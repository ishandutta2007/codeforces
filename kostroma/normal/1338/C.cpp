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
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;


void solve(__attribute__((unused)) bool read) {
  /*const int C = 257;
  vector<char> used(C);
  vector<int> pref;
  for (int a = 1; a < C; ++a) {
    if (used[a]) {
      continue;
    }
    bool f = false;
    for (int b = a + 1; b < C; ++b) {
      if (used[b]) {
        continue;
      }
      int c = (a ^ b);
      if (c >= C) {
        break;
      }
      if (c > b && !used[c]) {
        used[b] = used[c] = true;
        pref.push_back(a);
        pref.push_back(b);
        pref.push_back(c);
        f = true;
        break;
      }
    }
    if (!f) {
      break;
    }
  }
  for (int x : pref) {
    cout << x << " ";
  }
  cout << endl;*/

  int n;
  cin >> n;
  /*for (n = 4; n < C; ++n) {
    int stupid = pref[n - 1];*/
    if (n <= 3) {
      cout << n << "\n";
      return;
    }
    vector<int> sizes(31);
    for (int i = 0; i < sizes.size(); ++i) {
      sizes[i] = (1LL << (2 * i)) - 1;
    }
    int res = 0;
    int level = (int) sizes.size() - 1;
    for (; level >= 0; --level) {
      if (sizes[level] < n) {
        break;
      }
    }
    assert(level >= 0);
    int initial = (n - 1) % 3;
    vector<int> vals = {0, 0, 0, 1, 2, 3, 2, 3, 1, 3, 1, 2};
    int step = 1;
    int cur_val = n - sizes[level] - 1;
    while (level > 0) {
      int prev_part = (sizes[level] - sizes[level - 1]);
      res = res + step * vals[cur_val % 12];
      step *= 4;
      --level;
      if (level > 0) {
        int block = cur_val / 12;
        int where = block * 3 + cur_val % 3;
        cur_val = where;
      }
    }
    res += (initial + 1) * step;
    cout << res << "\n";

    /*cout << n << " " << res << " " << stupid << "\n";
    assert(res == stupid);
  }*/
}