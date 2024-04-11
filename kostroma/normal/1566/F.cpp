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
    cin >> t;
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

const int INF = (int)1e18;

struct DP {
  vector<pair<int, int>> once_dp, twice_dp;

  void swap(DP& ot) {
    once_dp.swap(ot.once_dp);
    twice_dp.swap(ot.twice_dp);
  }

  auto append_val(int old_dp, int dist) {
    once_dp.emplace_back(old_dp + dist, dist);
    twice_dp.emplace_back(old_dp + dist * 2, dist);
  }
  void process() {
    auto cmp = [&](const pair<int, int>& q, const pair<int, int>& w) {
      return q.second < w.second;
    };
    sort(all(once_dp), cmp);
    sort(all(twice_dp), cmp);
    for (int i = 1; i < twice_dp.size(); ++i) {
      relax_min(twice_dp[i].first, twice_dp[i - 1].first);
    }
    for (int i = (int)once_dp.size() - 2; i >= 0; --i) {
      relax_min(once_dp[i].first, once_dp[i + 1].first);
    }
  }
  int get_best(int dist) {
    auto cmp = [&](const pair<int, int>& q, const pair<int, int>& w) {
      return q.second < w.second;
    };
    auto mid = lower_bound(all(twice_dp), make_pair(0, dist), cmp) - twice_dp.begin();
    int res = INF;
    if (mid > 0) {
      relax_min(res, twice_dp[mid - 1].first + dist);
    }
    if (mid < once_dp.size()) {
      relax_min(res, once_dp[mid].first + 2 * dist);
    }
    return res;
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  sort(all(a));
  vector<vector<pair<int, int>>> buckets(n + 1);
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    auto bucket = lower_bound(all(a), l) - a.begin();
    if (bucket < a.size() && r >= a[bucket]) {
      continue;
    }
    //cout << bucket << " " << l << " " << r << endl;
    buckets[bucket].emplace_back(l, r);
  }
  int start_coord = a[0];
  for (auto seg : buckets[0]) {
    relax_min(start_coord, seg.second);
  }
  DP cur_dp;
  cur_dp.append_val(0, a[0] - start_coord);
  auto cmp = [&](const pair<int, int>& q, const pair<int, int>& w) {
    return q.second < w.second;
  };
  for (int i = 0; i < n; ++i) {
    DP next_dp;
    sort(all(buckets[i + 1]), cmp);
    set<int> left_borders;

    auto append_dp = [&] (int dist) {
      int max_left = 0;
      if (!left_borders.empty()) {
        max_left = *left_borders.rbegin() - a[i];
      }
      next_dp.append_val(cur_dp.get_best(max_left), dist);
    };

    for (auto &seg : buckets[i + 1]) {
      if (i + 1 < n) {
        append_dp(a[i + 1] - seg.second);
      }
      left_borders.insert(seg.first);
    }
    append_dp(0);
    cur_dp.swap(next_dp);
    cur_dp.process();
  }

  cout << cur_dp.get_best(0) << "\n";

}