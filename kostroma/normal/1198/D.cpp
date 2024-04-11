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

vector<string> matrix;
vector<vector<int>> pref_sums;

const int C = 52;
int dp[C][C][C][C];

int get_sum(int lx, int rx, int ly, int ry) {
  return pref_sums[rx][ry] - pref_sums[rx][ly] - pref_sums[lx][ry] + pref_sums[lx][ly];
}

int rec(int lx, int rx, int ly, int ry) {
  int& res = dp[lx][rx][ly][ry];
  if (res != -1) {
    return res;
  }
  if (get_sum(lx, rx, ly, ry) == 0) {
    return res = 0;
  }
  res = max(rx - lx, ry - ly);
  for (int m = lx + 1; m < rx; ++m) {
    relax_min(res, rec(lx, m, ly, ry) + rec(m, rx, ly, ry));
  }
  for (int m = ly + 1; m < ry; ++m) {
    relax_min(res, rec(lx, rx, ly, m) + rec(lx, rx, m, ry));
  }
  //cout << lx << " " << rx << " " << ly << " " << ry << " " << res << endl;
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 50;
  }
  matrix.resize(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> matrix[i];
    } else {
      matrix[i] = string(n, '#');
    }
  }
  pref_sums.assign(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      pref_sums[i + 1][j + 1] = pref_sums[i][j + 1] + pref_sums[i + 1][j] - pref_sums[i][j] + (matrix[i][j] == '#');
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int r = 0; r <= n; ++r) {
        for (int z = 0; z <= n; ++z) {
          dp[i][j][r][z] = -1;
        }
      }
    }
  }
  int ans = rec(0, n, 0, n);
  cout << ans << "\n";

}