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
  //freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
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

bool get_ans(int x1, int y1, int x2, int y2) {
  cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
  string s;
  cin >> s;
  assert(s != "BAD");
  return s == "YES";
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  int x = n - 1, y = n - 1;
  string rig;
  while (x + y > n - 1) {
    if (x > 0 && get_ans(0, 0, x - 1, y)) {
      --x;
      rig += 'D';
    } else {
      --y;
      rig += 'R';
    }
  }
  reverse(all(rig));
  x = 0;
  y = 0;
  string lef;
  while (x + y < n - 1) {
    if (y + 1 < n && get_ans(x, y + 1, n - 1, n - 1)) {
      ++y;
      lef += 'R';
    } else {
      ++x;
      lef += 'D';
    }
  }
  auto res = lef + rig;
  cout << "! " << res << endl;


}