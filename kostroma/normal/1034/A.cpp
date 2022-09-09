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
//using ull = unsigned long long;

const int C = 15000005;
int lp[C];
vector<int> pr;
int cnt[C];

void solve(__attribute__((unused)) bool read) {
  for (int i = 2; i < C; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < C; ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
  //read = false;
  int n;
  if (read) {
    cin >> n;
  } else {
    n = 300000;
  }
  vector<int> divisors;
  for (int i = 0; i < n; ++i) {
    int cur;
    if (read) {
      cin >> cur;
    } else {
      cur = 9699690;
    }
    divisors = {1};
    while (cur > 1) {
      int p = lp[cur];
      int cnt = 0;
      while (cur % p == 0) {
        cur /= p;
        ++cnt;
      }
      int sz = divisors.size();
      for (int j = 0; j < sz; ++j) {
        int now = divisors[j];
        for (int ji = 0; ji < cnt; ++ji) {
          now = now * p;
          divisors.push_back(now);
        }
      }
    }
    for (int d : divisors) {
      ++cnt[d];
    }
  }
  int res = -1;
  for (int i = 1; i < C; ++i) {
    if (cnt[i] > 0 && cnt[i] < n) {
      if (res == -1 || res > n - cnt[i]) {
        res = n - cnt[i];
      }
    }
  }
  cout << res << "\n";
}