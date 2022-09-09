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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  string moves = "URDL";
  vector<vector<pair<int, int>>> final(n);
  vector<pair<int, int>> roots;
  for (int i = 0; i < n; ++i) {
    final[i].resize(n);
    for (int j = 0; j < n; ++j) {
      cin >> final[i][j].first >> final[i][j].second;
      if (final[i][j].first == -1) {
        continue;
      }
      --final[i][j].first;
      --final[i][j].second;
      if (final[i][j] == make_pair(i, j)) {
        roots.emplace_back(i, j);
      }
    }
  }
  vector<string> res(n);
  for (int i = 0; i < n; ++i) {
    res[i] = string(n, 0);
  }
  for (auto& root : roots) {
    res[root.first][root.second] = 'X';
    queue<pair<int, int>> q;
    q.push(root);
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int x = v.first + dx[dir], y = v.second + dy[dir];
        if (x < n && y < n && x >= 0 && y >= 0 && res[x][y] == 0 && final[x][y] == root) {
          q.push({x, y});
          res[x][y] = moves[(dir + 2) % 4];
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (res[i][j] != 0) {
        continue;
      }
      if (final[i][j] != make_pair(-1, -1)) {
        cout << "INVALID" << endl;
        return;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (res[i][j] != 0) {
        continue;
      }
      if (j + 1 < n && res[i][j + 1] == 0) {
        res[i][j] = 'R';
        res[i][j + 1] = 'L';
        continue;
      }
      if (i + 1 < n && res[i + 1][j] == 0) {
        res[i][j] = 'D';
        res[i + 1][j] = 'U';
        continue;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (res[i][j] != 0) {
        continue;
      }
      bool f = false;
      for (int dir = 0; dir < 4; ++dir) {
        int x = i + dx[dir], y = j + dy[dir];
        if (x < 0 || y < 0 || x >= n || y >= n) {
          continue;
        }
        assert(res[x][y] != 0);
        if (final[x][y] == make_pair(-1, -1)) {
          f = true;
          res[i][j] = moves[dir];
          break;
        }
      }
      if (!f) {
        cout << "INVALID" << endl;
        return;
      }
    }
  }
  cout << "VALID" << endl;
  for (auto s : res) {
    cout << s << "\n";
  }


}