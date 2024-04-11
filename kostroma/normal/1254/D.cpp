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

#define int li
//const li mod = 1000000007;
const li mod = 998244353;
//using ull = unsigned long long;

vector<vector<int>> g;
vector<int> order;
vector<int> parent;
vector<int> cnt;

void dfs(int v, int p) {
  parent[v] = p;
  cnt[v] = 1;
  order.push_back(v);
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    dfs(to, v);
    cnt[v] += cnt[to];
  }
}

struct Query {
  int type, v;
  int d;
};

struct SqrtParent {
  int far_parent;
  int pred_parent;
};

void add(int& cur, int val) {
  cur = (cur + val) % mod;
}

void simple_add(int& cur, int val) {
  cur += val;
  if (cur >= mod) {
    cur -= mod;
  }
}

int my_rand() {
#ifdef AIM
  return rand();
#else
  return (rand() << 16) | rand();
#endif
}

void solve(__attribute__((unused)) bool read) {
  int n, Q;
  //read = false;
  g.clear();
  order.clear();
  if (read) {
    cin >> n >> Q;
  } else {
    n = my_rand() % 1000 + 1;
    Q = my_rand() % 1000 + 1;
    n = 150000;
    Q = 150000;
  }
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
      --a;
      --b;
    } else {
      a = i;
      b = my_rand() % i;
      b = i - 1;
    }
    g[a].push_back(b);
    g[b].push_back(a);
  }
  parent.assign(n, -1);
  cnt.assign(n, 0);
  dfs(0, -1);
  vector<Query> qs(Q);
  for (int i = 0; i < Q; ++i) {
    if (read) {
      cin >> qs[i].type >> qs[i].v;
      --qs[i].v;
    } else {
      qs[i].type = 1 + my_rand() % 2;
      qs[i].v = my_rand() % n;
    }
    if (qs[i].type == 1) {
      if (read) {
        cin >> qs[i].d;
      } else {
        qs[i].d = my_rand() % (int)1e7;
      }
    }
  }
  vector<int> pos_in_order(n);
  for (int i = 0; i < order.size(); ++i) {
    pos_in_order[order[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    auto it = find(all(g[i]), parent[i]);
    if (it != g[i].end()) {
      g[i].erase(it);
    }
  }

  int block_size = max(1LL, (int)sqrt(max(n, Q)) * 2);
  vector<int> vs;
  int TIMER = 0;
  vector<int> used(n);
  vector<SqrtParent> sqrt_parents(n, {-1, -1});
  vector<int> sum_inner_queries(n, 0);
  vector<int> pushed_queries(n, 0);
  int global_add = 0;
  vector<int> add_by_vertex(n, 0);
  int rev_n = binpow(n, mod - 2, mod);

  vector<int> mults(n, 0);
  for (int i = 0; i < n; ++i) {
    if (parent[i] != -1) {
      mults[i] = (n - cnt[parent[i]] - cnt[i]) * rev_n % mod;
      if (mults[i] < 0) {
        mults[i] += mod;
      }
    }
  }

  for (int w = 0; w < Q; w += block_size) {
    ++TIMER;
    int border = min(w + block_size, Q);
    vs.clear();
    vs.push_back(0);
    for (int i = w; i < border; ++i) {
      vs.push_back(qs[i].v);
    }
    sort(all(vs), [&](int q, int w) {
      return pos_in_order[q] < pos_in_order[w];
    });
    vs.erase(unique(all(vs)), vs.end());
    for (int v : vs) {
      used[v] = TIMER;
    }
    for (int v : order) {
      int far_parent = sqrt_parents[v].far_parent;
      int pred_parent = sqrt_parents[v].pred_parent;
      if (used[v] == TIMER) {
        far_parent = v;
        pred_parent = v;
      }
      for (int to : g[v]) {
        sqrt_parents[to] = {far_parent, (far_parent == v) ? to : pred_parent};
      }
    }
    for (int i = w; i < border; ++i) {
      int v = qs[i].v;
      if (qs[i].type == 1) {
        int d = qs[i].d;
        add(global_add, cnt[v] * d % mod * rev_n);
        add(add_by_vertex[v], (n - cnt[v]) * d % mod * rev_n);
        add(sum_inner_queries[v], d);
      } else {
        int cur_res = (global_add + add_by_vertex[v]) % mod;
        int pred = v;
        while (pred != 0) {
          int par = sqrt_parents[pred].far_parent;
          int pred_par = sqrt_parents[pred].pred_parent;
          add(cur_res, mults[pred_par] * sum_inner_queries[par]);
          pred = par;
        }
        if (read) {
          cur_res %= mod;
          if (cur_res < 0) {
            cur_res += mod;
          }
          cout << cur_res << "\n";
        }
      }
    }

    for (int v : vs) {
      for (int to : g[v]) {
        add(pushed_queries[to], mults[to] * sum_inner_queries[v]);
      }
      sum_inner_queries[v] = 0;
    }
    for (int v : order) {
      simple_add(add_by_vertex[v], pushed_queries[v]);
      for (int to : g[v]) {
        simple_add(pushed_queries[to], pushed_queries[v]);
      }
    }
    pushed_queries.assign(n, 0);
  }

}