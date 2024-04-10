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
long n,x,y,i,ans=1,par[200005],N,E,visi[200005]={0},h=1e9+7,vv[200005]={0};
vl a[200006];
void dfs(long node)
{
    long i;
    visi[node]=1;
    N++;
    for(i=0;i<a[node].size();++i)
    {
        E++;
        if(!visi[a[node][i]])
        dfs(a[node][i]);
    }
}
long fp(long x)
{
    if(par[x]==x) return x;
    else return par[x]=fp(par[x]);
}
int main()
{
    io
    cin>>n;
    for(i=1;i<=2*n;++i)
    par[i]=i;
    for(i=0;i<n;++i)
    {
        cin>>x>>y;
        par[x]=fp(y);
        a[y].pb(x);
        if(x==y) vv[x]=1;
    }
    for(i=1;i<=2*n;++i)
    {
        par[i]=fp(i);
        N=0;
        E=0;
        if(!visi[par[i]])
        {
            dfs(par[i]);
            if(E>=N) ans=(ans*(!vv[par[i]]+1))%h;
            else ans=(ans*N)%h;
        }
    }
    cout<<ans;
    return 0;
}