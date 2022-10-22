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
        FAST_IO(".inp", ".out");
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

const int N = 3e5 + 5;

#define int long long

int n, m, x, tot, vis[N], a[N];
vector<int> ans, revans;
vector<pair<int, int>> adj[N];

void dfs(int u, int p, int ed){
    vis[u] = 1;
    for (auto vw : adj[u])
        if (!vis[vw.first])
            dfs(vw.first, u, vw.second);
    if (!p) return ;
    if (a[u] >= x) 
        a[p] += a[u] - x, ans.push_back(ed);
    else
        revans.push_back(ed);
}

void Hollwo_Pelw() {
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i], tot += a[i];
    if (tot < 1ll * (n - 1) * x) 
        return cout << "NO\n", (void) 0;
    for (int i = 1, u, v; i <= m; i++)
        cin >> u >> v, adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);
    dfs(1, 0, 0);
    cout << "YES\n";
    reverse(revans.begin(), revans.end());
    for (auto x : ans) cout << x << "\n";
    for (auto x : revans) cout << x << "\n";
}