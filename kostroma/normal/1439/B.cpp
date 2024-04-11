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
  cin >> t;
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


void solve(__attribute__((unused)) bool read) {
  int n, m, k;
  //read = false;
  vector<pair<int, int>> all_edges;
  if (read) {
    cin >> n >> m >> k;
  } else {
    k = 100;
    for (int c = 0; c < 4; ++c) {
      for (int i = 0; i < k - 2; ++i) {
        for (int j = 0; j < k - 2; ++j) {
          all_edges.emplace_back(c * (k - 2) + i, c * (k - 2) + j);
        }
      }
    }
    for (int i = 0; i < k - 2; ++i) {
      for (int a = 0; a < 4; ++a) {
        for (int b = a + 1; b < 4; ++b) {
          all_edges.emplace_back(a * (k - 2) + i, b * (k - 2) + i);
        }
      }
    }
    int v = 4 * (k - 2);
    for (; all_edges.size() + (k - 1) <= 100000; ++v) {
      for (int i = 0; i < k - 1; ++i) {
        all_edges.emplace_back(i, v);
      }
    }
    n = v;
    m = all_edges.size();
    cout << n << " " << m << " " << k << endl;
  }
  vector<int> deg(n, 0);
  vector<vector<int>> g(n);
  if (read) {
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
  } else {
    for (auto item : all_edges) {
      g[item.first].push_back(item.second);
      g[item.second].push_back(item.first);
    }
  }
  set<pair<int, int>> degs;
  for (int i = 0; i < n; ++i) {
    deg[i] = g[i].size();
    degs.insert({deg[i], i});
    sort(all(g[i]));
  }
  vector<char> used(n, false);
  vector<int> vec;
  li max_edges = k * 1LL * (k - 1) / 2;
  int edges = m;

  auto has_edge = [&] (int from, int to) {
    auto it = lower_bound(all(g[from]), to);
    return it != g[from].end() && *it == to;
  };

  while (!degs.empty() && degs.begin()->first < k) {
    int v = degs.begin()->second;
    degs.erase(degs.begin());
    used[v] = true;
    vec = {v};
    bool possible = max_edges <= edges;
    for (int to : g[v]) {
      if (used[to]) {
        continue;
      }
      degs.erase({deg[to], to});
      --deg[to];
      degs.insert({deg[to], to});
      --edges;
      if (deg[v] == k - 1 && possible) {
        vec.push_back(to);
      }
    }
    if (vec.size() == k) {
      bool clique = true;
      for (int j = 0; j < vec.size() && clique; ++j) {
        for (int r = j + 1; r < vec.size(); ++r) {
          if (!has_edge(vec[j], vec[r])) {
            clique = false;
            break;
          }
        }
      }
      if (clique) {
        cout << "2\n";
        for (int v : vec) {
          cout << v + 1 << " ";
        }
        cout << "\n";
        return;
      }
    }
  }

  if (!degs.empty()) {
    cout << "1 " << degs.size() << "\n";
    while (!degs.empty()) {
      cout << degs.begin()->second + 1 << " ";
      degs.erase(degs.begin());
    }
    cout << "\n";
    return;
  }
  cout << "-1\n";

}