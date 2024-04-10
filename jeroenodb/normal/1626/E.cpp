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
const int mxN = 3.1e5+1, oo = 1e9;
bitset<mxN> good,black;
vi adj[mxN];
int cnt[mxN];
void dfs1(int at, int from) {
    good[at] = black[at];
    cnt[at]=black[at];

    for(auto to : adj[at]) if(to!=from) {
        dfs1(to,at);
        if(cnt[to]>=2 and good[to]) good[at]=true;
        if(black[to]) good[at]=true;
        cnt[at]+=cnt[to];
    }
}
int n,btotal;
void dfs2(int at, int from) {
    if(from) {
        if(btotal-cnt[at]>=2 and good[from]) good[at]=true;
        if(black[from]) good[at]=true;
    }
    for(auto to : adj[at]) if(to!=from) {
        dfs2(to,at);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;++i) {
        int c; cin >> c;
        black[i]=c;
    }
    btotal = black.count();
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;++i) cout << good[i] << ' ';
}