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

struct Edge {
  int from, to, cap, flow;
};

const int INF = (int)2e9;

struct Dinic {
  int n;
  vector<Edge> edges;
  vector<vector<int>> g;

  Dinic(int n) : n(n) {
    g.resize(n);
  }

  void add_edge(int from, int to, int cap) {
    Edge e = {from, to, cap, 0};
    g[from].push_back(edges.size());
    edges.push_back(e);
    e = {to, from, 0, 0};
    g[to].push_back(edges.size());
    edges.push_back(e);
  }

  vector<int> d;

  bool bfs(int s, int t) {
    d.assign(n, INF);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto id : g[v]) {
        auto e = edges[id];
        if (e.cap > e.flow && d[e.to] == INF) {
          d[e.to] = d[v] + 1;
          q.push(e.to);
        }
      }
    }
    return d[t] != INF;
  }

  vector<int> pointer;

  int dfs(int v, int t, int flow_add) {
    if (!flow_add) {
      return 0;
    }
    if (v == t) {
      return flow_add;
    }
    int added_flow = 0;
    for (int& i = pointer[v]; i < g[v].size(); ++i) {
      int id = g[v][i];
      int to = edges[id].to;
      if (d[to] != d[v] + 1) {
        continue;
      }
      int pushed = dfs(to, t, min(flow_add, edges[id].cap - edges[id].flow));
      if (pushed) {
        edges[id].flow += pushed;
        edges[id ^ 1].flow -= pushed;
        return pushed;
      }
    }
    return 0;
  }

  int max_flow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
      pointer.assign(n, 0);
      while (int pushed = dfs(s, t, INF)) {
        flow += pushed;
      }
    }
    return flow;
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, h, m;
  cin >> n >> h >> m;
  int S = h * n + m;
  int T = S + 1;
  Dinic dinic(T + 1);
  const int MY_INF = (int)1e7;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < h; ++j) {
      dinic.add_edge(S, i * h + j, 2 * j + 1);
      if (j > 0) {
        dinic.add_edge(i * h + j, i * h + j - 1, MY_INF);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    int l, r, x, c;
    cin >> l >> r >> x >> c;
    if (x >= h) {
      continue;
    }
    --l;
    for (int j = l; j < r; ++j) {
      dinic.add_edge(j * h + x, h * n + i, MY_INF);
    }
    dinic.add_edge(h * n + i, T, c);
  }
  int res = h * h * n - dinic.max_flow(S, T);
  cout << res << endl;
}