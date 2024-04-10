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

const int N = 1e6 + 5;

int n, k, a[N], tin[N], tout[N], timer;
vector<int> adj[N];

#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int st[N << 2], lz[N << 2];

void apply(int id, int v){
    st[id] += v, lz[id] += v;
}

void push(int id) {
    apply(id << 1, lz[id]);
    apply(id << 1 | 1, lz[id]);
    lz[id] = 0;
}

void upd(int l, int r, int v, int id = 1, int tl = 1, int tr = n + 1) {
    if (l > r || l > tr || tl > r) return ;
    if (l <= tl && tr <= r) return apply(id, v);
    int tm = tl + tr >> 1; push(id);
    upd(l, r, v, left), upd(l, r, v, right);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

void dfs(int u){
    tin[u] = ++ timer;
    for (auto v : adj[u])
        dfs(v);
    tout[u] = timer;
}

void __pre_process() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++){
        while (!pq.empty() && pq.top().first < a[i]) 
            adj[i].push_back(pq.top().second), pq.pop();
        pq.emplace(a[i], i);
    }

    while (!pq.empty()) 
        adj[0].push_back(pq.top().second), pq.pop();
    
    dfs(0);
}

void Hollwo_Pelw() {
    __pre_process ();

    for (int i = 1; i <= n; i++){
        upd(tin[i], tout[i], +1);
        if (i >= k){
            cout << st[1] << " ";
            upd(tin[i - k + 1], tout[i - k + 1], -1);
        }
    }
}