#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
#ifdef AIM
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
#ifdef AIM
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
//freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif

#ifdef AIM
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
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  precalc();
  while (t--) {
    solve(true);
  }
  cout.flush();

#ifdef AIM1
  while (true) {
    solve(false);
  }
#endif

#ifdef AIM
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

void precalc() {

}

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

struct Dsu {
  vector<int> dsu;
  Dsu(int n) {
    dsu.resize(n);
    iota(all(dsu), 0);
  }
  int find_set(int v) {
    if (dsu[v] == v) {
      return v;
    }
    return dsu[v] = find_set(dsu[v]);
  }
  void merge(int q, int w) {
    q = find_set(q);
    w = find_set(w);
    dsu[w] = q;
  }
};

struct Edge {
  int to, edge_id;
};

vector<vector<int>> loops;
vector<vector<Edge>> g;

void add_edge(int from, int to, int edge_id) {
  if (from == to) {
    loops[from].push_back(edge_id);
  } else {
    g[from].push_back({to, edge_id});
    g[to].push_back({from, edge_id});
  }
}

void solve(__attribute__((unused)) bool read) {
  int n;
  if (read) {
    cin >> n;
  } else {
    n = rand() % 1000 + 1;
  }
  vector<vector<int>> edges(n);
  const int L = 21;
  for (int i = 0; i < n; ++i) {
    edges[i].resize(2);
    for (int j = 0; j < 2; ++j) {
      if (read) {
        cin >> edges[i][j];
      } else {
        edges[i][j] = rand() % (1 << 20);
      }
    }
  }
  g.resize(1 << 20);
  loops.resize(1 << 20);
  for (int r = L - 1; r >= 0; --r) {
    Dsu dsu(1 << r);
    for (int i = 0; i < (1 << r); ++i) {
      g[i].clear();
      loops[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      int a = edges[i][0] % (1 << r), b = edges[i][1] % (1 << r);
      add_edge(a, b, i);
      dsu.merge(a, b);
    }
    bool f = true;
    int root_comp = -1;
    for (int i = 0; i < (1 << r); ++i) {
      if (g[i].size() % 2) {
        f = false;
        break;
      }
      if (!loops[i].empty() || !g[i].empty()) {
        int root = dsu.find_set(i);
        if (root_comp == -1) {
          root_comp = root;
        } else if (root_comp != root) {
          f = false;
          break;
        }
      }
    }
    if (!f) {
      assert(r > 0);
      continue;
    }

    assert(root_comp != -1);
    stack<int> st;
    st.push (root_comp);
    vector<int> res;
    vector<int> res_vs;
    vector<int> vs;
    vector<char> used_edge(n, false);
    while (!st.empty())
    {
      int v = st.top();
      //cout << "v: " << v << endl;
      bool found = false;
      while (!g[v].empty()) {
        auto e = g[v].back();
        g[v].pop_back();
        if (used_edge[e.edge_id]) {
          continue;
        }
        st.push(e.to);
        used_edge[e.edge_id] = true;
        found = true;
        break;
      }
      if (!found) {
        st.pop();
        res_vs.push_back(v);
        while (!loops[v].empty()) {
          res_vs.push_back(v);
          loops[v].pop_back();
        }
      }
    }
    cout << r << "\n";

    map<vector<int>, vector<int>> edges_by_key;
    for (int i = 0; i < edges.size(); ++i) {
      int a = edges[i][0] % (1 << r), b = edges[i][1] % (1 << r);
      edges_by_key[{a, b}].push_back(i);
    }
    /*for (int x : res_vs) {
      cout << x << " ";
    }
    cout << endl;*/
    for (int pos = 0; pos + 1 < res_vs.size(); ++pos) {
      int a = res_vs[pos], b = res_vs[(pos + 1) % res_vs.size()];
      auto it = edges_by_key.find({a, b});
      if (it != edges_by_key.end() && it->second.size() > 0) {
        int i = it->second.back();
        cout << 2 * i + 1 << " " << 2 * i + 2 << " ";
        it->second.pop_back();
      } else {
        it = edges_by_key.find({b, a});
        assert(it != edges_by_key.end() && it->second.size() > 0);
        int i = it->second.back();
        cout << 2 * i + 2 << " " << 2 * i + 1 << " ";
        it->second.pop_back();
      }
    }
    return;

  }

}