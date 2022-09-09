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

void precalc() {

}

#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

const int INF = (int)1e18;

struct SegTree {
  vector<int> vals;
  int shift;
  vector<int> tree;
  SegTree(const vector<int>& vals_): vals(vals_) {
    make_unique(vals);
    shift = 1;
    while (shift < vals.size()) {
      shift *= 2;
    }
    tree.assign(2 * shift, -INF);
  }
  void update(int v, int val) {
    v = lower_bound(all(vals), v) - vals.begin();
    v += shift;
    relax_max(tree[v], val);
    v /= 2;
    while (v) {
      tree[v] = max(tree[2 * v], tree[2 * v + 1]);
      v /= 2;
    }
  }
  int get_res(int pref_sum) {
    int l = 0, r = lower_bound(all(vals), pref_sum) - vals.begin();
    l += shift;
    r += shift;
    int res = -INF;
    while (l < r) {
      if (l & 1) {
        relax_max(res, tree[l++]);
        continue;
      }
      if (r & 1) {
        relax_max(res, tree[--r]);
        continue;
      }
      l /= 2;
      r /= 2;
    }
    return res;
  }
};

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  vector<int> vals = {0};
  {
    int pref_sum = 0;
    for (int i = 0; i < n; ++i) {
      pref_sum += a[i];
      vals.push_back(pref_sum);
    }
  }

  vector<pair<int, int>> st;
  st.emplace_back(0, 0);
  vector<int> dp(n + 1, 0);
  int pref_sum = 0;
  map<int, int> max_dp;
  max_dp[0] = 0;
  SegTree tree(vals);
  tree.update(0, 0);
  for (int i = 0; i < n; ++i) {
    pref_sum += a[i];
    /*cout << "i: " << i << " sz: " << st.size() << " pref_sum: " << pref_sum << endl;
    for (auto item : st) {
      cout << item.first << " " << item.second << endl;
    }*/
    dp[i + 1] = dp[i] - 1;
    relax_max(dp[i + 1], tree.get_res(pref_sum) + (i + 1));
    if (max_dp.count(pref_sum)) {
      relax_max(dp[i + 1], max_dp[pref_sum]);
    }
    max_dp[pref_sum] = dp[i + 1];
    tree.update(pref_sum, dp[i + 1] - (i + 1));
    //cout << "i: " << i << " dp: " << dp[i + 1] << endl;
  }
  cout << dp[n] << '\n';

}