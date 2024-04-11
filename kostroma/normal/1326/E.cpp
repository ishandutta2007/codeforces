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

struct SumSegTree {
  int shift;
  vector<int> tree;
  SumSegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, 0);
  }
  void update(int v, int val) {
    v += shift;
    tree[v] += val;
    v /= 2;
    while (v) {
      tree[v] = tree[2 * v] + tree[2 * v + 1];
      v /= 2;
    }
  }
  int get_sum(int l, int r) {
    l += shift;
    r += shift;
    int res = 0;
    while (l < r) {
      if (l & 1) {
        res += tree[l];
        ++l;
        continue;
      }
      if (r & 1) {
        --r;
        res += tree[r];
        continue;
      }
      l /= 2;
      r /= 2;
    }
    return res;
  }
};

struct Node {
  int min;
  int push_add;
};

Node merge(const Node& q, const Node& w) {
  Node res = {min(q.min, w.min), 0};
  return res;
}

const int INF = (int)1e9;

struct SegTree {
  int shift;
  vector<Node> tree;
  SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, {INF, 0});
  }
  void push(int v) {
    for (int h = 0; h < 2; ++h) {
      auto& child = tree[2 * v + h];
      child.min += tree[v].push_add;
      child.push_add += tree[v].push_add;
    }
    tree[v].push_add = 0;
  }
  void modify_val(int v, int tl, int tr, int pos, int val) {
    if (pos < tl || pos >= tr) {
      return;
    }
    if (tl + 1 == tr) {
      tree[v] = {val, 0};
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    modify_val(2 * v, tl, tm, pos, val);
    modify_val(2 * v + 1, tm, tr, pos, val);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
  }
  void update_val(int pos, int val) {
    return modify_val(1, 0, shift, pos, val);
  }
  void increment(int l, int r, int val) {
    return modify_segment(1, 0, shift, l, r, val);
  }
  void modify_segment(int v, int tl, int tr, int l, int r, int val) {
    if (r <= tl || l >= tr) {
      return;
    }
    if (l <= tl && tr <= r) {
      tree[v].min += val;
      tree[v].push_add += val;
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    modify_segment(2 * v, tl, tm, l, r, val);
    modify_segment(2 * v + 1, tm, tr, l, r, val);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
  }
  int get_min() {
    return tree[1].min;
  }
};

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  vector<int> rev_p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    rev_p[p[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> q[i];
    --q[i];
  }
  vector<int> min_to_eliminate(n);
  int pref = 0;
  SumSegTree sum_tree(n);
  SegTree tree(n);
  vector<int> answers;
  for (int cur_max = n - 1; cur_max >= 0; --cur_max) {
    tree.increment(0, rev_p[cur_max], -1);
    sum_tree.update(rev_p[cur_max], 1);
    int insert_val = -sum_tree.get_sum(rev_p[cur_max], n);
    tree.update_val(rev_p[cur_max], insert_val);
    while (pref < n && tree.get_min() < 0) {
      answers.push_back(cur_max + 1);
      sum_tree.update(q[pref], -1);
      tree.increment(0, q[pref] + 1, 1);
      ++pref;
    }
    min_to_eliminate[cur_max] = pref;
  }
  for (int x : answers) {
    cout << x << " ";
  }
  cout << endl;

}