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

#define int li
//const int mod = 1000000007;

struct Edge {
  int to;
  vector<int> repr;
};

const int INF = (int)1e9;
const int L = 18;

const int C = 100500;
const int mods[] = {1000000007, 1000000009};
const int primes[] = {2017, 2039};

struct Hash {
  int vals[2];
  Hash() {
    memset(vals, 0, sizeof vals);
  }
  Hash append(int val) {
    Hash res;
    for (int i = 0; i < 2; ++i) {
      res.vals[i] = (vals[i] * primes[i] + val) % mods[i];
    }
    return res;
  }
  Hash append(vector<int>& repr, int pos) {
    Hash res;
    for (int i = 0; i < 2; ++i) {
      res.vals[i] = vals[i];
    }
    for (int i = 0; i < pos; ++i) {
      for (int j = 0; j < 2; ++j) {
        res.vals[j] = (res.vals[j] * primes[j] + repr[i]) % mods[j];
      }
    }
    return res;
  }
  bool operator == (const Hash& ot) const {
    return vals[0] == ot.vals[0] && vals[1] == ot.vals[1];
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, m;
  //read = false;
  if (read) {
    cin >> n >> m;
  } else {
    n = 100000;
    m = 100000;
  }
  vector<vector<Edge>> edges(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    if (read) {
      cin >> x >> y;
      --x;
      --y;
    } else {
      x = i % n;
      y = (i + 1) % n;
    }
    int val = i + 1;
    vector<int> cur;
    while (val) {
      cur.push_back(val % 10);
      val /= 10;
    }
    reverse(all(cur));
    edges[x].push_back({y, cur});
    edges[y].push_back({x, cur});
  }
  vector<int> topsort;
  vector<vector<Edge>> g(n);
  vector<int> digit_dist(n, INF);
  {
    digit_dist[0] = 0;
    set<pair<int, int>> have;
    have.insert({0, 0});
    while (!have.empty()) {
      int v = have.begin()->second;
      topsort.push_back(v);
      have.erase(have.begin());
      for (auto& e : edges[v]) {
        int new_dist = digit_dist[v] + (int)e.repr.size();
        if (digit_dist[e.to] > new_dist) {
          have.erase({digit_dist[e.to], e.to});
          digit_dist[e.to] = new_dist;
          have.insert({digit_dist[e.to], e.to});
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (auto& e : edges[i]) {
        if (digit_dist[i] + e.repr.size() == digit_dist[e.to]) {
          g[e.to].push_back({i, e.repr});
        }
      }
    }
  }

  vector<vector<int>> parent(L, vector<int>(n, -1));
  for (int j = 0; j < L; ++j) {
    parent[j][0] = 0;
  }
  vector<vector<int>> preceeding_number(n);
  vector<Hash> prefix_hashes(n);
  prefix_hashes[0] = Hash();
  const int res_mod = 1000000007;
  vector<int> ans(n, 0);

  for (int v : topsort) {
    if (v == 0) {
      continue;
    }
    int best_index = 0;
    int res_len = digit_dist[v];

    auto get_hash = [&] (int index, int len) {
      int p = g[v][index].to;
      if (len > digit_dist[p]) {
        return prefix_hashes[p].append(g[v][index].repr, len - digit_dist[p]);
      }
      for (int j = L - 1; j >= 0; --j) {
        if (digit_dist[parent[j][p]] >= len) {
          p = parent[j][p];
        }
      }
      if (digit_dist[p] == len) {
        return prefix_hashes[p];
      }
      assert(p > 0);
      int prev_vertex = parent[0][p];
      return prefix_hashes[prev_vertex].append(preceeding_number[p], len - digit_dist[prev_vertex]);
    };

    auto get_symbol = [&] (int index, int pos) {
      int p = g[v][index].to;
      if (pos >= digit_dist[p]) {
        return g[v][index].repr[pos - digit_dist[p]];
      }
      for (int j = L - 1; j >= 0; --j) {
        if (digit_dist[parent[j][p]] > pos) {
          p = parent[j][p];
        }
      }
      assert(p > 0);
      int prev_vertex = parent[0][p];
      return preceeding_number[p][pos - digit_dist[prev_vertex]];
    };

    for (int index = 1; index < g[v].size(); ++index) {
      int L = 0, R = res_len;
      while (L + 1 < R) {
        int M = (L + R) / 2;
        if (get_hash(best_index, M) == get_hash(index, M)) {
          L = M;
        } else {
          R = M;
        }
      }
      if (get_symbol(best_index, L) > get_symbol(index, L)) {
        best_index = index;
      }
    }

    int p = g[v][best_index].to;
    parent[0][v] = p;
    for (int j = 1; j < L; ++j) {
      parent[j][v] = parent[j - 1][parent[j - 1][v]];
    }
    preceeding_number[v] = g[v][best_index].repr;
    prefix_hashes[v] = prefix_hashes[p].append(preceeding_number[v], (int)preceeding_number[v].size());

    int cur_res = ans[p];
    for (int val : preceeding_number[v]) {
      cur_res = (cur_res * 10 + val) % res_mod;
    }
    ans[v] = cur_res;
  }

  for (int i = 1; i < n; ++i) {
    cout << ans[i] << "\n";
  }

}