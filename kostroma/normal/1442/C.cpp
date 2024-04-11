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
const int mod = 998244353;
//using ull = unsigned long long;

const int L = 40;

struct Dist {
  int changes;
  li min_len;

  li get_overall_len() const {
    return (1LL << changes) + min_len - 1;
  }

  bool operator < (const Dist& ot) const {
    if (changes == ot.changes) {
      return min_len < ot.min_len;
    }
    return changes < ot.changes;
  }
};

bool cmp(const Dist& o1, const Dist& o2) {
  if (o1.changes == o2.changes) {
    return o1.min_len < o2.min_len;
  }
  if (max(o1.changes, o2.changes) >= L) {
    return o1.changes < o2.changes;
  }
  return o1.get_overall_len() < o2.get_overall_len();
}

struct State {
  int v;
  int type;
  bool operator < (const State& ot) const {
    if (type != ot.type) {
      return type < ot.type;
    }
    return v < ot.v;
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, m;
  //read = false;
  if (read) {
    cin >> n >> m;
  } else {
    n = 200000;
    m = n;
  }
  vector<vector<vector<int>>> g(2, vector<vector<int>>(n));
  for (int i = 0; i < m; ++i) {
    int from, to;
    if (read) {
      cin >> from >> to;
      --from;
      --to;
    } else {
      from = rand() % n;
      to = rand() % n;
    }
    g[0][from].push_back(to);
    g[1][to].push_back(from);
  }
  const li BIG_INF = (li)1e18;
  const int INF = (int)1e9;
  vector<vector<li>> dp_dist(L, vector<li>(n, BIG_INF));
  dp_dist[0][0] = 0;
  set<pair<li, int>> have;
  for (int changes = 0; changes < L; ++changes) {
    have.clear();
    for (int i = 0; i < n; ++i) {
      if (dp_dist[changes][i] != INF) {
        have.insert({dp_dist[changes][i], i});
      }
    }
    while (!have.empty()) {
      auto beg_it = have.begin();
      int v = beg_it->second;
      have.erase(beg_it);
      auto cur_dist = dp_dist[changes][v];

      //cout << v << " " << type << " " << changes << " " << cur_dist.get_overall_len() << endl;

      auto relax = [&] (int to, li candy) {
        auto& now_dist = dp_dist[changes][to];
        if (candy < now_dist) {
          have.erase({now_dist, {to}});
          now_dist = candy;
          have.insert({now_dist, {to}});
        }
      };

      for (int to : g[changes % 2][v]) {
        relax(to, cur_dist + 1);
      }
    }
    if (changes + 1 == L) {
      break;
    }
    for (int i = 0; i < n; ++i) {
      if (dp_dist[changes][i] == INF) {
        continue;
      }
      relax_min(dp_dist[changes + 1][i], dp_dist[changes][i]);
    }
  }

  Dist res = {INF, 0};
  for (int i = 0; i < L; ++i) {
    if (dp_dist[i][n - 1] == BIG_INF) {
      continue;
    }
    Dist cur_res = {i, dp_dist[i][n - 1]};
    if (cmp(cur_res, res)) {
      res = cur_res;
    }
  }

  {
    vector<vector<Dist>> dist(n, vector<Dist>(2, {INF, 0}));
    set<pair<Dist, State>> have;
    for (int changes = 0; changes < L; ++changes) {
      for (int i = 0; i < n; ++i) {
        int type = changes % 2;
        auto& cur_dp = dist[i][type];
        if (cur_dp.changes == INF && dp_dist[changes][i] != BIG_INF) {
          cur_dp = {changes, dp_dist[changes][i]};
          have.insert({cur_dp, {i, type}});
        }
      }
    }

    while (!have.empty()) {
      auto beg_it = have.begin();
      int v = beg_it->second.v, type = beg_it->second.type;
      have.erase(beg_it);
      auto cur_dist = dist[v][type];

      //cout << v << " " << type << " " << changes << " " << cur_dist.get_overall_len() << endl;

      auto relax = [&](int to, int new_type, Dist candy) {
        auto& now_dist = dist[to][new_type];
        if (candy < now_dist) {
          have.erase({now_dist, {to, new_type}});
          now_dist = candy;
          have.insert({now_dist, {to, new_type}});
        }
      };

      {
        auto new_dist = cur_dist;
        ++new_dist.changes;
        relax(v, type ^ 1, new_dist);
      }

      for (int to : g[type][v]) {
        auto new_dist = cur_dist;
        ++new_dist.min_len;
        relax(to, type, new_dist);
      }
    }

    for (int r = 0; r < 2; ++r) {
      auto cur_res = dist[n - 1][r];
      if (cmp(cur_res, res)) {
        res = cur_res;
      }
    }
  }

  li ans = 1;
  for (int i = 0; i < res.changes; ++i) {
    ans = ans * 2 % mod;
  }
  ans += res.min_len - 1;
  ans %= mod;
  if (ans < 0) {
    ans += mod;
  }
  cout << ans << "\n";

}