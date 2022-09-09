#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
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
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
#endif

#ifdef PINELY
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
#ifndef PINELY
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

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void precalc() {
}


struct SegTree {
  int shift;
  vector<int> tree;
  SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, -1);
  }
  void update(int v, int val) {
    v += shift;
    tree[v] = val;
    v /= 2;
    while (v) {
      tree[v] = max(tree[2 * v], tree[2 * v + 1]);
      v /= 2;
    }
  }
  int get_res(int l, int r) {
    l += shift;
    r += shift;
    int res = -1;
    while (l < r) {
      if (l & 1) {
        relax_max(res, tree[l]);
        ++l;
        continue;
      }
      if (r & 1) {
        --r;
        relax_max(res, tree[r]);
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
  vector<pair<int, int>> poses(n, {-1, -1});
  for (int i = 0; i < n; ++i) {
    int cur;
    cin >> cur;
    --cur;
    poses[cur].second = i;
    if (poses[cur].first == -1) {
      poses[cur].first = i;
    }
  }
  vector<int> rig(n, -1);
  for (int i = 0; i < n; ++i) {
    if (poses[i].first != -1) {
      rig[poses[i].first] = poses[i].second;
    }
  }
  int res = n;
  for (int l = 0; l < n; ) {
    if (rig[l] == -1) {
      ++l;
      continue;
    }
    int r = rig[l];
    if (l == r) {
      --res;
      ++l;
      continue;
    }
    res -= 2;
    while (true) {
      int new_r = r;
      while (l < r) {
        relax_max(new_r, rig[l]);
        ++l;
      }
      if (new_r == r) {
        break;
      }
      --res;
      r = new_r;
    }
    l = r + 1;
  }

  cout << res << "\n";
}