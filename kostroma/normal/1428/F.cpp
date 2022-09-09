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

struct Node {
  int sum = 0;
  int max = 0;
  int push_add = 0;
  int cnt = 0;
};

Node merge(const Node& q, const Node& w) {
  Node res = Node();
  res.sum = q.sum + w.sum;
  res.max = max(q.max, w.max);
  res.cnt = q.cnt + w.cnt;
  res.push_add = 0;
  return res;
}

struct SegTree {
  int n;
  int shift;
  vector<Node> tree;
  SegTree(int N) {
    n = N;
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, Node());
    for (int i = 0; i < n; ++i) {
      tree[shift + i].cnt = 1;
    }
    for (int i = shift - 1; i > 0; --i) {
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
  }
  void push(int v) {
    if (tree[v].push_add == 0) {
      return;
    }
    for (int h = 0; h < 2; ++h) {
      Node& child = tree[2 * v + h];
      child.push_add += tree[v].push_add;
      child.max += tree[v].push_add;
      child.sum += tree[v].push_add * child.cnt;
    }
    tree[v].push_add = 0;
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
  int get_position(int border) {
    int v = 1;
    if (tree[v].max < border) {
      return n;
    }
    while (v < shift) {
      push(v);
      if (tree[2 * v].max >= border) {
        v = 2 * v;
        continue;
      } else {
        v = 2 * v + 1;
      }
    }
    return v - shift;
  }
  void modify(int v, int tl, int tr, int l, int r, int val) {
    if (r <= tl || tr <= l) {
      return;
    }
    if (l <= tl && tr <= r) {
      tree[v].push_add += val;
      tree[v].max += val;
      tree[v].sum += tree[v].cnt * val;
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    modify(2 * v, tl, tm, l, r, val);
    modify(2 * v + 1, tm, tr, l, r, val);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
  }
  void update(int l, int r, int val) {
    return modify(1, 0, shift, l, r, val);
  }
};

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  string s;
  cin >> s;

  SegTree tree(n);
  int ans = 0;
  int cur_seq = 0;
  for (int pos = (int)s.length() - 1; pos >= 0; --pos) {
    if (s[pos] == '0') {
      cur_seq = 0;
    } else {
      ++cur_seq;
      int until = tree.get_position(cur_seq);
      tree.update(pos, until, 1);
      //cout << "pos: " << pos << " until: " << until << endl;
    }
    int cur_add = tree.get_sum(0, n);
    //cout << "pos: " << pos << " add: " << cur_add << "\n";
    ans += cur_add;
  }

  cout << ans << "\n";

}