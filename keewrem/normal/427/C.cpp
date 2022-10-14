#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) int((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD =   1000000007;//   998244353;
const int MAXN = 100100;
vi radj[MAXN],adj[MAXN],cc[MAXN];
vi po;
bool vis[MAXN];
int r;
void dfs(int n){
    vis[n] = 1;
    for(auto x: adj[n])if(!vis[x])dfs(x);
    po.pb(n);
}
void dd(int n){
    vis[n] = 1;
    cc[r].pb(n);
    for(auto x: radj[n]){
        if(!vis[x])dd(x);
    }
}
void solve(){
    int N,M,a,b; cin >> N;
    vll c(N); for(ll &i: c)cin >> i;
    ll ans = 0, w = 1;
    cin >> M;
    while(M--){
        cin >> a >> b;
        adj[--a].pb(--b);
        radj[b].pb(a);
    }
    FOR(i,N)if(!vis[i])dfs(i);
    FOR(i,N)vis[i] = 0;
    reverse(all(po));
    for(auto i: po)if(!vis[i]){
        r = i;
        dd(i);
        ll m = 1e9, q = 0;
        for(int x: cc[i])m = min(c[x],m);
        for(int x: cc[i])if(c[x] == m)q++;
        ans += m;
        w = (w*q)%MOD;
    }
    cout << ans << " " << w << endl;
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}