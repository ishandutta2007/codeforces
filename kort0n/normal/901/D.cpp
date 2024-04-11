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

ll c[100500];
ll ans[100500];
map<l_l, ll> mp;
UnWeightedGraph g;
ll N, M;
int p[100500];

bool AllZero() {
    for(int i = 0; i < N; i++) {
        if(c[i] != 0) return false;
    }
    return true;
}

void print() {
    cout << "YES" << endl;
    for(int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }
}

int f(int a, int b) {
    if(a > b) swap(a, b);
    return mp[{a, b}];
}
void dfs(int now, int from) {
    for(auto to : g[now]) {
        if(to == from) continue;
        p[to] = now;
        dfs(to, now);
        int e = f(now, to);
        ans[e] = c[to];
        c[now] -= c[to];
        c[to] = 0;
    }
}

void h(int x, ll factor) {
    if(p[x] == -1) return;
    int e = f(p[x], x);
    ans[e] += factor;
    h(p[x], -factor);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> c[i];
    UnionFind uni(N);
    g.resize(N);
    vector<l_l> rest;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a > b) swap(a, b);
        mp[{a, b}] = i;
        if(uni.merge(a, b)) {
            g[a].push_back(b);
            g[b].push_back(a);
        } else {
            rest.push_back({a, b});
        }
    }
    DoublingLowestCommonAncestor<UnWeightedGraph> LCA(g);
    LCA.build();
    p[0] = -1;
    dfs(0, -1);
    if(AllZero()) {
        print();
        return 0;
    }
    //print();
    for(auto e : rest) {
        if(LCA.dep[e.first] % 2 != LCA.dep[e.second] % 2) continue;
        ll factor = c[0] / 2;
        if(LCA.dep[e.first] % 2 == 1) factor *= -1;
        ans[f(e.first, e.second)] += factor;
        h(e.first, -factor);
        h(e.second, -factor);
        print();
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}