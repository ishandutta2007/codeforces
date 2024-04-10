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
const int MAXN = 100010;
vi po, adj[MAXN], radj[MAXN], cadj[MAXN];
bool vis[MAXN];
void ses(int n){
    vis[n] = 1;
    for(auto x: adj[n])if(!vis[x])ses(x);
    po.pb(n);
}
vi cc[MAXN]; int sas[MAXN];
int r;
void sus(int n){
    vis[n] = 1;
    cc[r].pb(n); sas[n] = r;
    for(auto x: radj[n])if(!vis[x])sus(x);
}
int uf[MAXN], sz[MAXN];
int find(int a){
    return uf[a] == a?a:uf[a]=find(uf[a]);
}
int uni(int a, int b){
    a = find(a); b = find(b);
    if(a == b)return 0;
    if(sz[a] < sz[b])swap(a,b);
    sz[a]+=sz[b];
    uf[b] = a;
    return 1;
}

void solve(){
    int N,M;
    cin >> N >> M;
    iota(uf,uf+MAXN,0);
    int a,b;
    while(M--){
        cin >> a >> b;
        adj[--a].pb(--b);
        radj[b].pb(a);
    }
    FOR(i,N)if(!vis[i])ses(i);
    FOR(i,N)vis[i] = 0;
    reverse(all(po));
    int ans = 0;
    for(int i: po)if(!vis[i]){
        r = i;
        sus(i);
        //cout << i << endl;
        if(cc[i].size() > 1){ans+=cc[i].size(); uni(i,N+1);}
        for(auto x: cc[i]){
            uni(i,x);
        //    cout << x << " ";
        }
        //cout << endl;
    }
    for(auto x: po){
        for(auto k: adj[x])ans+=uni(x,k);
    }
    cout << ans << endl;
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