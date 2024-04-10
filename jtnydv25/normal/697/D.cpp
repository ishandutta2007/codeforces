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

const int maxn = 1e5+10;
const ll mod = 1e9+7;
vi adj[maxn];
int subtree[maxn];
vi children[maxn];
int parent[maxn];
bool vis[maxn];
int dfs1(int node)
{

    int ret = 1;
    for(int i:children[node])
    {
        ret += dfs1(i);
    }
    subtree[node] = ret;
    return ret;
}
ld expected[maxn];
void dfs2(int node)
{
    int x = subtree[node];
    for(int i:children[node])
    {
        expected[i] = expected[node]+(x-1-subtree[i])/2.+1;
        dfs2(i);
    }
}
int main()
{

    memset(subtree,0,sizeof subtree);
    int n;
    sd(n);
    rep(i,2,n+1)
    {
        int x;
        sd(x);
        children[x].eb(i);
        parent[i] = x;
    }
    expected[1] = 1.0;
    dfs1(1);
    dfs2(1);
    cout<<setprecision(10)<<fixed;
    rep(i,1,n+1)
    cout<<expected[i]<<" ";
}