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
const int mod = 1000000007;

struct Node {
  int sum = 0;
  int set_val = -1;
  int push_add = 0;
  int cnt = 0;
};

Node merge(const Node& q, const Node& w) {
  Node res = Node();
  res.sum = (q.sum + w.sum) % mod;
  res.cnt = q.cnt + w.cnt;
  return res;
}

void add(int& cur, int val) {
  cur += val;
  cur %= mod;
}

struct SegTree {
  int shift;
  vector<Node> tree;
  vector<int> vec;
  SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    vec.assign(shift, 0);
    tree.assign(2 * shift, Node());
    for (int i = 0; i < shift; ++i) {
      tree[i + shift].cnt = 1;
    }
    for (int i = shift - 1; i >= 0; --i) {
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
  }
  void push(int v) {
    for (int h = 0; h < 2; ++h) {
      auto& child = tree[2 * v + h];
      if (tree[v].set_val != -1) {
        assert(tree[v].push_add == 0);
        child.set_val = tree[v].set_val;
        child.sum = child.set_val * child.cnt % mod;
        child.push_add = 0;
      } else if (tree[v].push_add != 0) {
        if (child.set_val != -1) {
          child.set_val += tree[v].push_add;
          child.set_val %= mod;
          child.sum = child.set_val * child.cnt % mod;
          child.push_add = 0;
        } else {
          child.push_add += tree[v].push_add;
          child.push_add %= mod;
          child.sum += tree[v].push_add * child.cnt;
          child.sum %= mod;
        }
      }
    }
    tree[v].set_val = -1;
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
  int get_sum(int pref) {
    /*int ans = 0;
    for (int i = 0; i < pref; ++i) {
      add(ans, vec[i]);
    }
    return ans;*/
    return rsq(1, 0, shift, 0, pref);
  }
  void make_zero(int pref) {
    /*for (int i= 0; i < pref; ++i) {
      vec[i] = 0;
    }
    return;*/

    return make_zero(1, 0, shift, 0, pref);
  }
  void make_zero(int v, int tl, int tr, int l, int r) {
    if (r <= tl || tr <= l) {
      return;
    }
    if (l <= tl && tr <= r) {
      tree[v].set_val = 0;
      tree[v].sum = 0;
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    make_zero(2 * v, tl, tm, l, r);
    make_zero(2 * v + 1, tm, tr, l, r);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
  }
  void update(int val) {
    /*for (int i = 0; i < shift; ++i) {
      add(vec[i], val);
    }
    return;*/

    update(1, 0, shift, 0, shift, val);
  }
  void update(int v, int tl, int tr, int l, int r, int val) {
    if (r <= tl || tr <= l) {
      return;
    }
    if (l <= tl && tr <= r) {
      if (tree[v].set_val != -1) {
        add(tree[v].set_val, val);
        add(tree[v].sum, val * tree[v].cnt);
      } else {
        add(tree[v].push_add, val);
        add(tree[v].sum, val * tree[v].cnt);
      }
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, r, val);
    update(2 * v + 1, tm, tr, l, r, val);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
  }
  void push_all() {
    for (int i = 0; i < shift; ++i) {
      push(i);
    }
    for (int i = shift - 1; i >= 0; --i) {
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
  }
};

void solve(__attribute__((unused)) bool read) {
  string s;
  //read = false;
  if (read) {
    cin >> s;
  } else {
    s = string(1000000,'0');
    for (char& c : s) {
      if (rand() % 4 == 0) {
        c = '1';
      }
    }
  }
  int cnt_zeros = 0;
  vector<int> segs;
  for (char c : s) {
    if (c == '0') {
      ++cnt_zeros;
    } else {
      segs.push_back(cnt_zeros);
      cnt_zeros = 0;
    }
  }
  segs.push_back(cnt_zeros);
  if (segs.size() == 1) {
    cout << segs[0] << "\n";
    return;
  }
  int res = (segs[0] + 1) * (segs.back() + 1) % mod;
  segs.pop_back();
  segs.erase(segs.begin());
  SegTree tree((int)s.length() + 1);
  tree.update(1);
  int ans = 1;
  for (int x : segs) {
    //tree.push_all();
    int new_sum = tree.get_sum(x + 1);
    //cout << new_sum << endl;
    add(ans, new_sum);
    tree.make_zero(x + 1);
    tree.update(new_sum);
  }
  ans = ans * res % mod;
  cout << ans << "\n";
}