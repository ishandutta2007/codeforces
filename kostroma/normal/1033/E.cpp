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
  //freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
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

int made_queries = 0;

bool READ = true;

using Bitset = bitset<600>;
Bitset g[600];

Bitset empty_set;

int get_response(vector<int> cur) {
  if (cur.size() <= 1) {
    return 0;
  }
  ++made_queries;
  if (READ) {
    cout << "? " << cur.size() << endl;
    for (int x : cur) {
      cout << x + 1 << " ";
    }
    cout << endl;
    int ans;
    cin >> ans;
    if (ans == -1) {
      exit(0);
    }
    return ans;
  } else {
    Bitset cur_set = empty_set;
    for (int x : cur) {
      cur_set[x] = true;
    }
    int ans = 0;
    for (auto x : cur) {
      ans += (g[x] & cur_set).count();
      //cout << "cnt: " << (g[x] & cur_set).count() << endl;
    }
    //cout << "Ans: " << ans << endl;
    assert(ans % 2 == 0);
    return ans / 2;
  }
}

vector<int> get_vector(map<int, int>& colors, int need_col = -1) {
  vector<int> res;
  for (auto item : colors) {
    if (need_col == -1 || need_col == item.second) {
      res.push_back(item.first);
    }
  }
  return res;
}

vector<int> concat(vector<int> q, vector<int> w) {
  vector<int> res = q;
  for (auto x : w) {
    res.push_back(x);
  }
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  for (int i = 0; i < 600; ++i) {
    empty_set[i] = 0;
    for (int j = 0; j < 600; ++j) {
      g[i][j] = 0;
    }
  }
  if (READ) {
    cin >> n;
  } else {
    n = 600;
    for (int i = 0; i < n / 2; ++i) {
      for (int j = n / 2; j < n; ++j) {
        if (rand() & 1) {
          g[i][j] = g[j][i] = true;
        }
      }
    }
    /*for (int i = 0; i < n / 2; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (rand() & 1) {
          g[i][j] = g[j][i] = true;
        }
      }
    }*/
  }
  vector<char> used(n, false);
  vector<int> col(n, -1);
  vector<vector<int>> my_g(n);
  for (int v = 0; v < n; ++v) {
    if (used[v]) {
      continue;
    }
    used[v] = true;
    vector<int> cur_comp;
    cur_comp.push_back(v);
    vector<int> pref_query = {0};
    while (true) {
      int inside_colors = pref_query.back();
      vector<int> rest;
      for (int i = v; i < n; ++i) {
        if (!used[i]) {
          rest.push_back(i);
        }
      }
      int L = -1, R = rest.size();
      while (L + 1 < R) {
        int M = (L + R) / 2;
        vector<int> have;
        for (int i = 0; i <= M; ++i) {
          have.push_back(rest[i]);
        }
        int bet = get_response(concat(have, cur_comp)) - get_response(have) - inside_colors;
        if (bet > 0) {
          R = M;
        } else {
          L = M;
        }
      }
      if (R == rest.size()) {
        break;
      }
      int new_v = rest[R];
      assert(!used[new_v]);
      used[new_v] = true;
      cur_comp.push_back(new_v);
      pref_query.push_back(get_response(cur_comp));
      L = -1, R = cur_comp.size();
      while (L + 1 < R) {
        int M = (L + R) / 2;
        vector<int> cur_query;
        for (int i = 0; i <= M; ++i) {
          cur_query.push_back(cur_comp[i]);
        }
        cur_query.push_back(new_v);
        if (get_response(cur_query) > pref_query[M]) {
          R = M;
        } else {
          L = M;
        }
      }
      assert(R < cur_comp.size());
      int p = cur_comp[R];
      my_g[p].push_back(new_v);
      my_g[new_v].push_back(p);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (col[i] == -1) {
      queue<int> q;
      q.push(i);
      col[i] = 0;
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : my_g[v]) {
          if (col[to] == -1) {
            col[to] = col[v] ^ 1;
            q.push(to);
          }
        }
      }
    }
  }

  vector<int> part[2];
  for (int i = 0; i < n; ++i) {
    part[col[i]].push_back(i);
  }
  for (int c = 0; c < 2; ++c) {
    if (!part[c].empty() && get_response(part[c]) > 0) {
      auto& vec = part[c];
      int L = -1, R = vec.size();
      while (L + 1 < R) {
        int M = (L + R) / 2;
        vector<int> cur_query;
        for (int i = 0; i <= M; ++i) {
          cur_query.push_back(vec[i]);
        }
        if (get_response(cur_query) > 0) {
          R = M;
        } else {
          L = M;
        }
      }
      assert(R != vec.size());
      int rig_end = R;
      L = -1;
      R = rig_end;
      while (L + 1 < R) {
        int M = (L + R) / 2;
        vector<int> cur_query;
        for (int i = M; i <= rig_end; ++i) {
          cur_query.push_back(vec[i]);
        }
        if (get_response(cur_query) > 0) {
          L = M;
        } else {
          R = M;
        }
      }
      assert(L != -1);
      int lef_end = L;

      lef_end = vec[lef_end];
      rig_end = vec[rig_end];

      queue<int> q;
      vector<int> par(n, -1);
      par[lef_end] = lef_end;
      q.push(lef_end);
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : my_g[v]) {
          if (par[to] == -1) {
            par[to] = v;
            q.push(to);
          }
        }
      }
      assert(par[rig_end] != -1);

      vector<int> cycle;
      while (rig_end != lef_end) {
        cycle.push_back(rig_end);
        rig_end = par[rig_end];
      }
      cycle.push_back(lef_end);

      cout << "N " << cycle.size() << endl;
      for (int x : cycle) {
        cout << x + 1 << " ";
      }
      cout << endl;

      return;
    }
  }

  cout << "Y" << " " << part[0].size() << endl;
  for (auto x : part[0]) {
    cout << x + 1 << " ";
  }
  cout << endl;

}