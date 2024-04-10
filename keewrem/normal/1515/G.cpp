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
// gcd delle differenze degli archi entranti e valuori dei noti da cui vengono
const int MAXN = 200010;
ll v[MAXN]; ll f[MAXN];
vector<pll>  adj[MAXN];
vi radj[MAXN];
bool vis[MAXN];
vi po;
int r;
int cc[MAXN];
void od(int n){
    vis[n] = 1;
    for(auto x: adj[n])if(!vis[x.fi])od(x.fi);
    po.pb(n);
}
void kek(int n){
    cc[n] = r;
    for(auto x: radj[n])if(cc[x] == 0)kek(x);
}
void dfs(int n){
    vis[n] = 1;
    for(auto x: adj[n]){
        if(cc[n] != cc[x.fi])continue;
        if(f[x.fi])v[x.fi] = __gcd(v[x.fi],__gcd(v[n],abs(f[n]+x.se-f[x.fi])));
        f[x.fi] = f[n]+x.se;
        if(!vis[x.fi])dfs(x.fi);
    }
}
void solve(){
    int N,M;
    cin >> N >> M;
    ll a,b,l;
    while(M--){
        cin >> a >> b >> l;
        radj[b].pb(a);
        adj[a].pb({b,l});
    }

    for(int i = 1; i <= N; i++){
        if(!vis[i])od(i);
    }
    reverse(all(po));
    FOR(i,N+1)vis[i] = 0;
    for(auto x: po){
        if(cc[x])continue;
        r = x;
        kek(x);
    }
    FOR(j,50){
        FOR(i,N+1)vis[i] = 0;
        for(auto i: po)if(!vis[i])dfs(i);
    }
    /*FOR(i,N)cout << f[i+1] << " ";
    cout << endl;
    FOR(i,N)cout << v[i+1] << " ";
    cout << endl;
    */int q; cin >> q;
    while(q--){
        cin >> a >> b >> l;
        ll k = __gcd(l,v[a]);
        if((l-b)%k == 0)cout <<"YES\n";
        else cout << "NO\n";
    }
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