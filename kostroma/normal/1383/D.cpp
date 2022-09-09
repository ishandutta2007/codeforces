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

vector<vector<int>> g;
vector<int> order;
vector<char> used;

void dfs(int v) {
  if (used[v]) {
    return;
  }
  used[v] = true;
  for (int to : g[v]) {
    dfs(to);
  }
  order.push_back(v);
}

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<int> row_max(n), col_max(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      --a[i][j];
      relax_max(row_max[i], a[i][j]);
      relax_max(col_max[j], a[i][j]);
    }
  }
  vector<int> max_mask(n * m, 0);
  for (int i = 0; i < n; ++i) {
    max_mask[row_max[i]] |= 1;
  }
  for (int i = 0; i < m; ++i) {
    max_mask[col_max[i]] |= 2;
  }
  vector<int> row_max_index(n), col_max_index(m);
  vector<vector<int>> res(n, vector<int>(m, -1));
  int x = n - 1, y = m - 1;
  vector<int> free_vals;
  for (int val = n * m - 1; val >= 0; ) {
    if (max_mask[val] == 3) {
      row_max_index[x] = y;
      col_max_index[y] = x;
      res[x][y] = val;
      --val;
      int cur_x = x - 1, cur_y = y - 1;
      while (val >= 0 && max_mask[val] != 3) {
        if (max_mask[val] == 1) {
          assert(cur_x >= 0);
          res[cur_x][y] = val;
          row_max_index[cur_x] = y;
          --cur_x;
        } else if (max_mask[val] == 2) {
          assert(cur_y >= 0);
          res[x][cur_y] = val;
          col_max_index[cur_y] = x;
          --cur_y;
        } else {
          free_vals.push_back(val);
        }
        --val;
      }
      x = cur_x;
      y = cur_y;
    }
  }
  //cerr << "x: " << x << " y: " << y << endl;

  g.clear();
  g.resize(n * m);
  auto get_num = [&] (int x, int y) {
    return x * m + y;
  };
  auto add_edge = [&] (int from_x, int from_y, int to_x, int to_y) {
    /*if (res[from_x][from_y] != -1 || res[to_x][to_y] != -1) {
      return;
    }*/
    //cerr << "edge " << from_x << " " << from_y << " to " << to_x << " " << to_y << endl;
    g[get_num(from_x, from_y)].push_back(get_num(to_x, to_y));
  };
  for (int i = 0; i < n; ++i) {
    int max_index = row_max_index[i];
    for (int j = max_index + 1; j < m; ++j) {
      add_edge(i, j - 1, i, j);
    }
    for (int j = max_index - 1; j >= 0; --j) {
      add_edge(i, j + 1, i, j);
    }
  }
  for (int i = 0; i < m; ++i) {
    int max_index = col_max_index[i];
    for (int j = max_index + 1; j < n; ++j) {
      add_edge(j - 1, i, j, i);
    }
    for (int j = max_index - 1; j >= 0; --j) {
      add_edge(j + 1, i, j, i);
    }
  }
  used.assign(n * m, false);
  for (int i = 0; i < n * m; ++i) {
    dfs(i);
  }
  sort(all(free_vals));
  reverse(all(free_vals));
  for (int key : order) {
    int x = key / m, y = key % m;
    if (res[x][y] != -1) {
      continue;
    }
    res[x][y] = free_vals.back();
    free_vals.pop_back();
  }
  for (auto& vec : res) {
    for (int x : vec) {
      cout << x + 1 << " ";
    }
    cout << "\n";
  }
}