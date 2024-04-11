#pragma comment(linker, "/STACK:512000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <memory>
#include <chrono>
#include <cassert>
#include <random>
#include <queue>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <sstream>
#ifdef PINELY
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
#ifdef PINELY
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;

#ifdef PINELY
  const rlim_t kStackSize = 60 * 1024 * 1024;   // min stack size = 16 MB
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
#ifndef PINELY
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    cout.precision(20);
    cout << fixed;
    //cin >> t;
    precalc();
    int test_num = 1;
    while (t--) {
      //cout << "Case #" << test_num++ << ": ";
      solve(true);
    }
    cout.flush();

#ifdef PINELY1
    while (true) {
    solve(false);
  }
#endif

#ifdef PINELY
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

template<typename T>
void print_vec(const vector<T>& vals) {
  for (int x : vals) {
    cout << x << " ";
  }
  cout << endl;
}

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

void precalc() {

}

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

const int INF = (int)1e9;

struct SegTree {
  int shift;
  vector<int> tree;
  SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, INF);
  }
  void update(int v, int val) {
    v += shift;
    relax_min(tree[v], val);
    v /= 2;
    while (v) {
      tree[v] = min(tree[2 * v], tree[2 * v + 1]);
      v /= 2;
    }
  }
  int get_min(int l, int r) {
    l += shift;
    r += shift;
    int res = INF;
    while (l < r) {
      if (l & 1) {
        relax_min(res, tree[l]);
        ++l;
        continue;
      }
      if (r & 1) {
        --r;
        relax_min(res, tree[r]);
        continue;
      }
      l /= 2;
      r /= 2;
    }
    return res;
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, Q;
  cin >> n >> Q;
  set<int> not_known;
  for (int i = 0; i < n; ++i) {
    not_known.insert(i);
  }
  SegTree tree(n);
  while (Q--) {
    int type;
    cin >> type;
    if (type == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      --l;
      if (x == 0) {
        auto it = not_known.lower_bound(l);
        while (it != not_known.end() && *it < r) {
          auto prev_it = it;
          it = next(it);
          //cout << "erasing " << *prev_it << endl;
          not_known.erase(prev_it);
        }
      } else {
        tree.update(l, r);
      }
    } else {
      int pos;
      cin >> pos;
      --pos;
      auto it = not_known.find(pos);
      if (it == not_known.end()) {
        cout << "NO" << "\n";
        continue;
      }
      auto next_it = next(it);
      int r = (next_it == not_known.end() ? n : *next_it);
      int l = (it == not_known.begin() ? -1 : *prev(it));
      int best_rig = tree.get_min(l + 1, r);
      //cout << "pos: " << pos << " l: " << l << " r: " << r << " best_rig: " << best_rig << endl;
      if (best_rig <= r) {
        cout << "YES\n";
      } else {
        cout << "N/A\n";
      }
    }
  }
}