#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
int N, M, K;
vector<vector<int>> paths;
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> Size;
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1); Size.resize(n + 1);
        for (int i = 0; i <= n; ++i) par[i] = i, rank[i] = 0, Size[i] = 1;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        return true;
    }

    ll size(int x){
        return Size[root(x)];
    }
};

typedef vector<vector<int>> UnWeightedGraph;

template< typename G >
struct DoublingLowestCommonAncestor {
  const int LOG;
  vector< int > dep;
  const G &g;
  vector< vector< int > > table;

  DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
    table.assign(LOG, vector< int >(g.size(), -1));
  }

  void dfs(int idx, int par, int d) {
    table[0][idx] = par;
    dep[idx] = d;
    for(auto &to : g[idx]) {
      if(to != par) dfs(to, idx, d + 1);
    }
  }

  void build() {
    dfs(0, -1, 0);
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = LOG - 1; i >= 0; i--) {
      if(((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--) {
      if(table[i][u] != table[i][v]) {
        u = table[i][u];
        v = table[i][v];
      }
    }
    return table[0][u];
  }
};


void solvetree() {
    UnionFind uni(2 * N);
    for(int i = N; i < 2 * N; i++) {
        uni.Size[i] = 0;
    }
    for(int i = 0; i < N; i++) {
        for(auto j : paths[i]) {
            uni.merge(i, j + N);
            uni.merge(j, i + N);
        }
    }
    int factor = 0;
    if(uni.size(0) < (K + 1) / 2) factor = N;
    vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(uni.issame(i, factor)) ans.push_back(i);
    }
    ans.resize((K + 1) / 2);
    cout << 1 << endl;
    for(auto v : ans) cout << v + 1 << " ";
    cout << endl;
}

vector<int> depth;
vector<i_i> rest;
vector<ll> p;
UnWeightedGraph g;
void dfs(int now, int from) {
    for(auto to : paths[now]) {
        if(to == from) continue;
        if(depth[to] == -1) {
            p[to] = now;
            depth[to] = depth[now] + 1;
            dfs(to, now);
        } else {
            rest.push_back({now, to});
        }
    }
}


int main() {
    cin >> N >> M >> K;
    g.resize(N);
    paths.resize(N);
    p.resize(N);
    depth.resize(N, -1);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    if(M == N - 1) {
        solvetree();
        return 0;
    }
    depth[0] = 0;
    p[0] = -1;
    dfs(0, -1);
    for(int i = 1; i < N; i++) {
        //cerr << p[i] << " ";
        g[i].push_back(p[i]);
        g[p[i]].push_back(i);
    }
    i_i circuit;
    int dist = 1e9;
    DoublingLowestCommonAncestor<UnWeightedGraph> LCA(g);
    LCA.build();
    for(auto e : rest) {
        ll lca = LCA.query(e.first, e.second);
        int nowdist = depth[e.first] + depth[e.second] - 2 * depth[lca];
        if(chmin(dist, nowdist)) circuit = e;
        //cerr << nowdist << " " << e.first << " " << e.second << " " << lca << " " << depth[e.first] << " " << depth[e.second] << endl;
    }
    ll c[2] = {circuit.first, circuit.second};
    vector<ll> a[2];
    for(int i = 0; i < 2; i++) {
        int now = c[i];
        while(now != -1) {
            a[i].push_back(now);
            now = p[now];
        }
    }
    while(true) {
        if(a[0].size() <= 1 or a[1].size() <= 1) break;
        int sz0 = a[0].size(); 
        int sz1 = a[1].size();
        if(a[0][sz0-2] != a[1][sz1-2]) break;
        a[0].pop_back();
        a[1].pop_back();
    }
    vector<ll> C;
    for(auto v : a[0]) {
        C.push_back(v);
    }
    a[1].pop_back();
    reverse(a[1].begin(), a[1].end());
    for(auto v : a[1]) {
        C.push_back(v);
    }
    /*
    for(auto v : C) {
        cerr << v << " ";
    }
    cerr << endl;
    */
    if(C.size() <= K) {
        cout << 2 << endl;
        cout << C.size() << endl;
        for(auto v : C) {
            cout << v + 1 << " ";
        }
        cout << endl;
        return 0;
    } else {
        vector<int> ans;
        for(int i = 0; i < C.size(); i += 2) {
            ans.push_back(C[i]);
        }
        cout << 1 << endl;
        for(int i = 0; i < (K + 1) / 2; i++) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}