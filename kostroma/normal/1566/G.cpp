#pragma comment(linker, "/STACK:512000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <memory>
#include <chrono>
#include <cassert>
#include <random>
#include <queue>
#include <set>
#include <map>
#include <array>
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
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;

#ifdef AIM
  const rlim_t kStackSize = 60 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif
#ifndef AIM
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
//const int mod = 998244353;
//using ull = unsigned long long;

struct Candidate {
  int cost;
  int a, b;
  bool operator < (const Candidate& ot) const {
    if (cost != ot.cost) {
      return cost < ot.cost;
    }
    return make_pair(a, b) < make_pair(ot.a, ot.b);
  }

  bool matches(const Candidate& ot) const {
    return a != ot.a && a != ot.b && b != ot.a && b != ot.b;
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  vector<set<pair<int, int>>> g(n);
  map<pair<int, int>, int> costs;
  for (int i = 0; i < m; ++i) {
    int a, b, cost;
    cin >> a >> b >> cost;
    --a; --b;
    if (a > b) {
      swap(a, b);
    }
    costs[{a, b}] = cost;
    g[a].insert({cost, b});
    g[b].insert({cost, a});
  }
  set<Candidate> candidates;
  set<Candidate> threes;

  auto in_top = [&] (int v, int to) {
    auto it = g[v].begin();
    for (int w = 0; w < 3 && it != g[v].end(); ++w, ++it) {
      if (it->second == to) {
        return true;
      }
    }
    return false;
  };

  auto update_vertex = [&] (int v, bool cancel) {
    auto it = g[v].begin();
    int sum = 0;
    for (int w = 0; w < 3 && it != g[v].end(); ++w, ++it) {
      sum += it->first;
      if (in_top(it->second, v)) {
        Candidate candy = {it->first, v, it->second};
        if (candy.a > candy.b) {
          swap(candy.a, candy.b);
        }
        if (cancel) {
          candidates.erase(candy);
        } else {
          candidates.insert(candy);
        }
      }
    }
    if (g[v].size() >= 3) {
      if (cancel) {
        threes.erase({sum, v, v});
      } else {
        threes.insert({sum, v, v});
      }
    }
  };

  for (int i = 0; i < n; ++i) {
    update_vertex(i, false);
  }

  const int INF = (int)1e18;

  auto print_ans = [&] () {
    int res = INF;
    if (!threes.empty()) {
      relax_min(res, threes.begin()->cost);
    }
    for (auto it = candidates.begin(); it != candidates.end(); ++it) {
      if (it->cost * 2 >= res) {
        break;
      }
      auto second_it = next(it);
      while (second_it != candidates.end() && second_it->cost + it->cost < res) {
        if (it->matches(*second_it)) {
          res = second_it->cost + it->cost;
          break;
        }
        ++second_it;
      }
    }
    cout << res << "\n";
  };

  print_ans();

  int Q;
  cin >> Q;
  while (Q--) {
    int type, a, b;
    cin >> type >> a >> b;
    --a; --b;
    if (a > b) {
      swap(a, b);
    }
    update_vertex(a, true);
    update_vertex(b, true);
    if (type == 0) {
      auto cost = costs[{a, b}];
      g[a].erase({cost, b});
      g[b].erase({cost, a});
      costs.erase({a, b});
    } else {
      int cost;
      cin >> cost;
      costs[{a, b}] = cost;
      g[a].insert({cost, b});
      g[b].insert({cost, a});
    }
    update_vertex(a, false);
    update_vertex(b, false);
    print_ans();
  }

}