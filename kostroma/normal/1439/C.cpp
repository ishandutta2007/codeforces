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

#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

struct Node {
  int min, max, cnt, sum;
  int push_set = -1;
};

Node merge(const Node& l, const Node& r) {
  Node res;
  res.push_set = -1;
  res.min = r.min;
  res.max = l.max;
  res.cnt = l.cnt + r.cnt;
  res.sum = l.sum + r.sum;
  return res;
}

struct SegTree {
  int n;
  int shift;
  vector<Node> tree;
  SegTree(vector<int>& a) {
    shift = 1;
    n = a.size();
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, Node());
    for (int i = 0; i < n; ++i) {
      tree[i + shift] = {a[i], a[i], 1, a[i]};
    }
    for (int i = shift - 1; i >= 0; --i) {
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
  }

  void push(int v) {
    if (tree[v].push_set == -1) {
      return;
    }
    for (int h = 0; h < 2; ++h) {
      recalc(2 * v + h, tree[v].push_set);
    }
    tree[v].push_set = -1;
  }

  void recalc(int v, int pushed) {
    tree[v].push_set = tree[v].min = tree[v].max = pushed;
    tree[v].sum = tree[v].min * tree[v].cnt;
  }

  void decent_update(int v, int val) {
    if (tree[v].min >= val) {
      return;
    }
    if (tree[v].max <= val) {
      recalc(v, val);
      return;
    }
    push(v);
    decent_update(2 * v, val);
    decent_update(2 * v + 1, val);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
  }

  void modify(int v, int tl, int tr, int l, int r, int val) {
    if (r <= tl || tr <= l) {
      return;
    }
    if (l <= tl && tr <= r) {
      return decent_update(v, val);
    }
    push(v);
    int tm = (tl + tr) / 2;
    modify(2 * v, tl, tm, l, r, val);
    modify(2 * v + 1, tm, tr, l, r, val);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
  }

  void update(int x, int val) {
    return modify(1, 0, shift, 0, x, val);
  }

  int rsq(int v, int tl, int tr, int l, int r) {
    if (r <= tl || tr <= l) {
      return 0;
    }
    if (l <= tl && tr <= r) {
      return tree[v].sum;
    }
    push(v);
    int tm = (tl + tr) / 2;
    return rsq(2 * v, tl, tm, l, r) + rsq(2 * v + 1, tm, tr, l, r);
  }

  int get_sum(int l, int r) {
    return rsq(1, 0, shift, l, r);
  }

  int get_last(int money) {
    int v = 1;
    if (money >= tree[v].sum) {
      return n;
    }
    while (v < shift) {
      push(v);
      if (tree[2 * v].sum <= money) {
        money -= tree[2 * v].sum;
        v = 2 * v + 1;
      } else {
        v = 2 * v;
      }
    }
    return v - shift;
  }

  int get_next(int money) {
    int v = 1;
    if (tree[v].min > money) {
      return n;
    }
    while (v < shift) {
      push(v);
      if (tree[2 * v].min <= money) {
        v = 2 * v;
      } else {
        v = 2 * v + 1;
      }
    }
    return v - shift;
  }

};

void solve(__attribute__((unused)) bool read) {
  int n, Q;
  //read = false;
  if (read) {
    cin >> n >> Q;
  } else {
    n = 20;
    Q = 10;
    n = 200000;
    Q = 200000;
  }
  vector<int> a(n);
  for (int& x : a) {
    if (read) {
      cin >> x;
    } else {
      x = rand() % (int)1e9 + 1;
    }
  }
  if (!read) {
    sort(all(a));
  }
  SegTree tree(a);
  while (Q--) {
    int type, x, y;
    if (read) {
      cin >> type >> x >> y;
    } else {
      type = 1 + rand() % 2;
      x = rand() % n + 1;
      y = rand() % (int)1e9 + 1;
    }
    if (type == 1) {
      tree.update(x, y);
    } else {
      --x;
      int money = y;
      int cant = tree.get_last(money + tree.get_sum(0, x));
      int ans = cant - x;
      money -= tree.get_sum(x, cant);
      //cout << x << " " << cant << endl;
      while (cant < n) {
        int can = tree.get_next(money);
        if (can >= n) {
          break;
        }
        cant = tree.get_last(money + tree.get_sum(0, can));
        //cout << can << " " << cant << endl;
        ans += cant - can;
        money -= tree.get_sum(can, cant);
      }
      cout << ans << "\n";
    }
  }

}