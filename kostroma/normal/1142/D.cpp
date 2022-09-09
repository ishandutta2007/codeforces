#pragma comment(linker, "/STACK:512000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#ifdef AIM
#include <sys/resource.h>
#endif
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
  string s = FILENAME;
//    assert(!s.empty());
  freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
//freopen("/home/alexandero/ClionProjects/cryptozoology/output.txt", "w", stdout);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif

#ifdef AIM
  const rlim_t kStackSize = 256 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif

  precalc();
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  int testNum = 1;
  while (t--) {
      //cout << "Case #" << testNum++ << ": ";
      solve(true);
  }
  cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
  cout.flush();
  auto end = clock();

  usleep(10000);
  print_stats(end - start);
  usleep(10000);
#endif

    return 0;
}

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
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
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
//const int mod = 1000000007;

struct BigInt {
  vector<int> a;
  BigInt(int cur) {
    a = {cur};
    norm();
  }
  void norm() {
    for (int i = 0; i < a.size(); ++i) {
      int nex = a[i] / 11;
      if (i + 1 == a.size() && nex > 0) {
        a.push_back(nex);
      } else if (nex > 0) {
        a[i + 1] += nex;
      }
      a[i] %= 11;
    }
    while (!a.empty() && a.back() == 0) {
      a.pop_back();
    }
  }
  BigInt operator + (const BigInt& ot) const {
    vector<int> res(max(a.size(), ot.a.size()));
    for (int i = 0; i < res.size(); ++i) {
      if (i < a.size()) {
        res[i] += a[i];
      }
      if (i < ot.a.size()) {
        res[i] += ot.a[i];
      }
    }
    BigInt ans(0);
    ans.a = res;
    ans.norm();
    return ans;
  }
  BigInt operator * (int c) {
    BigInt res(0);
    res.a.assign(a.size(), 0);
    for (int i = 0; i < a.size(); ++i) {
      res.a[i] = a[i] * c;
    }
    res.norm();
    return res;
  }
  BigInt divided() {
    BigInt res(0);
    res.a = a;
    if (!res.a.empty()) {
      res.a.erase(res.a.begin());
    }
    return res;
  }
  int mod() {
    if (a.empty()) {
      return 0;
    }
    return a[0];
  }
};

void solve(__attribute__((unused)) bool read) {
  string s;
  cin >> s;
  int n = (int)s.length();
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
  }
  li ans = 0;

  vector<vector<int>> trans(11, vector<int>(10, -1));
  for (int rem = 0; rem < 11; ++rem) {
    for (int dig = 0; dig < (rem + 1) % 11; ++dig) {
      trans[rem][dig] = (rem * (rem + 1) / 2 + dig + 9) % 11;
    }
  }

  vector<int> cur_dp(11, n);
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] != 0 && cur_dp[a[i] - 1] >= i) {
      ans += cur_dp[a[i] - 1] - i;
    }
    vector<int> new_dp(11, -1);
    for (int rem = 0; rem < 11; ++rem) {
      int val = trans[rem][a[i]];
      if (val != -1) {
        new_dp[rem] = cur_dp[val];
      } else {
        new_dp[rem] = i;
      }
    }
    new_dp.swap(cur_dp);
  }
  cout << ans << "\n";
  //cerr << "mx: " << mx << endl;
}