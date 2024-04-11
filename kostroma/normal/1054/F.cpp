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

vector<vector<int>> g;
vector<int> used;
int TIMER = 1;
vector<int> mt;

bool dfs(int v) {
  if (used[v] == TIMER) {
    return false;
  }
  used[v] = TIMER;
  for (int to : g[v]) {
    if (mt[to] == -1) {
      mt[to] = v;
      return true;
    }
  }
  for (int to : g[v]) {
    if (dfs(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

vector<char> in_right, in_left;

void dfs_set(int v) {
  for (int to : g[v]) {
    if (in_right[to]) {
      in_right[to] = false;
      assert(mt[to] != -1);
      in_left[mt[to]] = true;
      dfs_set(mt[to]);
    }
  }
}

void solve(__attribute__((unused)) bool read) {
  g.clear();
  used.clear();
  mt.clear();
  in_left.clear();
  in_right.clear();
  //read = false;
  int MAX_COORD = (int)1e5;
  TIMER = 1;
  int N;
  if (read) {
    cin >> N;
  } else {
    N = 1000;
  }
  vector<vector<int>> coords(2);
  vector<vector<int>> pts(N);
  set<vector<int>> have;
  for (int i = 0; i < N; ++i) {
    auto& cur_pt = pts[i];
    cur_pt.resize(2);
    if (read) {
      for (int j = 0; j < 2; ++j) {
        cin >> cur_pt[j];
      }
    } else {
      do {
        for (int j = 0; j < 2; ++j) {
          cur_pt[j] = rand() % MAX_COORD + 1;
        }
      } while (have.count(cur_pt));
      have.insert(cur_pt);

      //cout << "new_point: " << cur_pt[0] << " " << cur_pt[1] << endl;

    }
    for (int j = 0; j < 2; ++j) {
      coords[j].push_back(cur_pt[j]);
    }
  }
  for (int i = 0; i < 2; ++i) {
    make_unique(coords[i]);
  }
  int n = coords[0].size(), m = coords[1].size();
  vector<vector<int>> matrix(n, vector<int>(m));
  for (auto& pt : pts) {
    for (int j = 0; j < 2; ++j) {
      pt[j] = lower_bound(all(coords[j]), pt[j]) - coords[j].begin();
    }
    matrix[pt[0]][pt[1]] = 1;
  }
  vector<vector<int>> down_vs = matrix;
  vector<vector<int>> up_vs = matrix;
  for (int j = 0; j < m; ++j) {
    for (int i = n - 2; i >= 0; --i) {
      down_vs[i][j] += down_vs[i + 1][j];
    }
    for (int i = 1; i < n; ++i) {
      up_vs[i][j] += up_vs[i - 1][j];
    }
  }
  vector<vector<vector<int>>> vertices(2);

  vector<vector<vector<int>>> answers(2);
  for (int i = 0; i < 2; ++i) {
    answers[i].resize(coords[i].size());
  }

  vector<int> cur_vertex(m, -1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (matrix[i][j]) {
        cur_vertex[j] = -1;
        answers[0][i].push_back(j);
        answers[1][j].push_back(i);
      } else {
        if (cur_vertex[j] != -1) {
          vertices[1][cur_vertex[j]].back() = i;
        } else if (up_vs[i][j] > 0 && down_vs[i][j] > 0) {
          cur_vertex[j] = vertices[1].size();
          vertices[1].push_back({j, i, i});
        }
      }
    }
    int cnt = 0;
    for (int j = 0; j < m; ++j) {
      if (matrix[i][j]) {
        ++cnt;
        continue;
      }
      if (cnt == 0) {
        continue;
      }
      int r = j;
      while (r < m && matrix[i][r] == 0) {
        ++r;
      }
      if (r == m) {
        continue;
      }
      vertices[0].push_back({i, j, r - 1});
      g.push_back({});
      for (int z = j; z < r; ++z) {
        if (cur_vertex[z] != -1) {
          g.back().push_back(cur_vertex[z]);
        }
      }
      j = r - 1;
    }
  }
  mt.assign(vertices[1].size(), -1);
  used.assign(vertices[0].size(), 0);
  int matching = 0;
  for (int i = 0; i < vertices[0].size(); ++i) {
    if (dfs(i)) {
      ++TIMER;
      ++matching;
    }
  }
  vector<bool> in_match(vertices[0].size(), false);
  for (auto x : mt) {
    if (x != -1) {
      in_match[x] = true;
    }
  }
  in_left.assign(vertices[0].size(), true);
  in_right.assign(vertices[1].size(), true);
  for (int i = 0; i < vertices[0].size(); ++i) {
    if (in_match[i]) {
      in_left[i] = false;
    }
  }
  for (int i = 0; i < vertices[0].size(); ++i) {
    if (!in_match[i]) {
      dfs_set(i);
    }
  }

  int cnt_ans = 0;
  for (int i = 0; i < vertices[0].size(); ++i) {
    if (in_left[i]) {
      ++cnt_ans;
    }
  }
  for (int i = 0; i < vertices[1].size(); ++i) {
    if (in_right[i]) {
      ++cnt_ans;
    }
  }

  assert(cnt_ans + matching == vertices[0].size() + vertices[1].size());

  for (int i = 0; i < vertices[0].size(); ++i) {
    if (in_left[i]) {
      for (int to : g[i]) {
        assert(!in_right[to]);
      }
    }
  }

  for (int w = 0; w < 2; ++w) {
    auto& vs = vertices[w];
    auto& in_par = (w == 0 ? in_left : in_right);
    for (int i = 0; i < vs.size(); ++i) {
      if (in_par[i]) {
        int x = vs[i][0];
        for (int y = vs[i][1]; y <= vs[i][2]; ++y) {
          answers[w][x].push_back(y);
        }
      }
    }
  }
  vector<vector<vector<int>>> results(2);
  for (int w = 0; w < 2; ++w) {
    for (int i = 0; i < coords[w].size(); ++i) {
      auto& vec = answers[w][i];
      sort(all(vec));
      for (int j = 0; j < vec.size(); ++j) {
        int r = j;
        while (r + 1 < vec.size() && vec[r + 1] == vec[r] + 1) {
          ++r;
        }
        //cout << "Adding " << w << " " << coords[w][i] << " " << coords[w ^ 1][vec[j]] << " " << coords[w ^ 1][vec[r]] << endl;
        results[w].push_back({coords[w][i], coords[w ^ 1][vec[j]], coords[w ^ 1][vec[r]]});
        j = r;
      }
    }
  }

  if (read) {
    for (int ww = 0; ww < 2; ++ww) {
      int w = ww ^ 1;
      cout << results[w].size() << "\n";
      for (auto& vec : results[w]) {
        if (w == 0) {
          cout << vec[0] << " " << vec[1] << " " << vec[0] << " " << vec[2] << "\n";
        } else {
          cout << vec[1] << " " << vec[0] << " " << vec[2] << " " << vec[0] << "\n";
        }
      }
    }
  } else {
    cout << "ok\n";
  }

}