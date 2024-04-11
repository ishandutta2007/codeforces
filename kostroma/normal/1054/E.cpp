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
//using ull = unsigned long long;

int n, m;

struct Op {
  int x1, y1;
  int x2, y2;
};

struct Matrix {
  vector<vector<string>> matrix;
  vector<vector<int>> nums;
  vector<Op> operations;
  int sum_lens = 0;
  Matrix(int rev) {
    nums.assign(2, vector<int>(m, 0));
    matrix.resize(n);
    for (int i = 0; i < n; ++i) {
      matrix[i].resize(m);
      for (int j = 0; j < m; ++j) {
        cin >> matrix[i][j];
        sum_lens += matrix[i][j].length();
        if (!rev) {
          reverse(all(matrix[i][j]));
        }
        for (char c : matrix[i][j]) {
          int x, y;
          if (c == '0') {
            x = 0;
            y = j;
            if (i == 0) {
              y = (j & 1) ^ 1;
            }
          } else {
            x = 1;
            y = j;
            if (i == 1) {
              y = (j & 1) ^ 1;
            }
          }
          ++nums[c - '0'][y];
          operations.push_back({i, j, x, y});
        }
      }
    }
  }
};

void solve(__attribute__((unused)) bool read) {
  cin >> n >> m;
  vector<Matrix> a;
  for (int i = 0; i < 2; ++i) {
    a.emplace_back(i);
  }
  vector<Op> res = a[0].operations;
  for (int c = 0; c < 2; ++c) {
    vector<vector<int>> vecs(2);
    for (int i = 0; i < 2; ++i) {
      vecs[i] = a[i].nums[c];
    }
    for (int i = 0; i < m; ++i) {
      while (vecs[0][i] > vecs[1][i]) {
        for (int j = 0; j < m; ++j) {
          if (vecs[0][j] < vecs[1][j]) {
            int can = min(vecs[1][j] - vecs[0][j], vecs[0][i] - vecs[1][i]);
            while (can > 0) {
              --can;
              ++vecs[0][j];
              --vecs[0][i];
              res.push_back({c, i, c, j});
            }
            break;
          }
        }
      }
    }
  }
  auto rest = a[1].operations;
  reverse(all(rest));
  for (auto& item : rest) {
    res.push_back({item.x2, item.y2, item.x1, item.y1});
  }

  assert(res.size() <= 4 * a[0].sum_lens);

  cout << res.size() << endl;
  for (auto item : res) {
    cout << item.x1 + 1 << " " << item.y1 + 1 << " " << item.x2 + 1 << " " << item.y2 + 1 << "\n";
  }

  if (false) {
    for (auto item : res) {
      auto& cur_s = a[0].matrix[item.x1][item.y1];
      auto& new_s = a[0].matrix[item.x2][item.y2];
      assert(!cur_s.empty());
      new_s += cur_s[0];
      cur_s.erase(cur_s.begin());
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        reverse(all(a[1].matrix[i][j]));
        //cout << "want: " << a[1].matrix[i][j] << " have: " << a[0].matrix[i][j] << endl;
        assert(a[0].matrix[i][j] == a[1].matrix[i][j]);
      }
    }
  }

}