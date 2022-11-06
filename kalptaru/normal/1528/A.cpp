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
// const ll mod=998244353;
const ll mod=1e9+7;
ll INF=1e18;
const ll N=100005;
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
int l[N],r[N];
pair<ll,ll> dfs(int i,int j,vector<int> tree[])
{
    pair<ll,ll> a=mp(0,0),b;
    FOR(k,0,tree[i].size())
    {
        if(tree[i][k]!=j)
        {
            b=dfs(tree[i][k],i,tree);
            a.ff+=max(abs(l[i]-l[tree[i][k]])+b.ff,abs(l[i]-r[tree[i][k]])+b.ss);
            a.ss+=max(abs(r[i]-l[tree[i][k]])+b.ff,abs(r[i]-r[tree[i][k]])+b.ss);
        }
    }
    return a;
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
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        FOR(i,0,n)
        {
            cin>>l[i]>>r[i];
        } 
        vector<int> tree[n];
        cintree(tree,n);
        pair<ll,ll> ans=dfs(0,-1,tree);
        cout<<max(ans.ff,ans.ss)<<'\n';
    }

    return 0;
}