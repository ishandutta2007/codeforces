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

const int C = 256;
int dp[C][C][C];

const int INF = (int)1e9;

void delete_info(int num, vector<vector<int>>& a) {
  if (num == 0) {
    for (int i = 0; i <= a[1].size(); ++i) {
      for (int j = 0; j <= a[2].size(); ++j) {
        dp[a[0].size()][i][j] = INF;
      }
    }
  } else if (num == 1) {
    for (int i = 0; i <= a[0].size(); ++i) {
      for (int j = 0; j <= a[2].size(); ++j) {
        dp[i][a[1].size()][j] = INF;
      }
    }
  } else if (num == 2) {
    for (int i = 0; i <= a[0].size(); ++i) {
      for (int j = 0; j <= a[1].size(); ++j) {
        dp[i][j][a[2].size()] = INF;
      }
    }
  }
  a[num].pop_back();
}

int n;

void update_info(int num, vector<vector<int>>& a, int c, vector<vector<int>>& next_letter) {
  if (num == 0) {
    for (int i = 0; i <= a[1].size(); ++i) {
      for (int j = 0; j <= a[2].size(); ++j) {
        int pos = dp[a[0].size()][i][j];
        int& cur_dp = dp[a[0].size() + 1][i][j];
        if (pos < n) {
          relax_min(cur_dp, next_letter[c][pos] + 1);
        }
        if (cur_dp == INF) {
          continue;
        }
        if (i < a[1].size()) {
          int new_dp = next_letter[a[1][i]][cur_dp] + 1;
          relax_min(dp[a[0].size() + 1][i + 1][j], new_dp);
        }
        if (j < a[2].size()) {
          int new_dp = next_letter[a[2][j]][cur_dp] + 1;
          relax_min(dp[a[0].size() + 1][i][j + 1], new_dp);
        }
      }
    }
  } else if (num == 1) {
    for (int i = 0; i <= a[0].size(); ++i) {
      for (int j = 0; j <= a[2].size(); ++j) {
        int pos = dp[i][a[1].size()][j];
        int& cur_dp = dp[i][a[1].size() + 1][j];
        if (pos < n) {
          relax_min(cur_dp, next_letter[c][pos] + 1);
        }
        if (cur_dp == INF) {
          continue;
        }
        if (i < a[0].size()) {
          int new_dp = next_letter[a[0][i]][cur_dp] + 1;
          relax_min(dp[i + 1][a[1].size() + 1][j], new_dp);
        }
        if (j < a[2].size()) {
          int new_dp = next_letter[a[2][j]][cur_dp] + 1;
          relax_min(dp[i][a[1].size() + 1][j + 1], new_dp);
        }
      }
    }
  } else if (num == 2) {
    for (int i = 0; i <= a[0].size(); ++i) {
      for (int j = 0; j <= a[1].size(); ++j) {
        int pos = dp[i][j][a[2].size()];
        int& cur_dp = dp[i][j][a[2].size() + 1];
        if (pos < n) {
          relax_min(cur_dp, next_letter[c][pos] + 1);
        }
        if (cur_dp == INF) {
          continue;
        }
        if (i < a[0].size()) {
          int new_dp = next_letter[a[0][i]][cur_dp] + 1;
          relax_min(dp[i + 1][j][a[2].size() + 1], new_dp);
        }
        if (j < a[1].size()) {
          int new_dp = next_letter[a[1][j]][cur_dp] + 1;
          relax_min(dp[i][j + 1][a[2].size() + 1], new_dp);
        }
      }
    }
  }
  a[num].push_back(c);
}

void solve(__attribute__((unused)) bool read) {
  int Q;
  //read = false;
  if (read) {
    cin >> n >> Q;
  } else {
    n = 100000;
    Q = 1000;
  }
  string s;
  if (read) {
    cin >> s;
  } else {
    for (int i = 0; i < n; ++i) {
      s += (char)('a' + rand() % 26);
    }
  }
  for (int i = 0; i < C; ++i) {
    for (int j = 0; j < C; ++j) {
      for (int r = 0; r < C; ++r) {
        dp[i][j][r] = INF;
      }
    }
  }
  vector<vector<int>> next_letter(26, vector<int>(n + 1, INF));
  vector<int> next_pos(26, INF);
  for (int i = n - 1; i >= 0; --i) {
    next_pos[s[i] - 'a'] = i;
    for (int c = 0; c < 26; ++c) {
      next_letter[c][i] = next_pos[c];
    }
  }
  dp[0][0][0] = 0;
  vector<vector<int>> a(3);
  while (Q--) {
    char type;
    int num;
    if (read) {
      cin >> type >> num;
      --num;
    } else {
      num = rand() % 3;
      type = '+';
      if (a[num].size() == 250) {
        type = '-';
      }
    }
    if (type == '+') {
      char c;
      if (read) {
        cin >> c;
      } else {
        c = (char)('a' + rand() % 26);
      }
      update_info(num, a, c - 'a', next_letter);
    } else {
      delete_info(num, a);
    }
    if (dp[a[0].size()][a[1].size()][a[2].size()] < INF) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

}