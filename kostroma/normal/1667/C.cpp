#pragma comment(linker, "/STACK:512000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <memory>
#include <chrono>
#include <cassert>
#include <random>
#include <queue>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <sstream>
#ifdef PINELY
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
#ifdef PINELY
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;

#ifdef PINELY
  const rlim_t kStackSize = 60 * 1024 * 1024;   // min stack size = 16 MB
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
#ifndef PINELY
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    cout.precision(20);
    cout << fixed;
    //cin >> t;
    precalc();
    int test_num = 1;
    while (t--) {
      //cout << "Case #" << test_num++ << ": ";
      solve(true);
    }
    cout.flush();

#ifdef PINELY1
    while (true) {
    solve(false);
  }
#endif

#ifdef PINELY
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

template<typename T>
void print_vec(const vector<T>& vals) {
  for (int x : vals) {
    cout << x << " ";
  }
  cout << endl;
}

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

void precalc() {

}

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

vector<vector<bool>> matrix;

vector<pair<int, int>> cur_res;
vector<pair<int, int>> best_res;

void rec(int cur_x, int cur_y) {
  int n = matrix.size();
  bool f = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!matrix[i][j]) {
        f = true;
        break;
      }
    }
  }
  if (!f) {
    if (best_res.empty() || best_res.size() > cur_res.size()) {
      best_res = cur_res;
    }
    //cout << "found " << cur_res.size() << endl;
    return;
  }
  if (!best_res.empty() && cur_res.size() + 1 >= best_res.size()) {
    return;
  }
  if (cur_x == n) {
    return;
  }
  for (int ii = cur_x; ii < n; ++ii) {
    for (int jj = (ii == cur_x ? cur_y + 1 : 0); jj < n; ++jj) {
      /*if (matrix[ii][jj]) {
        continue;
      }*/
      pair<int, int> item = {ii, jj};
      auto old_matrix = matrix;
      for (int i = 0; i < n; ++i) {
        matrix[item.first][i] = matrix[i][item.second] = true;
      }
      for (int i = -n; i <= n; ++i) {
        int x = item.first + i, y = item.second + i;
        if (x >= 0 && y >= 0 && x < n && y < n) {
          matrix[x][y] = true;
        }
      }
      cur_res.push_back(item);
      rec(ii, jj);
      cur_res.pop_back();
      matrix = old_matrix;
    }
  }
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  /*matrix.assign(n, vector<bool>(n, false));
  rec(0, -1);
  cout << best_res.size() << " " << (2 * n + 1) / 3 << endl;
  for (auto item : best_res) {
    cout << item.first << " " << item.second << endl;
  }
  return;*/

  int ans = (2 * n + 1) / 3;
  vector<pair<int, int>> res;
  res.emplace_back(0, 0);
  pair<int, int> last(0, 0);
  int rest = ans - 1;
  int max_cnt = (ans + 1) / 2 - 1;
  while (rest > 0) {
    --max_cnt;
    if (max_cnt < 0) {
      break;
    }
    if (last.second + 2 >= n - 1) {
      break;
    }
    --rest;
    res.emplace_back(last.first + 1, last.second + 2);
    last = res.back();
  }
  if (rest > 0) {
    res.emplace_back(last.first + 1, 1);
    --rest;
    last = res.back();
    while (rest > 0) {
      --rest;
      res.emplace_back(last.first + 1, last.second + 2);
      last = res.back();
    }
  }
  assert(res.size() == ans);

  cout << res.size() << "\n";
  for (auto item : res) {
    cout << item.first + 1 << " " << item.second + 1 << "\n";
  }

  if (false) {
    vector<vector<bool>> matrix(n, vector<bool>(n, false));
    for (auto& item : res) {
      for (int i = 0; i < n; ++i) {
        matrix[item.first][i] = matrix[i][item.second] = true;
      }
      for (int i = -n; i <= n; ++i) {
        int x = item.first + i, y = item.second + i;
        if (x >= 0 && y >= 0 && x < n && y < n) {
          matrix[x][y] = true;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!matrix[i][j]) {
          cout << "bad " << i << " " << j << endl;
        }
      }
    }
  }
}