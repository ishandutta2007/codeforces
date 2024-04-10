#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long n,k,v[200005]={0},val[200005]={0},x,y,i,ans=0,root=-1,j,p[200005]={0},f,s;
vl a[200005];
void dfs(long node,long par)
{
    long i;
    p[node]=par;
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    {
        dfs(a[node][i],node);
        val[node]+=val[a[node][i]];
    }
    val[node]+=v[node];
}
void dfs1(long node,long par,long dist)
{
    long i;
    if(v[node]) ans+=dist;
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    dfs1(a[node][i],node,dist+1);
}
int main()
{
    io
    cin>>n>>k;
    for(i=0;i<2*k;++i)
    {
        cin>>x;
        v[x]=1;
    }
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,-1);
    for(i=1;i<=n;++i)
    {
        f=1;
        s=0;
        for(j=0;j<a[i].size();++j)
        if(a[i][j]!=p[i] && val[a[i][j]]>k)
        {f=0;break;}
        else if(a[i][j]!=p[i]) s+=val[a[i][j]];
        if(s<k) f=0;
        if(f) break;
    }
    root=i;
    dfs1(root,-1,0);
    cout<<ans;
    return 0;
}