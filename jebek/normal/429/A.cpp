#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=101000;
vector<int>G[MAXN],ans;
int n,t[2],a[MAXN],b[MAXN],h[MAXN];
bool mark[MAXN],mark2[MAXN];

void dfs(int v)
{
    mark[v]=true;
    if((t[h[v]]+a[v])%2!=b[v])
    {
        t[h[v]]++;
        ans.push_back(v);
        mark2[v]=true;
    }
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            h[u]=1-h[v];
            dfs(u);
        }
    }
    if(mark2[v])
        t[h[v]]--;
}

int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    dfs(1);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
}