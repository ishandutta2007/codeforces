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

//#define int li
//const int mod = 1000000007;

struct Query {
  int l, r;
  int id;
  bool operator < (const Query& ot) const {
    return l > ot.l;
  }
};

struct TreeSum {
  int shift;
  vector<int> tree;
  TreeSum(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, 0);
  }
  int get_res(int l, int r) {
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
  void update(int pos) {
    pos += shift;
    ++tree[pos];
    pos /= 2;
    while (pos) {
      tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
      pos /= 2;
    }
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, Q;
  cin >> n >> Q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = (i + 1) - a[i];
    //cout << a[i] << " \n"[i + 1 == n];
  }
  vector<Query> qs;
  for (int i = 0; i < Q; ++i) {
    int x, y;
    cin >> x >> y;
    qs.push_back({x, n - y, i});
  }
  sort(all(qs));
  TreeSum tree_sum(n);
  vector<vector<int>> add_to_pref(n);
  for (int i = 0; i < n; ++i) {
    int val = a[i];
    if (val < 0) {
      continue;
    }
    int pos = i;
    int L = -1, R = pos + 1;
    while (L + 1 < R) {
      int M = (L + R) / 2;
      if (tree_sum.get_res(M, pos) >= val) {
        L = M;
      } else {
        R = M;
      }
    }
    if (L != -1) {
      add_to_pref[L].push_back(pos);
      tree_sum.update(L);
      //cout << "pos: " << pos << " since: " << L << " val: " << val << endl;
    }
  }

  TreeSum tree(n);
  vector<int> ans(Q, -1);
  int cur_pos = n - 1;
  for (auto& cur_q : qs) {
    while (cur_pos >= cur_q.l) {
      for (int pos : add_to_pref[cur_pos]) {
        tree.update(pos);
        //cout << "add pos: " << pos << " val: " << a[pos] << endl;
      }
      --cur_pos;
    }
    ans[cur_q.id] = tree.get_res(cur_q.l, cur_q.r);
    //cout << "evaluate " << cur_q.l << " " << cur_q.r << " " << ans[cur_q.id] << endl;
  }
  for (int x : ans) {
    cout << x << "\n";
  }
}