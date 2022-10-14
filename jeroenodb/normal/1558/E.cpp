#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e3+1, oo = 1e9;
vi adj[mxN];
bitset<mxN> need;
int n,a[mxN],b[mxN];
int par[mxN];
ll gp;
bool dfs(int at, ll p, bool good=false) {
    for(int to: adj[at]) if(to!=par[at]) {
        if(a[to]>=p) break;
        if(par[to]==-1) {
            par[to]=at;
            int extra = need[to]?b[to]:0;
            if(dfs(to,p+extra,good or need[to])) {
                if(need[to]) gp+=b[to],need[to]=false;
                return true;
            }
        } else {
            if(good or need[to]) {
                while(need[to]) {
                    gp+=b[to];
                    need[to]=false;
                    to = par[at];
                }
                return true;
            }
        }
    }
    return false;
}
bool good(ll p) {
    gp=p;
    need.reset();
    for(int i=1;i<n;++i) need[i]=true;

    while(need.any()) {
        fill(par,par+n,-1);
        par[0]=0;
        if(!dfs(0,gp)) {
            break;
        }
    }
    return need.none();
}
void solve() {
    int m; cin >> n >> m;
    for(int i=1;i<n;++i) cin >> a[i];
    for(int i=1;i<n;++i) cin >> b[i];
    for(int i=0;i<n;++i) {
        adj[i].clear();
    }
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;++i) sort(all(adj[i]),[&](int c, int d) {return a[c]<a[d];});
    int lo=1, hi=1e9+3;
    while(lo<hi) {
        int mid = (lo+hi)/2;
        if(good(mid)) hi=mid;
        else lo = mid+1;
    }
    cout << lo << '\n';

}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}