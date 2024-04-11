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

vector<vector<int>> g, revg;
vector<int> topsort;
vector<char> used;

void dfs1(int v) {
  if (used[v]) {
    return;
  }
  used[v] = true;
  for (int to : g[v]) {
    dfs1(to);
  }
  topsort.push_back(v);
}

vector<int> cur_comp;
vector<int> num_comp;

void dfs2(int v, int n_c) {
  if (used[v]) {
    return;
  }
  used[v] = true;
  num_comp[v] = n_c;
  cur_comp.push_back(v);
  for (int to : revg[v]) {
    dfs2(to, n_c);
  }
}

void solve(__attribute__((unused)) bool read) {
  int n, m, d;
  //read = false;
  if (read) {
    cin >> n >> m >> d;
  } else {
    n = rand() % 10 + 1;
    m = rand() % (3 * n) + 1;
    d = rand() % 20 + 1;

    /*n = 100000;
    m = n - 1;
    d = 50;*/
  }
  g.clear();
  revg.clear();
  topsort.clear();
  used.clear();
  cur_comp.clear();
  num_comp.clear();
  g.resize(n);
  revg.resize(n);
  used.assign(n, false);
  for (int i = 0; i < m; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
      --a;
      --b;
    } else {
      a = rand() % n;
      b = rand() % n;
    }
    g[a].push_back(b);
    revg[b].push_back(a);
  }
  vector<vector<char>> open(n, vector<char>(d));
  for (int i = 0; i < n; ++i) {
    string s;
    if (read) {
      cin >> s;
    } else {
      for (int j = 0; j < d; ++j) {
        if (rand() & 1) {
          s += '1';
        } else {
          s += '0';
        }
      }
    }
    for (int j = 0; j < d; ++j) {
      open[i][j] = (s[j] == '1');
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs1(i);
    }
  }
  used.assign(n, false);
  reverse(all(topsort));
  vector<vector<int>> comps;
  num_comp.assign(n, -1);
  vector<int> into_index(n, -1);
  for (int v : topsort) {
    if (used[v]) {
      continue;
    }
    dfs2(v, comps.size());
    sort(all(cur_comp));
    comps.push_back(cur_comp);
    for (int i = 0; i < cur_comp.size(); ++i) {
      into_index[cur_comp[i]] = i;
    }
    cur_comp.clear();
  }
  vector<vector<int>> scores(comps.size(), vector<int>(d, 0));
  vector<vector<int>> dists(comps.size());

  vector<vector<vector<char>>> lists;
  for (int i = 0; i < comps.size(); ++i) {
    auto& cur_comp = comps[i];
    vector<vector<int>> cur_g(cur_comp.size());
    auto cur_revg = cur_g;
    for (int j = 0; j < cur_comp.size(); ++j) {
      for (int to : g[cur_comp[j]]) {
        if (num_comp[to] != i) {
          continue;
        }
        int b = into_index[to];
        cur_g[j].push_back(b);
        cur_revg[b].push_back(j);
      }
    }
    int root = 0;
    queue<int> q;
    q.push(root);
    dists[i].assign(cur_comp.size(), -1);
    dists[i][root] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int to : cur_revg[v]) {
        if (dists[i][to] == -1) {
          q.push(to);
          dists[i][to] = dists[i][v] + 1;
        }
      }
    }
    queue<pair<int, int>> new_q;
    new_q.push({root, 0});
    vector<vector<char>> is_reach(cur_comp.size(), vector<char>(d, false));
    is_reach[root][0] = true;
    while (!new_q.empty()) {
      auto item = new_q.front();
      new_q.pop();
      int new_d = (item.second + 1) % d;
      for (int to : cur_g[item.first]) {
        if (!is_reach[to][new_d]) {
          is_reach[to][new_d] = true;
          new_q.push({to, new_d});
        }
      }
    }
    for (int start_val = 0; start_val < d; ++start_val) {
      for (int j = 0; j < cur_comp.size(); ++j) {
        bool flag = false;
        for (int new_val = 0; new_val < d; ++new_val) {
          if (is_reach[j][new_val]) {
            int real_d = (start_val + new_val) % d;
            if (open[cur_comp[j]][real_d]) {
              flag = true;
              break;
            }
          }
        }
        if (flag) {
          ++scores[i][start_val];
          //cout << "add " << i << " " << start_val << endl;
        }
      }
    }
    lists.push_back(is_reach);
  }
  const int INF = (int)1e9;
  vector<vector<int>> dp(comps.size(), vector<int>(d, -INF));
  int first = num_comp[0];
  dp[first][0] = 0;
  int ans = 0;
  for (int i = first; i < comps.size(); ++i) {
    for (int val = 0; val < d; ++val) {
      int cur_dp = dp[i][val];
      if (cur_dp < 0) {
        continue;
      }
      cur_dp += scores[i][val];
      relax_max(ans, cur_dp);
      //cout << i << " " << val << " " << cur_dp << endl;
      for (int v : comps[i]) {
        for (int new_val = 0; new_val < d; ++new_val) {
          if (lists[i][into_index[v]][new_val]) {
            for (int to : g[v]) {
              if (num_comp[to] == num_comp[v]) {
                continue;
              }
              int cur_val = (new_val + val) % d;
              ++cur_val;
              cur_val += dists[num_comp[to]][into_index[to]];
              cur_val %= d;
              relax_max(dp[num_comp[to]][cur_val], cur_dp);
            }
          }
        }
      }
    }
  }
  cout << ans << endl;


  /*{
    vector<vector<vector<int>>> dp(1 << n, vector<vector<int>>(d, vector<int>(n, -INF)));
    dp[0][0][0] = 0;
    int stupid = 0;
    while (true) {
      bool relaxed = false;
      for (int mask = 0; mask < (1 << n); ++mask) {
        for (int val = 0; val < d; ++val) {
          for (int last = 0; last < n; ++last) {
            int &cur_dp = dp[mask][val][last];
            if (cur_dp < 0) {
              continue;
            }
            relax_max(stupid, cur_dp);
            if (open[last][val] && !(mask & (1 << last))) {
              if (dp[mask | (1 << last)][val][last] < cur_dp + 1) {
                dp[mask | (1 << last)][val][last] = cur_dp + 1;
                //cout << (mask | (1 << last)) << " " << val << " " << last << " " << cur_dp + 1 << endl;
                relaxed = true;
              }
            } else {
              for (int to : g[last]) {
                if (dp[mask][(val + 1) % d][to] < cur_dp) {
                  dp[mask][(val + 1) % d][to] = cur_dp;
                  //cout << (mask) << " " << (val + 1) % d << " " << to << " " << cur_dp << endl;
                  relaxed = true;
                }
              }
            }
          }
        }
      }
      if (!relaxed) {
        break;
      }
    }
    if (stupid != ans) {
      cout << "FOUND" << endl;
      cout << "ans: " << ans << " stupid: " << stupid << endl;
      cout << n << " " << m << " " << d << endl;
      for (int i = 0; i < n; ++i) {
        make_unique(g[i]);
        for (int to : g[i]) {
          cout << i + 1 << " " << to + 1 << endl;
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
          cout << (bool)(open[i][j]);
        }
        cout << endl;
      }
      exit(0);
    }
  }*/

}