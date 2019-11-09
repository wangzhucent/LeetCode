class Solution {
    typedef vector<unordered_set<int>> tree;
    int height(tree &Mytree, int x)
    {
        if (x>=Mytree.size() || Mytree[x].size()==0)
            return 0;
        priority_queue<int> que;
        
        for (auto temp: Mytree[x])
        {
            Mytree[temp].erase(x);
            int temp_n=height(Mytree,temp);
            que.push(temp_n+1);
        }
        
        int res=(que.size()>0?que.top():0);
        int sum=0;
        for (int i=0;i<2;i++)
        {
            if(que.size()>0)
            {
                sum+=que.top();
                que.pop();
            }
        }
        radius = max(sum, radius);
        return res;
    }
    int radius=0;
public:
    int treeDiameter(vector<vector<int>>& edges) {
        tree Mytree(edges.size()+1);
        for (auto temp:edges)
        {
            Mytree[temp[0]].insert(temp[1]);
            Mytree[temp[1]].insert(temp[0]);
        }
        int res = height(Mytree,edges[0][0]);
        
        // cout<<radius<<endl;
        return radius;
    }
    
    
};
