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

const int maxn = 1e6+10;
const ll mod = 1e9+7;
int n,m;
vi adj[maxn];
bool ise[maxn];
bool is_in(int i,int j)
{
    return (i>=0&&j>=0&&i<n&&j<m);
}

int cnt[maxn];
bool visited[maxn];
int graphno[maxn];
int picount[maxn];

void dfs1(int node,int& sm,int no)
{
    
    graphno[node] = no;
    visited[node] = 1;
    sm += cnt[node];
    for(int i:adj[node])
    {
        if(!visited[i])
        {
            dfs1(i,sm,no);
        }
    }
}
void dfs2()
{
    int sz = 0;
    for(int i = 0;i<n*m;i++)
        if(ise[i])
            if(!visited[i])
                {int sm = 0; dfs1(i,sm,sz);picount[sz++] = sm;}
}
int main()
{

    memset(visited,0,sizeof visited);
    memset(cnt,0,sizeof cnt);
    memset(ise,0,sizeof ise);
    sd(n);sd(m);
    int k;
    sd(k);
    string s;
    rep(i,0,n)
    {
        cin>>s;
        rep(j,0,m)
        if(s[j] =='.')
            ise[m*i+j] = 1;
    }
    rep(i,0,n)
    rep(j,0,m)
    {
        int x = 0;
        if(ise[i*m+j]){
        if(is_in(i-1,j)){
            if(!ise[(i-1)*m+j])
                x++;
            else
                adj[i*m+j].eb((i-1)*m+j);
        }
        if(is_in(i+1,j)){
            if(!ise[(i+1)*m+j])
                x++;
            else
                adj[i*m+j].eb((i+1)*m+j);
        }
        if(is_in(i,j-1)){
            if(!ise[i*m+j-1])
                x++;
            else
                adj[i*m+j].eb(i*m+j-1);
        }
        if(is_in(i,j+1)){
            if(!ise[(i)*m+j+1])
                x++;
            else
                adj[i*m+j].eb(i*m+j+1);
        }
            cnt[i*m+j] = x; 
        }
    }
    dfs2();
    while(k--)
    {
        int p,q;
        sd(p),sd(q);
        p--;q--;
        cout<<picount[graphno[p*m+q]]<<"\n";
    }
}