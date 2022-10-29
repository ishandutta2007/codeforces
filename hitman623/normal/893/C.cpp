#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
vl a[100005];
long mx,vv[100005],v[100005],ans;
void dfs(long node)
{
    long i;
    v[node]=1;
    mx=min(mx,vv[node]);
    for(i=0;i<a[node].size();++i)
    if(!v[a[node][i]])
    dfs(a[node][i]);
}
int main()
{
    io
    long n,m,x,y,i;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    cin>>vv[i];
    for(i=0;i<m;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for(i=1;i<=n;++i)
    if(!v[i])
    {
        mx=1e12;
        dfs(i);
        ans+=mx;
    }
    cout<<ans;
    return 0;
}