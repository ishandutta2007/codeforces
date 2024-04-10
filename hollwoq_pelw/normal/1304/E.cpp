/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 1e6 + 6 , MAXM = 2e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
//#define int long long

// RMQ + LCA (SPASE TABLE)

template<class T>
struct RMQ {
    vector<vector<T>> spt;
    vector<int> lg;
//    RMQ(const vector<T>& arr){
//        int N = sz(arr), tmp = 1, K = 1;
//        while (tmp < N) tmp *= 2, ++K;
//        lg.assign(N, 0);
//        spt.assign(K, arr);
//        for (int i = 2; i < N; i++)
//            lg[i] = lg[i/2] + 1;
//
//        for (int i = 1; i < K; i++){
//            for (int j = 0; j < N; j++){
//                spt[i][j] = min(spt[i-1][j], spt[i-1][min(N - 1, j + (1 << (i - 1)))]);
//            }
//        }
//    }
    void init(const vector<T>& arr){
        int N = sz(arr), tmp = 1, K = 1;
        while (tmp < N) tmp *= 2, ++K;
        lg.assign(N, 0);
        spt.assign(K, arr);
        for (int i = 2; i < N; i++)
            lg[i] = lg[i/2] + 1;

        for (int i = 1; i < K; i++){
            for (int j = 0; j < N; j++){
                spt[i][j] = min(spt[i-1][j], spt[i-1][min(N - 1, j + (1 << (i - 1)))]);
            }
        }
    }

    T query(int l, int r){
        int d = lg[r - l];
        return min(spt[d][l], spt[d][r - (1 << d)]);
    }
};

struct LCA{
    vector<int> st;
    vector<int> dep;
    vector<pii> arr;
    int N; RMQ<pii> rmq;
    LCA(vector<vector<int>> &adj, int r = 0){
        N = adj.size();
        st.resize(N);
        dep.resize(N);
        arr.reserve(N*2);
        dfs(adj, r, 0);
        rmq.init(arr);
        //RMQ<pii> rmq(arr);
    }

    void dfs(vector<vector<int>> &adj, int u, int p, int h = 0){
        st[u] = arr.size();
        dep[u] = h;
        arr.eb(h, u);
        for (auto v : adj[u]) if (v != p){
            dfs(adj, v, u, h + 1);
            arr.eb(h, u);
        }
    }

	int query(int a, int b) {
		if (a == b) return a;
		a = st[a], b = st[b];
		return rmq.query(min(a, b), max(a, b)).S;
	}
	int dist(int a, int b) {
		int lca = query(a, b);
		return dep[a] + dep[b] - 2 * dep[lca];
	}
};

void Solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v; u--; v--;
        adj[u].eb(v); adj[v].eb(u);
    }
    LCA lca(adj);
    int q, x, y, a, b, k;
    cin >> q; while(q--){
        cin >> x >> y >> a >> b >> k;
        x --; y --; a --; b --;
        int d1 = lca.dist(a, b);
        int d2 = lca.dist(a, x) + lca.dist(b, y) + 1;
        int d3 = lca.dist(a, y) + lca.dist(b, x) + 1;

        if ((d1 <= k && (k - d1) % 2 == 0) ||
            (d2 <= k && (k - d2) % 2 == 0) ||
            (d3 <= k && (k - d3) % 2 == 0)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    //cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.
*/