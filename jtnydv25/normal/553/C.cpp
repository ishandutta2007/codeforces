#include <bits/stdc++.h>
using namespace std;

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
vi love[maxn];
vii hate;
bool vis[maxn];
vi con[maxn];
int root[maxn];
void dfs1(int s, int k)
{
    root[s] = k;
    vis[s] = 1;
    for(int i:love[s])
        if(!vis[i])
            dfs1(i,k);
}
int sz = 0;
void dfs(int n)
{
    sz = 0;
    for(int i = 1;i<=n;i++)
        if(!vis[i]){ 
            sz++;
            dfs1(i,sz);
        }
}
int color[maxn];
int main()
{
    int n,m,u,v,c;
    sd(n),sd(m);
    rep(i,0,m)
    {
        sd(u),sd(v),sd(c);
        if(c==1){
            love[u].eb(v);
            love[v].eb(u);
        }
        else
        {
            hate.eb(mp(u,v));
        }
    }
    dfs(n);
    for(auto edge: hate)
    {
        int u = edge.F,v = edge.S;
        int x = root[u], y = root[v];
        if(x==y)
        {
            cout<<0;
            return 0;
        }
        con[x].eb(y);
        con[y].eb(x);
    }
    memset(vis,0,sizeof vis);
    ll ans = inv(2,mod);
    for(int i = 1;i<=sz;i++)
    {
        if(!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            color[i] = 1;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(int v:con[u])
                {
                    if(!vis[v])
                    {
                        q.push(v);
                        vis[v] = 1;
                        color[v] = 3-color[u];
                    }
                    else
                    {
                        if(color[u]+color[v] != 3)
                        {
                            cout<<0;
                            return 0;
                        }
                    }
                }
            }
            ans = (ans*2)%mod;
        }
    }
    cout<<ans;
}