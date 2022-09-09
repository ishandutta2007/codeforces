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
//const int mod = 998244353;
//using ull = unsigned long long;

const int MAXN = 15;

unordered_map<int, li> dp[MAXN][1 << MAXN];

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 14;
  }
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    if (read) {
      string s;
      cin >> s;
      for (int j = 0; j < n; ++j) {
        matrix[i][j] = s[j] - '0';
      }
    } else {
      for (int j = 0; j < n; ++j) {
        if (j == i) {
          matrix[i][j] = 0;
          continue;
        }
        if (i > j) {
          matrix[i][j] = matrix[j][i];
          continue;
        }
        matrix[i][j] = rand() % 2;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    dp[i][1 << i][0] = 1;
  }
  vector<li> res(1 << (n - 1), 0);
  int half = (n + 1) / 2;
  for (int mask = 1; mask < (1 << n); ++mask) {
    int cnt_bits = __builtin_popcount(mask);
    if (cnt_bits > half) {
      continue;
    }
    for (int last = 0; last < n; ++last) {
      if (dp[last][mask].empty()) {
        continue;
      }
      if (mask + 1 == (1 << n)) {
        for (auto& item : dp[last][mask]) {
          res[item.first] += item.second;
        }
        continue;
      }
      for (int nex = 0; nex < n; ++nex) {
        if (mask & (1 << nex)) {
          continue;
        }
        for (auto& item : dp[last][mask]) {
          //++cnt;
          int new_m = item.first * 2 + matrix[last][nex];
          dp[nex][mask | (1 << nex)][new_m] += item.second;
        }
      }
    }
  }
  //cout << "cnt: " << cnt << endl;

  vector<int> reversed_mask(1 << (half - 1));
  for (int m = 0; m < reversed_mask.size(); ++m) {
    for (int j = 0; j < half - 1; ++j) {
      if (m & (1 << j)) {
        reversed_mask[m] |= (1 << (half - 2 - j));
      }
    }
  }
  int rest = n - 1 - half;
  for (int mask = 1; mask < (1 << n); ++mask) {
    int cnt_bits = __builtin_popcount(mask);
    if (cnt_bits != half) {
      continue;
    }
    int rev_mask = (1 << n) - 1 - mask;
    if (n % 2 == 0 && mask > rev_mask) {
      continue;
    }
    for (int last = 0; last < n; ++last) {
      if (dp[last][mask].empty()) {
        continue;
      }
      for (int nex = 0; nex < n; ++nex) {
        if (dp[nex][rev_mask].empty()) {
          continue;
        }
        for (auto& item1 : dp[last][mask]) {
          int rev_1 = reversed_mask[item1.first] + matrix[last][nex] * (1 << (half - 1));
          for (auto& item2 : dp[nex][rev_mask]) {
            //++cnt;
            res[rev_1 + item2.first * (1 << half)] += item1.second * 1LL * item2.second;
          }
        }
      }
    }
  }
  if (n % 2 == 0) {
    for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
      int rev_mask = 0;
      for (int i = 0; i < n - 1; ++i) {
        if (mask & (1 << i)) {
          rev_mask |= (1 << (n - 2 - i));
        }
      }
      if (rev_mask < mask) {
        continue;
      }
      auto val = res[mask] + res[rev_mask];
      res[mask] = val;
      res[rev_mask] = val;
    }
  }

  //cout << "cnt: " << cnt << endl;

  if (read) {
    for (auto x : res) {
      cout << x << " ";
    }
    cout << endl;
  }

}