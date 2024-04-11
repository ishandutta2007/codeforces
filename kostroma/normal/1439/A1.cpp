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

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      matrix[i][j] = s[j] - '0';
    }
  }
  vector<vector<pair<int, int>>> ops;

  auto add_op = [&] (vector<pair<int, int>> vec) {
    assert(vec.size() == 3);
    ops.push_back(vec);
    for (auto item : vec) {
      matrix[item.first][item.second] ^= 1;
    }
  };

  for (int i = n - 1; i >= 2; --i) {
    for (int j = 0; j < m; ++j) {
      if (matrix[i][j]) {
        add_op({{i, j}, {i - 1, j}, {i - 1, (j == 0) ? (j + 1) : (j - 1)}});
      }
    }
    for (int j = 0; j < m; ++j) {
      assert(matrix[i][j] == 0);
    }
    matrix.pop_back();
  }
  n = matrix.size();
  for (int j = m - 1; j >= 2; --j) {
    for (int i = 0; i < n; ++i) {
      if (matrix[i][j]) {
        add_op({{i, j}, {i, j - 1}, {(i == 0) ? (i + 1) : (i - 1), j - 1}});
      }
    }
    for (int i = 0; i < n; ++i) {
      assert(matrix[i][j] == 0);
      matrix[i].pop_back();
    }
  }
  assert(matrix.size() == 2);
  assert(matrix[0].size() == 2);

  bool found = false;
  for (int m1 = 0; m1 < 4 && !found; ++m1) {
    for (int m2 = 0; m2 < 4; ++m2) {
      vector<pair<int, int>> centers;
      for (int i = 0; i < 2; ++i) {
        if (m1 & (1 << i)) {
          centers.push_back({0, i});
        }
        if (m2 & (1 << i)) {
          centers.push_back({1, i});
        }
      }
      auto new_matrix = matrix;
      for (auto item : centers) {
        for (int i = 0; i < 2; ++i) {
          for (int j = 0; j < 2; ++j) {
            if (item.first == i && item.second == j) {
              continue;
            }
            new_matrix[i][j] ^= 1;
          }
        }
      }
      if (new_matrix[0] == vector<int>{0, 0} && new_matrix[1] == vector<int>{0, 0}) {
        for (auto item : centers) {
          vector<pair<int, int>> vec;
          for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
              if (item.first == i && item.second == j) {
                continue;
              }
              vec.push_back({i, j});
            }
          }
          add_op(vec);
        }
        found = true;
        break;
      }
    }
  }

  assert(found);
  assert(matrix[0] == vector<int>(2, 0));
  assert(matrix[1] == vector<int>(2, 0));

  cout << ops.size() << "\n";
  for (auto vec : ops) {
    for (auto item : vec) {
      cout << item.first + 1 << " " << item.second + 1 << " ";
    }
    cout << "\n";
  }

}