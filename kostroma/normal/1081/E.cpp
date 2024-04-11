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

#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

const int C = 300500;
vector<int> divs[C];

void solve(__attribute__((unused)) bool read) {
  for (int i = 1; i < C; ++i) {
    for (int j = i; j < C; j += i) {
      if (i < j / i) {
        divs[j].push_back(i);
      }
    }
  }
  vector<vector<pair<int, int>>> who(C);
  for (int i = 1; i < C; ++i) {
    sort(all(divs[i]));
    for (int d1 : divs[i]) {
      int d2 = i / d1;
      if (d2 <= d1) {
        continue;
      }
      if ((d1 + d2) % 2) {
        continue;
      }
      who[i].push_back({(d2 - d1) / 2, (d2 + d1) / 2});
    }
    /*if (i < 100) {
      cout << i << ": " << who[i].first << " " << who[i].second << endl;
    }*/
  }
  int n;
  cin >> n;
  const int INF = (int)1e18;
  vector<int> res(n, INF);
  for (int i = 0; i < n / 2; ++i) {
    int d;
    cin >> d;
    for (auto item : who[d]) {
      if (i == 0 || item.first > res[2 * i - 1]) {
        if (item.second < res[2 * i + 1]) {
          res[2 * i] = item.first;
          res[2 * i + 1] = item.second;
        }
      }
    }
    if (res[2 * i] == INF) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  for (int i = 0; i < n; ++i) {
    int cur = res[i] * res[i];
    if (i) {
      cur -= res[i - 1] * res[i - 1];
    }
    cout << cur << " \n"[i + 1 == n];
  }


}