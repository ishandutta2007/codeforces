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

const int L = 18;

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  int ans = 1;
  vector<int> b(n - 1);
  for (int i = 0; i + 1 < n; ++i) {
    b[i] = abs(a[i + 1] - a[i]);
  }
  --n;
  vector<vector<int>> sparse(L, vector<int>(n));
  sparse[0] = b;
  for (int k = 1; k < L; ++k) {
    for (int i = 0; i < n; ++i) {
      sparse[k][i] = sparse[k - 1][i];
      int nex = i + (1 << (k - 1));
      if (nex < n) {
        sparse[k][i] = gcd(sparse[k][i], sparse[k - 1][nex]);
      }
    }
  }
  int l = 0, r = n + 1;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    bool is_good = false;
    int layer = 31 - __builtin_clz((signed)m);
    for (int i = 0; i + m <= n; ++i) {
      if (gcd(sparse[layer][i], sparse[layer][i + m - (1 << layer)]) > 1) {
        is_good = true;
        break;
      }
    }
    if (is_good) {
      l = m;
    } else {
      r = m;
    }
  }
  relax_max(ans, l + 1);
  cout << ans << "\n";
}