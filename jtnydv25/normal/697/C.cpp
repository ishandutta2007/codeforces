#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define what_is(x) cerr << #x << " is " << x << endl;
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

void gett()
{
    cerr<< (clock())/(double)cps<<endl;
}

ll powr(ll a, ll b, ll mod)
{
    ll x = 1%mod;
    a %= mod;
    while(b)
    {
        if(b&1)
            x = (x*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return x;
}
ll inv(ll a, ll mod)
{
    return powr(a,mod-2,mod);
}

const int maxn = 1e6+10;
const ll mod = 1e9+7;
map<ll,ll> cost;
ll add(ll u, ll w)
{
    if(cost.find(u)!=cost.end())
        cost[u]+=w;
    else
        cost[u] = w;
}
int main()
{
    int q;
    cin>>q;
    ll u,v,w;
    int x;
    while(q--)
    {
        cin>>x>>v>>u;
        set<ll> ans1,ans2;
        set<ll> common;
        ll u1=u,v1=v;
        while(u1)
        {
            ans1.insert(u1);
            u1>>=1;
        }
        while(v1)
        {
            ans2.insert(v1);
            v1>>=1;
        }
        ll ans = 1;
        for(ll x:ans1)
        {
            if(ans2.find(x)!=ans2.end())
                ans = max(ans,x);
                
        }
        if(x==1)
        {
            cin>>w;
            while(u != ans)
            {
                add(u,w);
                u>>=1;
            }
            while(v != ans)
            {
                add(v,w);
                v>>=1;
            }
        }
        else
        {
            ll ret = 0;
            while(u != ans){
                ret += cost[u];
                u>>=1;
            }
            while(v != ans)
            {
                ret += cost[v];
                v>>=1;
            }
            cout<<ret<<endl;
        }
    }
}