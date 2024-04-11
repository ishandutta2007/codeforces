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
  cin >> t;
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
const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;
 
void solve(__attribute__((unused)) bool read) {
  int n, p;
  //read = false;
  if (read) {
    cin >> n >> p;
  } else {
    n = rand() % (int)1e5 + 1;
    p = rand() % (int)1e5 + 1;
    n = 1000000;
    p = 1000000;
    //p = 1;
  }
  vector<int> vals(n);
  for (int& x : vals) {
    if (read) {
      cin >> x;
    } else {
      x = rand() % (int)1e6;
    }
  }
  sort(all(vals));
  if (p == 1) {
    cout << (vals.size() % 2 == 1) << "\n";
    return;
  }
  vector<pair<int, int>> items;
  for (int i = 0; i < vals.size(); ) {
    int j = i;
    while (j < vals.size() && vals[j] == vals[i]) {
      ++j;
    }
    items.emplace_back(vals[i], j - i);
    i = j;
  }
  reverse(all(items));
  const int INF = 1e12 + 100;
  int num = 0;
  int cur_step = -1;
  for (auto& item : items) {
    if (num == 0 && item.second % 2 == 0) {
      continue;
    }
    if (num == 0) {
      num = 1;
      cur_step = item.first;
    } else {
      int new_step = item.first;
      int old_num = num;
      bool to_end = false;
      for (int i = 0; i < cur_step - new_step; ++i) {
        num = num * p;
        if (num > INF) {
          to_end = true;
          break;
        }
      }
      if (to_end) {
        int res = old_num % mod * binpow(p, cur_step, mod) % mod;
        for (auto rest_item : items) {
          if (rest_item.first > item.first) {
            continue;
          }
          res = (res - binpow(p, rest_item.first, mod) * rest_item.second) % mod;
          if (res < 0) {
            res += mod;
          }
        }
        cout << res << "\n";
        return;
      }
      int aval = item.second;
      cur_step = new_step;
      if (num >= aval) {
        num -= aval;
        continue;
      } else {
        num = (num + aval) % 2;
      }
    }
  }
  if (cur_step == -1) {
    cout << num << "\n";
    return;
  }
 
  int res = num % mod * binpow(p, cur_step, mod) % mod;
  cout << res << "\n";
 
}