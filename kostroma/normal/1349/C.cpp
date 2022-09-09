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

using Matrix = vector<vector<int>>;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve(__attribute__((unused)) bool read) {
  int n, m;
  int T;
  //read = false;
  if (read) {
    cin >> n >> m >> T;
  } else {
    n = rand() % 10 + 1;
    m = rand() % 10 + 1;
    T = rand() % 100 + 1;
  }
  Matrix matrix(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    string s;
    if (read) {
      cin >> s;
    }
    for (int j = 0; j < m; ++j) {
      if (read) {
        matrix[i][j] = s[j] - '0';
      } else {
        matrix[i][j] = rand() % 2;
      }
    }
  }

  vector<vector<int>> dist(n, vector<int>(m, -1));
  queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      bool found = false;
      for (int d = 0; d < 4; ++d) {
        int x = i + dx[d], y = j + dy[d];
        if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] == matrix[i][j]) {
          found = true;
          break;
        }
      }
      if (found) {
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    auto item = q.front();
    q.pop();
    int i = item.first, j = item.second;
    for (int d = 0; d < 4; ++d) {
      int x = i + dx[d], y = j + dy[d];
      if (x >= 0 && y >= 0 && x < n && y < m && dist[x][y] == -1) {
        dist[x][y] = dist[i][j] + 1;
        q.push({x, y});
      }
    }
  }
  while (T--) {
    int x, y;
    li p;
    cin >> x >> y >> p;
    --x; --y;
    if (dist[x][y] == -1 || p < dist[x][y]) {
      cout << matrix[x][y] << "\n";
      continue;
    }
    int res = (((p - dist[x][y]) % 2) ^ matrix[x][y]);
    cout << res << "\n";
  }


}