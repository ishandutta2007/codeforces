
#include <bits/stdc++.h>
#ifdef PINELY
#include <sys/resource.h>
#endif
using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef PINELY
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
#endif

#ifdef PINELY
  const rlim_t kStackSize = 256 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0) {
    if (rl.rlim_cur < kStackSize) {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0) {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif

  start = clock();
  int t = 1;
#ifndef PINELY
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  precalc();
  int test_num = 1;
  while (t--) {
    //cout << "Case #" << test_num++ << ": ";
    solve(true);
  }
  cout.flush();

#ifdef PINELY1
  while (true) {
    solve(false);
  }
#endif

#ifdef PINELY
  cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif
  return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
  if (!w)
    return 1 % mod;
  if (w & 1)
    return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template<typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void precalc() {
}

struct Edge {
  int from, to, cost;
  bool operator < (const Edge& ot) const {
    return cost < ot.cost;
  }
};

struct Vertex {
  int id;
  int cost;
};

struct Dsu {
  vector<int> dsu;
  vector<Vertex> vertices;
  Dsu(int n) {
    dsu.resize(n);
    iota(all(dsu), 0);
    vertices.resize(n);
    for (int i = 0; i < n; ++i) {
      vertices[i] = {i, -1};
    }
  }
  int find_set(int v) {
    if (dsu[v] == v) {
      return v;
    }
    return dsu[v] = find_set(dsu[v]);
  }
};

vector<vector<int>> g;
vector<Vertex> vertices;
const int L = 18;
vector<vector<int>> parent;
vector<int> tin, tout;
int TIMER = 0;

void dfs(int v, int p) {
  //cout << v << " " << p << endl;
  tin[v] = TIMER++;
  parent[0][v] = p;
  for (int i = 1; i < L; ++i) {
    parent[i][v] = parent[i - 1][parent[i - 1][v]];
  }
  for (int to : g[v]) {
    dfs(to, v);
  }
  tout[v] = TIMER++;
}

bool upper(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
  if (a == -1) {
    return b;
  }
  if (b == -1) {
    return a;
  }
  if (upper(a, b)) {
    return a;
  }
  for (int i = L - 1; i >= 0; --i) {
    if (!upper(parent[i][a], b)) {
      a = parent[i][a];
    }
  }
  return parent[0][a];
}

struct Node {
  int lca_all = -1;
  int lca_active = -1;
  int push_type = 0;
};

Node merge(const Node& l, const Node& r, int cached_lca_all = -1) {
  if (r.lca_all == -1) {
    return l;
  }
  if (l.lca_all == -1) {
    return r;
  }
  Node res;
  if (cached_lca_all == -1) {
    res.lca_all = lca(l.lca_all, r.lca_all);
  } else {
    res.lca_all = cached_lca_all;
  }
  res.lca_active = lca(l.lca_active, r.lca_active);
  return res;
}

struct SegTree {
  int shift;
  vector<Node> tree;

  SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, Node());
    for (int i = 0; i < n; ++i) {
      tree[i + shift] = {i, -1, 0};
    }
    for (int i = shift - 1; i >= 0; --i) {
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
      //cout << tree[i].lca_active << endl;
    }
  }

  void apply_push(Node& child, int push_type) {
    if (push_type == -1) {
      child.lca_active = -1;
    } else {
      child.lca_active = child.lca_all;
    }
    child.push_type = push_type;
  }

  void push(int v) {
    if (tree[v].push_type == 0) {
      return;
    }
    for (int h = 0; h < 2; ++h) {
      apply_push(tree[2 * v + h], tree[v].push_type);
    }
    tree[v].push_type = 0;
  }

  int rmq(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) {
      return -1;
    }
    if (l <= tl && tr <= r) {
      return tree[v].lca_active;
    }
    push(v);
    int tm = (tl + tr) / 2;
    return lca(rmq(2 * v, tl, tm, l, r), rmq(2 * v + 1, tm, tr, l, r));
  }

  int get_min(int l, int r) {
    return rmq(1, 0, shift, l, r);
  }

  void modify(int v, int tl, int tr, int l, int r, int push_type) {
    if (tr <= l || r <= tl) {
      return;
    }
    if (l <= tl && tr <= r) {
      apply_push(tree[v], push_type);
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    modify(2 * v, tl, tm, l, r, push_type);
    modify(2 * v + 1, tm, tr, l, r, push_type);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1], tree[v].lca_all);
  }

  void update(int l, int r, int push_type) {
    return modify(1, 0, shift, l, r, push_type);
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, Q;
  //read = false;
  if (read) {
    cin >> n >> Q;
  } else {
    n = Q = 300000;
  }
  vector<Edge> edges(n - 1);
  int id = 1;
  for (auto& e : edges) {
    if (read) {
      cin >> e.from >> e.to >> e.cost;
    } else {
      e.from = id;
      e.to = rand() % id;
      ++id;
    }
    --e.from; --e.to;
  }
  sort(all(edges));
  Dsu dsu(n);
  for (int i = 0; i < n; ++i) {
    vertices.push_back({i, -1});
  }
  g.resize(n);
  for (auto e : edges) {
    e.from = dsu.find_set(e.from);
    e.to = dsu.find_set(e.to);
    int new_id = vertices.size();
    vertices.push_back({new_id, e.cost});
    g.push_back({dsu.vertices[e.from].id, dsu.vertices[e.to].id});
    //cout << new_id << " " << e.cost << " " << g[new_id][0] << " " << g[new_id][1] << endl;
    dsu.dsu[e.from] = e.to;
    dsu.vertices[e.to] = vertices.back();
  }
  int root = (int)vertices.size() - 1;
  parent.assign(L, vector<int>(g.size(), root));
  tin.resize(g.size());
  tout.resize(g.size());
  dfs(root, root);

  int s = 0;

  SegTree tree(n);
  while (Q--) {
    int type;
    if (read) {
      cin >> type;
    } else {
      type = rand() % 3 + 1;
    }
    if (type <= 2) {
      int l, r;
      if (read) {
        cin >> l >> r;
      } else {
        do {
          l = rand() % n + 1;
          r = rand() % n + 1;
        } while (l >= r);
      }
      --l;
      tree.update(l, r, type == 1 ? 1 : -1);
    } else {
      int v;
      if (read) {
        cin >> v;
        --v;
      } else {
        v = rand() % n;
      }
      int cur_lca = tree.get_min(0, n);
      //cout << cur_lca << endl;
      if (cur_lca == -1) {
        cout << "-1\n";
        continue;
      }
      cur_lca = lca(cur_lca, v);
      if (cur_lca == v) {
        cout << "-1\n";
        continue;
      }
      if (read) {
        cout << vertices[cur_lca].cost << "\n";
      } else {
        s += vertices[cur_lca].cost;
      }
    }
  }

  if (!read) {
    cout << s << endl;
  }

}