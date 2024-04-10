#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=500;
int n,a[MAXN],ans[MAXN];
bool mark[MAXN];
vector<int>vec,vec1,G[MAXN];

bool cmp(int i,int j)
{
    return a[i]<a[j];
}

void dfs(int v)
{
    mark[v]=true;
    vec.push_back(v);
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
            dfs(u);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            char x;
            cin>>x;
            if(x=='1')
                G[i].push_back(j);
        }
    for(int i=1;i<=n;i++)
    {
        if(!mark[i]){
            vec.clear();
            dfs(i);
            sort(vec.begin(),vec.end());
            vec1=vec;
            sort(vec1.begin(),vec1.end(),cmp);
            for(int i=0;i<vec.size();i++)
            {
                ans[vec[i]]=a[vec1[i]];
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}