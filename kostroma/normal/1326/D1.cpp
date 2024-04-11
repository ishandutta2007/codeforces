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

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

array<vector<int>, 2> manacher(const string& s) {
  int n = s.length();
  array<vector<int>, 2> res;
  for (auto& v : res) {
    v.assign(n, 0);
  }
  for (int z = 0, l = 0, r = 0; z < 2; ++z, l = 0, r = 0) {
    for (int i = 0; i < n; ++i) {
      if (i < r) {
        res[z][i] = min(r - i + !z, res[z][l + r - i + !z]);
      }
      int L = i - res[z][i], R = i + res[z][i] - !z;
      while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1]) {
        ++res[z][i];
        --L;
        ++R;
      }
      if (R > r) {
        l = L;
        r = R;
      }
    }
  }
  return res;
}

void solve(__attribute__((unused)) bool read) {
  string s;
  cin >> s;
  auto man = manacher(s);
  int max_equal = 0;
  while (max_equal < (int)s.length() - 1 - max_equal && s[max_equal] == s[(int)s.length() - 1 - max_equal]) {
    ++max_equal;
  }
  vector<pair<int, int>> subs;
  int best_len = 0;
  for (int i = 0; i < s.length(); ++i) {
    for (int z = 0; z < 2; ++z) {
      if (z == 0 && man[0][i] == 0) {
        continue;
      }
      int L = i - man[z][i], R = i + man[z][i] + (z == 1);
      int can = min(L, (int) s.length() - R);
      if (can <= max_equal) {
        int cur_len = 2 * can + R - L;
        if (cur_len > best_len) {
          best_len = cur_len;
          subs = {{0, can},
                  {L, R},
                  {(int) s.length() - can, (int) s.length()}};
        }
      }
    }
  }

  string res;
  for (auto item : subs) {
    for (int i = item.first; i < item.second; ++i) {
      res += s[i];
    }
  }
  cout << res << "\n";

}