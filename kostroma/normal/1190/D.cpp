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

struct SegTree {
  int shift;
  vector<int> tree;
  SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, 0);
  }
  void update(int v) {
    v += shift;
    tree[v] = 1;
    v /= 2;
    while (v) {
      tree[v] = tree[2 * v] + tree[2 * v + 1];
      v /= 2;
    }
  }
  int get_sum(int l, int r) {
    l += shift;
    r += shift;
    int res = 0;
    while (l < r) {
      if (l & 1) {
        res += tree[l++];
        continue;
      }
      if (r & 1) {
        res += tree[--r];
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
  vector<pair<int, int>> a(n);
  vector<vector<int>> coords(2);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    coords[0].push_back(a[i].first);
    coords[1].push_back(a[i].second);
  }
  for (auto& vec : coords) {
    make_unique(vec);
  }
  for (auto& pt : a) {
    pt.first = lower_bound(all(coords[0]), pt.first) - coords[0].begin();
    pt.second = lower_bound(all(coords[1]), pt.second) - coords[1].begin();
  }
  SegTree tree(coords[0].size());
  sort(all(a), [&](const pair<int, int>& q, const pair<int, int>& w) {
    if (q.second != w.second) {
      return q.second > w.second;
    }
    return q.first > w.first;
  });

  li ans = 0;
  for (int i = 0; i < n; ++i) {
    int L = 0;
    if (i + 1 < n && a[i].second == a[i + 1].second) {
      L = a[i + 1].first + 1;
    }
    int M = a[i].first;
    int R = coords[0].size();
    li rig = tree.get_sum(M + 1, R) + 1;
    li lef = tree.get_sum(L, M) + 1;
    ans += lef * rig;
    //cout << coords[0][a[i].first] << " " << coords[1][a[i].second] << " " << lef << " " << rig << endl;
    tree.update(M);
  }
  cout << ans << endl;
}