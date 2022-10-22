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

const int N = 1e5 + 5, inf = (int) 2e9;

int n, root, a[N], dep[N];
int timer, euler[N], tin[N], tout[N];

vector<int> adj[N];

void dfs(int u, int p){
    tin[u] = ++timer;
    euler[timer] = u;
    for (auto v : adj[u]) 
        if (v != p ){
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    tout[u] = timer;
}

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm 
#define right id << 1 | 1, tm + 1, tr

vector<pair<int, int>> st[N << 2];

void merge(vector<pair<int, int>> & res, vector<pair<int, int>> & l, vector<pair<int, int>> & r){
    int pl = 0, pr = 0;
    while (pl < l.size() && pr < r.size()) {
        if (l[pl] > r[pr])
            res.push_back(r[pr ++]);
        else
            res.push_back(l[pl ++]);
    }
    while (pl < l.size())
        res.push_back(l[pl ++]);
    while (pr < r.size())
        res.push_back(r[pr ++]);
    for (int i = 1; i < res.size(); i++)
        if (res[i].second > res[i - 1].second)
            res[i].second = res[i - 1].second;
}

void build(int id = 1, int tl = 1, int tr = n){
    if (tl == tr) {
        st[id].emplace_back(dep[euler[tl]], a[euler[tl]]);
    } else {
        build(left), build(right);
        merge(st[id], st[id << 1], st[id << 1 | 1]);
    }
}

int binsearch(int id, int h){
    int tmp = lower_bound(st[id].begin(), st[id].end(), pair<int, int>(h + 1, -1)) - st[id].begin();
    return tmp ? st[id][tmp - 1].second : inf;
}

int query(int l, int r, int h, int id = 1, int tl = 1, int tr = n){
    if (l > r || l > tr || tl > r) return inf;
    if (l <= tl && tr <= r) return binsearch(id, h);
    return min(query(l, r, h, left), query(l, r, h, right));
}

#undef tm
#undef left
#undef right

void Hollwo_Pelw() {
    cin >> n >> root;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i < n; i++)
        cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    dfs(root, root);
    build(1, 1, n);
    int q, ans = 0; cin >> q;
    while (q --) {
        int u, k;
        cin >> u >> k;
        u = (u + ans) % n + 1;
        k = (k + ans) % n;
        cout << (ans = query(tin[u], tout[u], dep[u] + k)) << "\n"; 
    }
}