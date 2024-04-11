#pragma comment(linker, "/STACK:512000000")
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

struct DP {
  string candy;
  vector<int> reverses;
};

string reversed(string s) {
  reverse(all(s));
  return s;
}

void solve(__attribute__((unused)) bool read) {
  string s;
  //read = false;
  if (read) {
    cin >> s;
  } else {
    s = string(1000,'a');
  }
  vector<DP> dp(2, {"", {}});
  for (int i = 0; i < s.length(); ++i) {
    vector<DP> new_dp(2, {"", {}});

    auto relax = [&] (DP& val_dp, int index) {
      auto& to_relax = new_dp[index];
      bool need = to_relax.candy.empty();
      if (index == 0) {
        need |= to_relax.candy > val_dp.candy;
      } else {
        need |= reversed(to_relax.candy) > reversed(val_dp.candy);
      }
      if (need) {
        to_relax = val_dp;
      }
    };

    for (int j = 0; j < 2; ++j) {
      DP new_can = dp[j];
      new_can.candy += s[i];
      new_can.reverses.push_back(0);
      relax(new_can, j);
      reverse(all(new_can.candy));
      new_can.reverses.back() = 1;
      relax(new_can, j ^ 1);
    }
    dp.swap(new_dp);
  }
  auto res = dp[0].reverses;
  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;
}