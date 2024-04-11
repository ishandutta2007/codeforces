#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
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
  start = clock();
  int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
//cin  t;
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

void precalc() {

}

//#define int li
//const li mod = 1000000007;

//using ull = unsigned long long;

struct SegTree {
  int shift;
  vector<int> tree;
  vector<int> xs;
  void build() {
    make_unique(xs);
    shift = 1;
    while (shift < xs.size()) {
      shift *= 2;
    }
    tree.assign(2 * shift, 0);
  }
  int get_lower_bound(int coord) {
    return lower_bound(all(xs), coord) - xs.begin();
  }
  int get_sum(int l, int r) {
    l = get_lower_bound(l);
    r = get_lower_bound(r);
    l += shift;
    r += shift;
    int res = 0;
    while (l < r) {
      if (l & 1) {
        res += tree[l++];
        continue;
      }
      if (r & 1) {
        res += tree[--r];
        continue;
      }
      l /= 2;
      r /= 2;
    }
    return res;
  }
  void update(int x, int val) {
    int v = get_lower_bound(x);
    assert(xs[v] == x);
    v += shift;
    while (v) {
      tree[v] += val;
      v /= 2;
    }
  }
};

struct LargeTree {
  int shift;
  vector<SegTree> trees;
  LargeTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    trees.resize(2 * shift);
  }
  void build() {
    for (int i = 0; i < trees.size(); ++i) {
      trees[i].build();
    }
  }
  void raw_insert(int x, int y) {
    x += shift;
    while (x) {
      trees[x].xs.push_back(y);
      x /= 2;
    }
  }
  void insert(int x, int y) {
    x += shift;
    while (x) {
      trees[x].update(y, 1);
      x /= 2;
    }
  }
  int count(int lx, int rx, int ly, int ry) {
    lx += shift;
    rx += shift;
    int res = 0;
    while (lx < rx) {
      if (lx & 1) {
        res += trees[lx++].get_sum(ly, ry);
        continue;
      }
      if (rx & 1) {
        res += trees[--rx].get_sum(ly, ry);
        continue;
      }
      lx /= 2;
      rx /= 2;
    }
    return res;
  }
};

const int C = 100500;

struct Query {
  int z;
  int lx, rx;
  int ly, ry;
  int sign;
  int id;
};

int pidorand() {
  return (rand() << 16) | rand();
}

#ifndef AIM
#define rand pidorand
#endif

void solve(bool read) {
  //read = false;
  LargeTree tree(C);
  vector<int> borders(3);
  for (int i = 0; i < 3; ++i) {
    if (read) {
      cin >> borders[i];
    } else {
      borders[i] = 100000;
    }
  }
  int n, m, k;
  if (read) {
    cin >> n >> m >> k;
  } else {
    n = 1;
    m = 100000;
    k = 100000;
  }
  vector<int> mins(3, C), maxes(3, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      int cur;
      if (read) {
        cin >> cur;
      } else {
        cur = rand() % borders[j] + 1;
      }
      relax_min(mins[j], cur);
      relax_max(maxes[j], cur);
    }
  }
  auto is_into = [&] (const vector<int>& cur) {
    for (int i = 0; i < 3; ++i) {
      if (cur[i] < mins[i] || cur[i] > maxes[i]) {
        return false;
      }
    }
    return true;
  };

  vector<vector<vector<int>>> not_visited(C);
  for (int i = 0; i < m; ++i) {
    vector<int> cur(3);
    for (int j = 0; j < 3; ++j) {
      if (read) {
        cin >> cur[j];
      } else {
        cur[j] = rand() % borders[j] + 1;
      }
    }
    if (is_into(cur)) {
      cout << "INCORRECT\n";
      return;
    }
    not_visited[cur[2]].push_back({cur[0], cur[1]});
    tree.raw_insert(cur[0], cur[1]);
  }
  tree.build();

  cout << "CORRECT\n";

  vector<int> res(k, 0);
  vector<bool> is_inside(k, false);
  vector<vector<Query>> queries(C);
  for (int i = 0; i < k; ++i) {
    auto cur_mins = mins;
    auto cur_maxes = maxes;
    vector<int> cur(3);
    for (int j = 0; j < 3; ++j) {
      if (read) {
        cin >> cur[j];
      } else {
        cur[j] = rand() % borders[j] + 1;
      }
      relax_min(cur_mins[j], cur[j]);
      relax_max(cur_maxes[j], cur[j]);
    }
    if (is_into(cur)) {
      is_inside[i] = true;
      continue;
    }
    Query cur_q = {cur_maxes[2], cur_mins[0], cur_maxes[0] + 1, cur_mins[1], cur_maxes[1] + 1, 1, i};
    queries[cur_q.z].push_back(cur_q);
    cur_q.z = cur_mins[2] - 1;
    cur_q.sign = -1;
    if (cur_q.z >= 0) {
      queries[cur_q.z].push_back(cur_q);
    }
  }

  for (int z = 0; z < C; ++z) {
    for (auto& vec : not_visited[z]) {
      tree.insert(vec[0], vec[1]);
    }
    for (auto& q : queries[z]) {
      res[q.id] += q.sign * tree.count(q.lx, q.rx, q.ly, q.ry);
    }
  }

  for (int i = 0; i < k; ++i) {
    if (is_inside[i]) {
      cout << "OPEN\n";
      continue;
    }
    if (res[i] > 0) {
      cout << "CLOSED\n";
      continue;
    }
    cout << "UNKNOWN\n";
  }

}