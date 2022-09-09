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
const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

vector<int> powers, rev_powers;

struct Node {
  int ans = 0;
  int sum_left = 0;
  int sum_right = 0;
  int cnt = 0;
};

Node merge(const Node& q, const Node& w) {
  return {
      (q.ans + w.ans + q.sum_left * w.sum_right % mod * rev_powers[q.cnt]) % mod,
      (q.sum_left + w.sum_left * powers[q.cnt]) % mod,
      (q.sum_right + w.sum_right * rev_powers[q.cnt]) % mod,
      q.cnt + w.cnt
      };
}

struct SegTree {
  int shift;
  vector<Node> tree;
  SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, Node{0, 0, 0});
  }
  void update(int v, int lef, int rig) {
    v += shift;
    tree[v] = Node{0, lef, rig, 1};
    v /= 2;
    while (v) {
      tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
      v /= 2;
    }
  }
  void erase(int v) {
    v += shift;
    tree[v] = Node{0, 0, 0, 0};
    v /= 2;
    while (v) {
      tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
      v /= 2;
    }
  }
  int get_res() const {
    return (tree[1].ans + mod) % mod;
  }
};

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  powers.assign(n + 1, 1);
  rev_powers = powers;
  for (int i = 1; i < powers.size(); ++i) {
    powers[i] = powers[i - 1] * 2 % mod;
  }
  rev_powers[1] = binpow(powers[1], mod - 2, mod);
  for (int i = 2; i < powers.size(); ++i) {
    rev_powers[i] = rev_powers[i - 1] * rev_powers[1] % mod;
  }
  vector<pair<int, int>> p(n);
  vector<pair<int, int>> have;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first;
    p[i].second = i;
    have.push_back(p[i]);
  }
  int Q;
  cin >> Q;
  vector<pair<int, int>> queries(Q);
  for (int w = 0; w < Q; ++w) {
    cin >> queries[w].first >> queries[w].second;
    --queries[w].first;
    have.push_back({queries[w].second, w + n});
  }
  sort(all(have));
  SegTree tree(have.size());
  auto get_index = [&] (const pair<int, int>& v) {
    int index = lower_bound(all(have), v) - have.begin();
    return index;
  };
  for (int i = 0; i < n; ++i) {
    tree.update(get_index(p[i]), p[i].first, p[i].first * rev_powers[1] % mod);
  }
  cout << tree.get_res() << "\n";
  for (int w = 0; w < Q; ++w) {
    int i = queries[w].first;
    //cout << "was: " << get_index(p[i]) << endl;
    tree.erase(get_index(p[i]));
    p[i] = {queries[w].second, w + n};
    //cout << "now: " << get_index(p[i]) << endl;
    tree.update(get_index(p[i]), p[i].first, p[i].first * rev_powers[1] % mod);
    cout << tree.get_res() << "\n";
  }




}