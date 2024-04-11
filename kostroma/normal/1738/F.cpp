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
#include <bitset>
#include <sstream>
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
    //freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
    //freopen("/Users/alexandero/Downloads/worklife_balance_chapter_2_input.txt", "r", stdin);
    //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;

#ifdef PINELY
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
#ifndef PINELY
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    cout.precision(20);
    cout << fixed;
    cin >> t;
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

template<typename T>
void print_vec(const vector<T>& vals) {
  for (int x : vals) {
    cout << x << " ";
  }
  cout << endl;
}

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void precalc() {

}

bool local = false;
vector<vector<int>> g;
vector<int> uks;
int n;

struct Dsu {
  vector<int> dsu;
  vector<bool> used;
  Dsu(int n) {
    dsu.assign(n, 0);
    iota(all(dsu), 0);
    used.assign(n, false);
  }
  int find_set(int v) {
    if (dsu[v] == v) {
      return v;
    }
    return dsu[v] = find_set(dsu[v]);
  }
  bool merge(int new_v, int old_v) {
    new_v = find_set(new_v);
    old_v = find_set(old_v);
    assert(new_v != old_v);
    bool res = used[old_v];
    dsu[new_v] = old_v;
    used[old_v] = true;
    return res;
  }
};

int qs;

int ask(int v) {
  ++qs;
  assert(qs <= n);
  if (local) {
    if (uks[v] >= g[v].size()) {
      return -1;
    }
    //cout << "v: " << v << " to: " << g[v][uks[v]] << endl;
    return g[v][uks[v]++] + 1;
  } else {
    cout << "? " << v + 1 << endl;
    int res;
    cin >> res;
    return res;
  }
}

void check_ans(vector<int>& ans) {
  if (local) {
    vector<vector<int>> comps(n);
    for (int i = 0; i < ans.size(); ++i) {
      comps[ans[i]].push_back(i);
    }
    for (auto& vec : comps) {
      int sum_deg = 0;
      for (int v : vec) {
        sum_deg += g[v].size();
      }
      int cur_n = vec.size();
      assert(sum_deg <= cur_n * cur_n);
    }
    cout << "ok\n";
  } else {
    cout << "!";
    for (int i = 0; i < n; ++i) {
      cout << " " << ans[i] + 1;
    }
    cout << endl;
  }
}

void solve(__attribute__((unused)) bool read) {
  if (local) {
    n = rand() % 1000 + 1;
  } else {
    cin >> n;
  }
  qs = 0;
  vector<int> deg(n);
  if (local) {
    int coef = rand() % 10 + 1;
    g.clear();
    g.resize(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (rand() % coef == 0) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }
    uks.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      deg[i] = g[i].size();
    }
  } else {
    for (int i = 0; i < n; ++i) {
      cin >> deg[i];
    }
  }
  vector<pair<int, int>> sorted_degs(n);
  for (int i = 0; i < n; ++i) {
    sorted_degs[i] = {deg[i], i};
  }
  sort(sorted_degs.rbegin(), sorted_degs.rend());
  Dsu dsu(n);
  for (int pos = 0; pos < sorted_degs.size(); ++pos) {
    int v = sorted_degs[pos].second;
    int cur_comp = dsu.find_set(v);
    if (dsu.used[cur_comp]) {
      continue;
    }
    for (int i = 0; i < deg[v]; ++i) {
      int to = ask(v);
      assert(to != -1);
      --to;
      if (dsu.merge(v, to)) {
        break;
      }
    }
  }
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = dsu.find_set(i);
  }
  check_ans(ans);

}