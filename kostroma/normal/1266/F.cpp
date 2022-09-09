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

vector<vector<int>> g;
vector<int> parent;
vector<int> max_down, max_up;

void dfs1(int v, int p) {
  parent[v] = p;
  max_down[v] = 0;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    dfs1(to, v);
    relax_max(max_down[v], max_down[to] + 1);
  }
}

void dfs2(int v, int p, int cur_max) {
  max_up[v] = cur_max;
  vector<pair<int, int>> children;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    children.push_back({max_down[to] + 1, to});
  }
  sort(children.rbegin(), children.rend());
  if (children.size() > 2) {
    children.resize(2);
  }
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    int push_max = cur_max + 1;
    for (auto& item : children) {
      if (item.second == to) {
        continue;
      } else {
        relax_max(push_max, item.first + 1);
        break;
      }
    }
    dfs2(to, v, push_max);
  }
}

void solve(__attribute__((unused)) bool read) {
  int n;
  if (read) {
    cin >> n;
  } else {
    n = rand() % 15 + 2;
  }
  g.clear();
  g.resize(n);
  parent.assign(n, -1);
  max_down.assign(n, 0);
  max_up.assign(n, 0);
  for (int i = 1; i < n; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
      --a;
      --b;
    } else {
      a = i;
      b = rand() % i;
    }
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs1(0, 0);
  dfs2(0, 0, 0);

  vector<int> ans(2 * n + 5, 1);
  vector<vector<int>> prec_lens(n);
  for (int i = 0; i < n; ++i) {
    relax_max(ans[1], (int)g[i].size() + 1);
    vector<int> lens;
    if (max_up[i] > 0) {
      lens.push_back(max_up[i]);
    }
    for (int to : g[i]) {
      if (to == parent[i]) {
        continue;
      }
      lens.push_back(max_down[to] + 1);
    }
    sort(all(lens));
    prec_lens[i] = lens;
    for (int j = 0; j < lens.size(); ++j) {
      int x = lens[j];
      int cnt = (int)lens.size() - j;
      relax_max(ans[2 * x], cnt);
      relax_max(ans[2 * x - 1], cnt);
      if (j + 1 < lens.size() && lens[j + 1] > x) {
        relax_max(ans[2 * x + 1], cnt);
      }
    }
  }
  for (int i = (int)ans.size() - 2; i >= 0; --i) {
    relax_max(ans[i], ans[i + 1]);
  }
  vector<vector<pair<int, int>>> events(n);
  vector<int> new_ans(ans.size(), 0);
  for (int v = 0; v < n; ++v) {
    vector<int> lens;
    int p = parent[v];
    if (v == p) {
      continue;
    }
    for (int to : g[v]) {
      if (parent[to] == v) {
        lens.push_back(max_down[to] + 1);
      }
    }
    sort(all(lens));
    for (int j = 0; j < lens.size(); ++j) {
      int x = lens[j];
      int cnt = (int)lens.size() - j;
      auto it = lower_bound(all(prec_lens[p]), x);
      assert(it != prec_lens[p].end());
      cnt += (int)(prec_lens[p].end() - it) - 1;
      relax_max(new_ans[2 * x], cnt);
      events[p].push_back({x, v});
    }
  }
  int TIMER = 0;
  vector<int> used(n, 0);
  vector<int> score(n, 0);
  for (int v = 0; v < n; ++v) {
    ++TIMER;
    sort(events[v].rbegin(), events[v].rend());
    int max_val = 0;
    auto lens = prec_lens[v];
    reverse(all(lens));
    int uk = 0;
    for (int i = 0; i < lens.size(); ++i) {
      int x = lens[i];
      while (uk < events[v].size() && events[v][uk].first >= x) {
        int to = events[v][uk].second;
        if (used[to] != TIMER) {
          used[to] = TIMER;
          score[to] = 1;
        } else {
          ++score[to];
        }
        relax_max(max_val, score[to]);
        ++uk;
      }
      if (i > 0) {
        relax_max(new_ans[2 * x], max_val + i);
      }
      //cout << "update " << 2 * x << " by " << max_val + i << " max_val: " << max_val << " i: " << i << endl;
    }
  }
  for (int i = (int)new_ans.size() - 3; i >= 0; --i) {
    relax_max(new_ans[i], new_ans[i + 2]);
  }
  for (int i = 1; i <= n; ++i) {
    //cout << new_ans[i] << " ";
    relax_max(ans[i], new_ans[i]);
  }
  //cout << endl;

  if (read) {
    for (int i = 1; i <= n; ++i) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }

  /*{
    const int INF = (int)1e9;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
      dist[i][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      for (int to : g[i]) {
        dist[i][to] = 1;
      }
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          relax_min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    vector<int> stupid(n + 1, 1);
    for (int mask = 1; mask < (1 << n); ++mask) {
      vector<int> vs;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          vs.push_back(i);
        }
      }
      int min_d = INF, max_d = 0;
      for (int v : vs) {
        for (int u : vs) {
          if (u == v) {
            continue;
          }
          //assert(u >= 0 && u < n && v >= 0 && v < n);
          relax_max(max_d, dist[u][v]);
          relax_min(min_d, dist[u][v]);
        }
      }
      if (min_d > max_d) {
        continue;
      }
      if (max_d > min_d + 1) {
        continue;
      }
      assert(min_d > 0);
      //cout << min_d << " " << max_d << " " << n << endl;
      relax_max(stupid[min_d], (int)vs.size());
      if (min_d == max_d) {
        relax_max(stupid[min_d - 1], (int)vs.size());
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (ans[i] != stupid[i]) {
        cout << "i: " << i << " ans: " << ans[i] << " stupid: " << stupid[i] << endl;
        cout << n << endl;
        for (int v = 0; v < n; ++v) {
          for (int to : g[v]) {
            if (to > v) {
              cout << v + 1 << " " << to + 1 << endl;
            }
          }
        }
        exit(0);
      }
    }
    cout << "ok\n";
  }*/

}