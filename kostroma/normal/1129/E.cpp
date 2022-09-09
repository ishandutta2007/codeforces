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

bool local = true;

vector<vector<int>> g;
vector<vector<set<int>>> bet;
int n;
vector<char> is_leaf;

void generate_tree() {
  n = 500; //rand() % 500 + 1;
  g.clear();
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int p = rand() % i;
    p = i - 1;
    g[p].push_back(i);
    g[i].push_back(p);
  }
  is_leaf.assign(n, false);

  /*n = 5;
  g.clear();
  g.resize(n);
  g[0].push_back(1);
  g[1].push_back(4);
  g[1].push_back(2);
  g[2].push_back(3);
  g[1].push_back(0);
  g[4].push_back(1);
  g[2].push_back(1);
  g[3].push_back(2);*/

  bet.clear();
  bet.resize(n);
  for (int s = 0; s < n; ++s) {
    bet[s].resize(n);
    vector<int> par(n, -1);
    par[s] = s;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int to : g[v]) {
        if (par[to] == -1) {
          par[to] = v;
          q.push(to);
        }
      }
    }
    for (int f = 0; f < n; ++f) {
      int cur = f;
      while (cur != s) {
        bet[s][f].insert(cur);
        cur = par[cur];
      }
      bet[s][f].insert(s);
    }
  }
}

int queries = 0;

int get_ans(vector<int> S, vector<int> T, int v) {
  if (S.empty() || T.empty()) {
    return 0;
  }
  if (is_leaf[v]) {
    for (int x : S) {
      if (v == x) {
        return (int)T.size();
      }
    }
    for (int x : T) {
      if (v == x) {
        return (int)S.size();
      }
    }
    return 0;
  }
  ++queries;
  if (queries > 11111) {
    cerr << "too many queries" << endl;
    exit(0);
  }
  if (local) {
    int res = 0;
    for (int s : S) {
      for (int t : T) {
        if (bet[s][t].count(v)) {
          ++res;
        }
      }
    }
    return res;
  } else {
    cout << S.size() << endl;
    //cout << "S: ";
    for (int x : S) {
      cout << x + 1 << " ";
    }
    cout << endl;
    cout << T.size() << endl;
    //cout << "T: ";
    for (int x : T) {
      cout << x + 1 << " ";
    }
    cout << endl;
    //cout << "v: ";
    cout << v + 1 << endl;
    int res;
    cin >> res;
    return res;
  }
}

void check_ans(vector<pair<int, int>> edges) {
  for (auto& item : edges) {
    if (item.first > item.second) {
      swap(item.first, item.second);
    }
  }
  sort(all(edges));
  if (local) {
    vector<pair<int, int>> correct;
    for (int i = 0; i < n; ++i) {
      for (int to : g[i]) {
        if (to > i) {
          correct.push_back({i, to});
        }
      }
    }
    sort(all(correct));
    cerr << "used " << queries << " queries" << endl;
    if (correct == edges) {
      cout << "ok" << endl;
    } else {
      cout << "wa" << endl;
    }
    return;
  }
  cout << "ANSWER" << endl;
  for (auto item : edges) {
    cout << item.first + 1 << " " << item.second + 1 << endl;
  }
}

vector<pair<int, int>> kill(vector<int> vertices, vector<int> cached_sizes) {
  int n = (int)vertices.size();
  int need_size = (n + 1) / 2;
  int min_size = n;
  int root = vertices[0];
  int center = root;
  vector<int> start_t;
  for (int i = 1; i < vertices.size(); ++i) {
    start_t.push_back(vertices[i]);
  }
  if (cached_sizes.empty()) {
    for (int v : start_t) {
      int cur_size = get_ans({root}, start_t, v);
      if (cur_size == 1) {
        is_leaf[v] = true;
      }
      if (cur_size >= need_size && cur_size < min_size) {
        min_size = cur_size;
        center = v;
      }
    }
  } else {
    for (int i = 1; i < cached_sizes.size(); ++i) {
      int v = vertices[i];
      int cur_size = cached_sizes[i];
      if (cur_size == 1) {
        is_leaf[v] = true;
      }
      if (cur_size >= need_size && cur_size < min_size) {
        min_size = cur_size;
        center = v;
      }
    }
  }
  root = center;

  //cout << "center: " << center << endl;

  vector<int> children;
  vector<int> sizes;
  vector<int> to_position;
  vector<pair<int, int>> res_edges;
  vector<pair<int, int>> cached;
  for (int v : vertices) {
    if (v == root) {
      continue;
    }
    vector<int> rest;
    for (int u : vertices) {
      if (u != v && u != root) {
        rest.push_back(u);
      }
    }
    int cnt = get_ans({root}, rest, v);
    cached.push_back({v, cnt + 1});
    if (cnt + get_ans({v}, rest, root) == n - 2) {
      children.push_back(v);
      sizes.push_back(cnt + 1);
      res_edges.push_back({v, root});
    } else {
      to_position.push_back(v);
    }
  }
  vector<pair<int, int>> to_sort;
  for (int i = 0; i < children.size(); ++i) {
    to_sort.push_back({sizes[i], children[i]});
  }
  sort(to_sort.rbegin(), to_sort.rend());
  for (int i = 0; i < children.size(); ++i) {
    sizes[i] = to_sort[i].first;
    children[i] = to_sort[i].second;
  }

  vector<vector<int>> comps(children.size());
  for (int i = 0; i < children.size(); ++i) {
    comps[i].push_back(children[i]);
  }
  for (int v : to_position) {
    int l = 0, r = children.size();
    auto get_without = [&] (int L, int R) {
      vector<int> S;
      for (int i = 0; i < L; ++i) {
        S.push_back(children[i]);
      }
      for (int i = R; i < children.size(); ++i) {
        S.push_back(children[i]);
      }
      return get_ans(S, {v}, root) == S.size();
    };
    while (l + 1 < r) {
      int sum_sizes = 0;
      for (int i = l; i < r; ++i) {
        sum_sizes += sizes[i];
      }
      int m = l;
      int pref_sizes = 0;
      int best_score = (int)1e9;
      for (int i = l; i < r; ++i) {
        pref_sizes += sizes[i];
        int cur_score = abs(sum_sizes - 2 * pref_sizes);
        if (cur_score < best_score) {
          best_score = cur_score;
          m = i + 1;
        }
      }
      //int m = (l + r) / 2;
      assert(m > l && m < r);
      if (get_without(l, m)) {
        r = m;
      } else {
        l = m;
      }
    }
    comps[l].push_back(v);
    --sizes[l];
  }
  sort(all(cached));
  for (int i = 0; i < comps.size(); ++i) {
    vector<int> new_cached;
    for (int v : comps[i]) {
      auto it = lower_bound(all(cached), make_pair(v, -1));
      assert(it != cached.end() && it->first == v);
      new_cached.push_back(it->second);
    }
    auto new_edges = kill(comps[i], new_cached);
    for (auto item : new_edges) {
      res_edges.push_back(item);
    }
  }
  return res_edges;
}

void solve(__attribute__((unused)) bool read) {
#ifndef AIM
  local = false;
#endif
  if (local) {
    generate_tree();
  } else {
    cin >> n;
    is_leaf.assign(n, false);
  }
  clock_t start = clock();
  vector<int> all_v(n);
  iota(all_v.begin(), all_v.end(), 0);
  auto edges = kill(all_v, {});
  check_ans(edges);
  cerr << "strategy time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << endl;
}