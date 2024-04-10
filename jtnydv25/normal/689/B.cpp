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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define what_is(x) cerr << #x << " is " << x << endl;
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))

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

const int maxn = 2e5+10;

vi edges[maxn];
bool visited[maxn];
int dist[maxn];
void bfs(int s)
{
    dist[s] = 0;
    visited[s] = 1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:edges[u])
            if(!visited[v])
            {
                visited[v] = 1;
                dist[v] = dist[u]+1;
                q.push(v);
            }
    }
}
int main()
{
    int n;
    cin>>n;
    int x;
    for(int i = 1;i<n;i++)
    {
        edges[i].eb(i+1);
        edges[i+1].eb(i);
        sd(x);
        if(x != i+1 && x!= i-1)
            edges[i].eb(x);
    }
    memset(visited,0,sizeof visited);
    bfs(1);
    for(int i = 1;i<=n;i++)
        printf("%d ",dist[i]);
}