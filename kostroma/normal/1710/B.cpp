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
//const int mod = 998244353;
//using ull = unsigned long long;

void precalc() {
}

struct Rain {
  int x, p;
  int id;
  bool operator < (const Rain& ot) const {
    return x < ot.x;
  }
};

struct Event {
  int pos;
  int add_sum, add_coef;
  bool operator < (const Event& ot) const {
    return pos < ot.pos;
  }
};

const int L = 18;

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  vector<Rain> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].p;
    a[i].id = i;
  }
  sort(all(a));
  vector<Event> evs;
  vector<int> lef(n), rig(n);
  for (int i = 0; i < n; ++i) {
    auto l = lower_bound(all(a), Rain{a[i].x - a[i].p, 0, 0}) -  a.begin();
    lef[i] = l;
    evs.push_back({l, a[i].p - a[i].x, 1});
    evs.push_back({i + 1, -(a[i].p - a[i].x), -1});
    evs.push_back({i + 1, a[i].p + a[i].x, -1});
    auto r = lower_bound(all(a), Rain{a[i].x + a[i].p, 0, 0}) -  a.begin();
    evs.push_back({r, -(a[i].p + a[i].x), 1});
    rig[i] = r;
  }
  sort(all(evs));
  vector<int> res(n);
  auto ev_it = evs.begin();
  int cur_sum = 0, cur_coef = 0;
  for (int i = 0; i < n; ++i) {
    while (ev_it != evs.end() && ev_it->pos <= i) {
      cur_sum += ev_it->add_sum;
      cur_coef += ev_it->add_coef;
      ++ev_it;
    }
    res[i] = cur_sum + cur_coef * a[i].x;
    //cout << res[i] << " ";
  }
  //cout << endl;
  const int INF = (int)1e18;
  vector<int> pref_max(n + 1, -INF);
  auto suf_max = pref_max;
  vector<vector<int>> sparse_add(L, vector<int>(n));
  auto sparse_sub = sparse_add;
  for (int i = 0; i < n; ++i) {
    sparse_sub[0][i] = res[i] - a[i].x;
    sparse_add[0][i] = res[i] + a[i].x;
    pref_max[i + 1] = max(pref_max[i], res[i]);
  }
  for (int i = n - 1; i >= 0; --i) {
    suf_max[i] = max(suf_max[i + 1], res[i]);
  }
  for (int i = 1; i < L; ++i) {
    sparse_add[i] = sparse_add[i - 1];
    sparse_sub[i] = sparse_sub[i - 1];
    for (int j = 0; j < n; ++j) {
      int pos = j + (1 << (i - 1));
      if (pos >= n) {
        break;
      }
      relax_max(sparse_add[i][j], sparse_add[i - 1][pos]);
      relax_max(sparse_sub[i][j], sparse_sub[i - 1][pos]);
    }
  }

  auto get_layer = [&] (int l, int r) {
    return 63 - __builtin_clzll(r - l);
  };

  auto get_max_add = [&] (int l, int r) {
    int b = get_layer(l, r);
    return max(sparse_add[b][l], sparse_add[b][r - (1 << b)]);
  };

  auto get_max_sub = [&] (int l, int r) {
    int b = get_layer(l, r);
    return max(sparse_sub[b][l], sparse_sub[b][r - (1 << b)]);
  };

  string ans(n, '0');
  for (int i = 0; i < n; ++i) {
    int l = lef[i], r = rig[i];
    if (pref_max[l] > m || suf_max[r] > m) {
      continue;
    }
    auto max_lef = get_max_sub(l, i + 1) - (a[i].p - a[i].x);
    //cout << i << " " << l << " " << r << " " << max_lef << " " << sparse_sub[i + 1] << endl;
    auto max_rig = get_max_add(i, r) - (a[i].p + a[i].x);
    if (max_lef > m) {
      continue;
    }
    if (max_rig > m) {
      continue;
    }
    ans[a[i].id] = '1';
  }
  cout << ans << "\n";
}