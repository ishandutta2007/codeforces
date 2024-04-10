/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
        #ifdef hollwo_pelw_local
            freopen(fileerr.c_str(), "w", stderr);
        #endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out", "error.err");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    #ifdef hollwo_pelw_local
        auto end = chrono::steady_clock::now();
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

const int N = 2e5 + 5, mod = 998244353, inf = 2e9, L = 20, K = 2;

int n, m;
vector<int> adj[N][2];

struct node {
    int u, d, p, t;
} dist[N][K][L + 1];

bool operator < (const node &x, const node &y) {
    if (x.p <= L && y.p <= L) 
        return (1 << x.p) + x.d < (1 << y.p) + y.d;
    return x.p == y.p ? x.d < y.d : x.p < y.p;
}

bool operator > (const node &x, const node &y) {
    return y < x;
}

inline int calc(node x) {
    int ans = 1;
    for (int _ = 0; _ < x.p; _++)
        ans = 2ll * ans % mod;
    return (ans + x.d - 1) % mod;
}

priority_queue<node, vector<node>, greater<node>> pq;

void Hollwo_Pelw() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
        cin >> u >> v, adj[u][0].push_back(v), adj[v][1].push_back(u);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < K; j++)
            for (int k = 0; k <= L; k++)
                dist[i][j][k] = {i, inf, inf, j};

    pq.push({1, 0, 0, 0});
    while (!pq.empty()) {
        node cur = pq.top(); pq.pop();
        if (cur.u == n) return cout << calc(cur), (void) 0;
        
        if (!(dist[cur.u][cur.t][min(cur.p, L)] > cur)) continue ;

        // cout << cur.u << ' ' << cur.d << ' ' << cur.p << "\n";

        dist[cur.u][cur.t][min(cur.p, L)] = cur;

        for (int i = 0; i < 2; i++)
            for (int v : adj[cur.u][i]) {
                node nxt = {v, cur.d + 1, cur.p + (cur.t != i), i};
                if (dist[nxt.u][nxt.t][min(nxt.p, L)] > nxt) pq.push(nxt);
            }
    }
}