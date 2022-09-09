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
  cin >> t;
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

#define int li
//const int mod = 1000000007;

const int C = 200500;

int dp[C][2][2];

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 200000;
  }
  string s;
  if (read) {
    cin >> s;
  } else {
    for (int i = 0; i < n; ++i) {
      s += "LR"[rand() & 1];
    }
  }
  const int INF = (int)1e9;
  int res = INF;
  for (int mask = 0; mask < 4; ++mask) {
    for (int i = 0; i <= n; ++i) {
      for (int r = 0; r < 2; ++r) {
        dp[i][r][0] = dp[i][r][1] = INF;
      }
    }
    int& start_dp = dp[2][mask & 1][(bool)(mask & 2) == (bool)(mask & 1)];
    start_dp = 0;
    for (int i = 0; i < 2; ++i) {
      if ((s[i] == 'R') != (bool)(mask & (1 << (1 - i)))) {
        ++start_dp;
      }
    }
    //cout << "mask: " << mask << " start: " << start_dp << endl;
    for (int i = 2; i < n; ++i) {
      for (int val = 0; val < 2; ++val) {
        for (int same = 0; same < 2; ++same) {
          int cur_dp = dp[i][val][same];
          if (cur_dp == INF) {
            continue;
          }
          for (int nex = 0; nex < 2; ++nex) {
            int new_same = (nex != val ? 0 : (same + 1));
            if (new_same > 1) {
              continue;
            }
            relax_min(dp[i + 1][nex][new_same], cur_dp + ((s[i] == 'R') != nex));
          }
        }
      }
    }
    for (int val = 0; val < 2; ++val) {
      for (int same = 0; same < 2; ++same) {
        if (val == (bool)(mask & 2)) {
          int new_same = same + 1 + (val == (bool)(mask & 1));
          if (new_same > 1) {
            continue;
          }
        }
        //cout << "relax mask: " << mask << " val: " << val << " same: " << same << " dp: " << dp[n][val][same] << endl;
        relax_min(res, dp[n][val][same]);
      }
    }
  }
  cout << res << "\n";
}