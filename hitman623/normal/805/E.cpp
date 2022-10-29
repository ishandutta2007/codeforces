#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long n,m,i,j,x,y,k,c=1,col[300005]={0},v[300005]={0};
vector < long > s[300005],adj[300005];
long visi[300005]={0};
set < long > a;
set < long > ::iterator it;
void dfs(long node)
{
    visi[node]=1;
    long i=node,j;
    vector < long > b;
    for(j=0;j<s[node].size();++j)
    {
        if(col[s[i][j]]!=0)
        {
            if(a.find(col[s[i][j]])!=a.end())
            {
                a.erase(a.find(col[s[i][j]]));
                b.pb(col[s[i][j]]);
            }
            else col[s[i][j]]=0;
        }
    }
    k=1;
    it=a.begin();
    for(j=0;j<s[node].size();++j)
    if(col[s[i][j]]==0)
    {col[s[i][j]]=*it;
    it++;}
    for(j=0;j<b.size();++j)
    a.insert(b[j]);
    for(i=0;i<adj[node].size();++i)
    if(!visi[adj[node][i]])
    dfs(adj[node][i]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=m;++i)
    a.insert(i);
    for(i=1;i<=n;++i)
    {
        cin>>x;
        c=max(c,x);
        for(j=0;j<x;++j)
        {
            cin>>y;
            s[i].pb(y);
        }
    }
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);
    cout<<c<<endl;
    for(i=1;i<=m;++i)
    cout<<max(col[i],(long)1)<<" ";
    return 0;
}