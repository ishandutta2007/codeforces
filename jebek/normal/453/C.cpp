#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=200000;
bool mark[MAXN];
int par[MAXN],a[MAXN],n,m,root;
vector<int>G[MAXN],ans;

void dfs(int v)
{
    mark[v]=true;
    ans.push_back(v);
    a[v]=1-a[v];
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            par[u]=v;
            dfs(u);
            ans.push_back(v);
            a[v]=1-a[v];
        }
    }
    if(a[v]!=0)
    {
        if(v==root)
            ans.pop_back();
        else
        {
            ans.push_back(par[v]);
            ans.push_back(v);
            a[par[v]]=1-a[par[v]];
            a[v]=1-a[v];
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
            root=i;
    }
    if(root==0)
    {
        cout<<0<<endl;
        return 0;
    }
    dfs(root);
    for(int i=1;i<=n;i++)
        if(a[i] && !mark[i])
        {
            cout<<-1<<endl;
            return 0;
        }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}