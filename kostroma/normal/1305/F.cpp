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

const int C = 1000500;
vector<int> primes;
bool not_prime[C];

void solve(__attribute__((unused)) bool read) {
  for (int p = 2; p < C; ++p) {
    if (!not_prime[p]) {
      primes.push_back(p);
      for (int j = p * p; j < C; j += p) {
        not_prime[j] = true;
      }
    }
  }

  //read = false;
  int n;
  if (read) {
    cin >> n;
  } else {
    n = 200000;
  }
  vector<int> a(n);
  int res = 0;
  int cnt = 0;
  for (int& x : a) {
    if (read) {
      cin >> x;
    } else {
      x = 1000000000000LL - cnt;
      ++cnt;
    }
    res += (x % 2 == 1);
  }
  sort(all(a));
  int min_val = max(1LL, a[0] - n);
  vector<int> rest(2 * n + 1);
  vector<vector<int>> factors(rest.size());
  for (int i = 0; i < factors.size(); ++i) {
    rest[i] = min_val + i;
  }
  vector<int> candies;
  for (int p : primes) {
    int r = min_val % p;
    int div_val = min_val + (r == 0 ? 0 : (p - r));
    int pos = div_val - min_val;
    if (pos < rest.size()) {
      candies.push_back(p);
    }
    while (pos < rest.size()) {
      while (rest[pos] % p == 0) {
        rest[pos] /= p;
      }
      pos += p;
    }
  }
  for (int r : rest) {
    if (r > 1) {
      candies.push_back(r);
    }
  }
  make_unique(candies);
  //cerr << "candies: " << candies.size() << endl;
  for (int p : candies) {
    int cur_res = 0;
    for (int x : a) {
      if (cur_res > res) {
        break;
      }
      int r = x % p;
      if (x == r) {
        cur_res += p - r;
      } else {
        cur_res += min(r, p - r);
      }
    }
    relax_min(res, cur_res);
    //cout << p << " " << cur_res << endl;
  }

  cout << res << endl;

}