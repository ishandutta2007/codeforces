#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp() pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
#define cintree(t,n) int u,v; FOR(i,1,n){cin>>u>>v;u--;v--;t[v].pb(u);t[u].pb(v);}
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
const ll mod=998244353;
// const ll mod=1e9+7;
ll INF=1e18;
const ll N=300005;
ll po(ll a,ll b)
{
    ll re=1;  
    while(b)
    {
        if(b%2==1)
        {
            re=(re*a);
            re%=mod;
        }
        a=(a*a);
        a%=mod;
        b>>=1;
    }
    return re;
}
int ans,c,o;
int t[8*N];
int le[N],re[N];
void up(int v,int tl,int tr,int l,int r,int a)
{
    if(l>r)
    {
        return;
    }
    if(tl==l && tr==r)
    {
        t[v]=a;
        return;
    }
    int tm=(tl+tr)/2;
    if(t[v]!=-1)
    {
        t[2*v]=t[v];
        t[2*v+1]=t[v];
        t[v]=-1;
    }
    up(2*v,tl,tm,l,min(r,tm),a);
    up(2*v+1,tm+1,tr,max(l,tm+1),r,a);
}
int get(int v,int tl,int tr,int p)
{
    if(t[v]!=-1)
    {
        return t[v];
    }
    int tm=(tl+tr)/2;
    if(p>tm)
    {
        return get(2*v+1,tm+1,tr,p);
    }
    return get(2*v,tl,tm,p);
}
void lere(int i,int j,vector<int> tree[])
{
    le[i]=o;
    o++;
    FOR(k,0,tree[i].size())
    {
        if(tree[i][k]!=j)
        {
            lere(tree[i][k],i,tree);
        }
    }
    re[i]=o;
    o++;
}
void dfs(int i,int j,vector<int> tree[],int n)
{
    int p=get(1,0,n,le[i]);
    if(p!=-2)
    {
        up(1,0,n,le[p],re[p],-2);
    }
    else
    {
        c++;
    }
    up(1,0,n,le[i],re[i],i);
    ans=max(ans,c);
    FOR(k,0,tree[i].size())
    {
        if(tree[i][k]!=j)
        {
            dfs(tree[i][k],i,tree,n);
        }
    }
    up(1,0,n,le[i],re[i],-2);
    if(p!=-2)
    {
        up(1,0,n,le[p],re[p],p);
    }
    else
    {
        c--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    ll test=1;
    // int gt=0;
    memset(t,-1,sizeof(t));
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        vector<int> t1[n],t2[n];
        FOR(i,1,n)
        {
            cin>>o;
            t1[o-1].pb(i);
        }
        FOR(i,1,n)
        {
            cin>>o;
            t2[o-1].pb(i);
        }
        o=0;
        lere(0,-1,t2);
        ans=0;
        c=0;
        up(1,0,2*n,0,2*n,-2);
        dfs(0,-1,t1,2*n);
        cout<<ans<<'\n';

    }
    return 0;
}