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
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
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

#define int li
//const li mod = 1000000007;
const int mod = 998244353;
//using ull = unsigned long long;

void precalc() {
}

void add(int& cur, int val) {
  cur = (cur + val) % mod;
}

void solve(__attribute__((unused)) bool read) {
  int n, m;
  //read = false;
  if (read) {
    cin >> n >> m;
  } else {
    n = rand() % 1000 + 1;
    m = rand() % 1000 + 1;
  }
  vector<int> a(n);
  for (int& x : a) {
    if (read) {
      cin >> x;
    } else {
      x = rand() % (int)1e9;
    }
  }
  vector<vector<int>> g(n);
  vector<int> in_deg(n, 0);
  for (int i = 0; i < m; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
      --a;
      --b;
    } else {
      do {
        a = rand() % n;
        b = rand() % n;
      } while (a >= b);
    }
    g[a].push_back(b);
    ++in_deg[b];
  }

  vector<int> order;
  for (int i = 0; i < n; ++i) {
    if (in_deg[i] == 0) {
      order.push_back(i);
    }
  }
  for (int i = 0; i < order.size(); ++i) {
    for (int to : g[order[i]]) {
      --in_deg[to];
      if (in_deg[to] == 0) {
        order.push_back(to);
      }
    }
  }
  assert(order.size() == n);
  vector<int> rev_order(n, -1);
  for (int i = 0; i < n; ++i) {
    rev_order[order[i]] = i;
  }
  vector<int> dp(n, 0);
  dp.back() = 1;
  for (int i = n - 2; i >= 0; --i) {
    for (int to : g[order[i]]) {
      add(dp[i], dp[rev_order[to]]);
    }
  }

  vector<int> iter;
  int init_ops = n;
  for (int step = 0; step < init_ops; ++step) {
    iter.clear();
    for (int i = 0; i < n; ++i) {
      if (a[i] > 0) {
        //cout << "dec: " << i << endl;
        iter.emplace_back(i);
        --a[i];
      }
    }
    if (iter.empty()) {
      cout << step << '\n';
      return;
    }
    for (int v : iter) {
      for (int to : g[v]) {
        ++a[to];
      }
    }
    /*cout << "step: " << step << endl;
    for (int x : a) {
      cout << x << " ";
    }
    cout << endl;
    int cur_res = 0;
    for (int i = 0; i < n; ++i) {
      cout << order[i] << " paths: " << dp[i] << "a: " << a[oder[i]] << endl;
      add(cur_res, dp[i] * a[order[i]]);
    }
    cout << "cur_res: " << cur_res << endl;*/
  }
  int res = init_ops % mod;
  for (int i = 0; i < n; ++i) {
    //cout << order[i] << " paths: " << dp[i] << endl;
    add(res, dp[i] * a[order[i]]);
  }
  cout << res << "\n";

}