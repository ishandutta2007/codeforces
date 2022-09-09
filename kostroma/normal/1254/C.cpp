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
  //freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
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

#define int li
//const li mod = 1000000007;
//const li mod = 998244353;
//using ull = unsigned long long;

int ask(int t, int i, int j, int k) {
  cout << t << " " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
  int res;
  cin >> res;
  return res;
}

void output(vector<int> res) {
  cout << 0 << " ";
  for (int x : res) {
    cout << x + 1 << " ";
  }
  cout << endl;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  int cur_max = 1;
  for (int i = 2; i < n; ++i) {
    if (ask(2, 0, i, cur_max) > 0) {
      cur_max = i;
    }
  }
  vector<pair<int, int>> areas;
  for (int i = 1; i < n; ++i) {
    if (i != cur_max) {
      int area = ask(1, 0, cur_max, i);
      areas.emplace_back(area, i);
    }
  }
  sort(all(areas));
  reverse(all(areas));
  vector<int> lef, rig;
  int upper_index = areas[0].second;
  rig.push_back(upper_index);
  for (int i = 1; i < areas.size(); ++i) {
    int index = areas[i].second;
    if (ask(2, 0, upper_index, index) > 0) {
      lef.push_back(index);
    } else {
      rig.push_back(index);
    }
  }
  reverse(all(rig));
  vector<int> res = {0, cur_max};
  for (int x : rig) {
    res.push_back(x);
  }
  for (int x : lef) {
    res.push_back(x);
  }
  output(res);

}