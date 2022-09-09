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

vector<vector<int>> transp(vector<vector<int>> matrix) {
  vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size()));
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      res[j][i] = matrix[i][j];
    }
  }
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
    }
  }
  vector<vector<int>> max_before(n, vector<int>(m)), max_after(n, vector<int>(m));
  for (int w = 0; w < 2; ++w) {
    for (int i = 0; i < n; ++i) {
      vector<int> cur_pos(m, 0);
      vector<pair<int, int>> vec;
      for (int j = 0; j < m; ++j) {
        vec.push_back({matrix[i][j], j});
      }
      sort(all(vec));
      int cnt = 0;
      for (int j = 0; j < vec.size(); ) {
        int r = j;
        while (r < vec.size() && vec[r].first == vec[j].first) {
          ++r;
        }
        for (int z = j; z < r; ++z) {
          cur_pos[vec[z].second] = cnt;
        }
        j = r;
        ++cnt;
      }
      for (int j = 0; j < m; ++j) {
        int a = i, b = j;
        if (w) {
          swap(a, b);
        }
        relax_max(max_before[a][b], cur_pos[j]);
        relax_max(max_after[a][b], cnt - 1 - cur_pos[j]);
      }
    }
    matrix = transp(matrix);
    swap(n, m);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << max_before[i][j] + max_after[i][j] + 1 << " \n"[j + 1 == m];
    }
  }
}