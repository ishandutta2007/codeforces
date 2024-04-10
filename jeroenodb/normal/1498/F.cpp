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
const int mxN = 1e5+1, oo = 1e9;
int k, SZ;
struct DP {
    array<int,40> dp = {};
    int lazy=0;
    int& operator[](int i) {
        int res = (i-lazy)%SZ;
        if(res<0) res+=SZ;
        return dp[res];
    }
    void hang() {lazy++;}
    void unhang() {lazy--;}
    DP() {}
    DP(int a) {
        dp[0]=a;
    }
    void merge(DP& o) { // merging is its own inverse
        for(int i=0;i<SZ;++i) {
            operator[](i) ^= o[i];
        }
    }
    friend int get(DP& d) {
        int res=0;
        for(int i=k;i<SZ;++i) {
            res^=d[i];
        }
        return res;
    }
};
vi adj[mxN];
DP dp[mxN];
int a[mxN];
void dfs1(int at, int from) {
    dp[at] = DP(a[at]);
    for(int to: adj[at]) if(to!=from) {
        dfs1(to,at);
        dp[to].hang();
        dp[at].merge(dp[to]);
    }
}
int ans[mxN];
void dfs2(int at, int from) {
    if(from!=-1) {
        auto cur = dp[from];
        cur.merge(dp[at]);
        dp[at].unhang();
        cur.hang();
        dp[at].merge(cur);
    }
    ans[at] = get(dp[at]);
    for(int to: adj[at]) if(to!=from) {
        dfs2(to,at);
    }
}
int main() {
    int n; cin >> n >> k;
    SZ=2*k;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;++i) cin >> a[i];
    dfs1(0,-1);
    dfs2(0,-1);
    for(int i=0;i<n;++i) cout << (!!ans[i]) << ' ';

}