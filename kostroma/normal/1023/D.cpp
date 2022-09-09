#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
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

void precalc() {

}

//#define int li
//const li mod = 1000000007;
//using ull = unsigned long long;

void solve(__attribute__((unused)) bool read) {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<char> init(n, false);
  vector<int> min_pos(q + 1, n), max_pos(q + 1, -1);
  int mx_val = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    relax_max(mx_val, a[i]);
    if (a[i] > 0) {
      init[i] = true;
      relax_min(min_pos[a[i]], i);
      relax_max(max_pos[a[i]], i);
    }
  }

  vector<set<int>> to_insert(n), to_erase(n);
  for (int i = 1; i <= q; ++i) {
    if (min_pos[i] <= max_pos[i]) {
      to_insert[min_pos[i]].insert(i);
      to_erase[max_pos[i]].insert(i);
    }
  }

  set<int> cur_set;
  vector<vector<int>> possible(q + 1);
  for (int i = 0; i < n; ++i) {
    for (int x : to_insert[i]) {
      cur_set.insert(x);
    }
    int can = 0;
    if (!cur_set.empty()) {
      can = *cur_set.rbegin();
    }
    if (init[i] && a[i] < can) {
      cout << "NO\n";
      return;
    }
    a[i] = can;
    if (!init[i]) {
      possible[can].push_back(i);
    }
    for (int x : to_erase[i]) {
      cur_set.erase(x);
    }
  }
  set<int> can;
  for (int i = 0; i <= q; ++i) {
    for (int x : possible[i]) {
      can.insert(x);
    }
    if (i == q && min_pos[i] > max_pos[i]) {
      if (can.empty()) {
        cout << "NO\n";
        return;
      }
      int pos = *can.begin();
      can.erase(can.begin());
      a[pos] = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      a[i] = 1;
    }
  }

  cout << "YES\n";
  for (int x : a) {
    cout << x << " ";
  }
  cout << "\n";

}