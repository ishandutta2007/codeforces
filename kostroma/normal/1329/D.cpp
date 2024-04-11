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
  cin >> t;
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
struct Node {
  int sum;
  int push_clear;
};

Node merge(const Node& q, const Node& w) {
  return {q.sum + w.sum, 0};
}

struct SegTree {
  int shift;
  vector<Node> tree;
  SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, {0 , 0});
    for (int i = 0; i < n; ++i) {
      tree[shift + i] = {1, 0};
    }
    for (int i = shift - 1; i >= 0; --i) {
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
  }
  void clear(int l, int r) {
    modify_clear(1, 0, shift, l, r);
  }
  void push(int v) {
    for (int h = 0; h < 2; ++h) {
      auto& child = tree[2 * v + h];
      if (tree[v].push_clear) {
        child.push_clear = 1;
        child.sum = 0;
      }
    }
    tree[v].push_clear = 0;
  }
  void modify_clear(int v, int tl, int tr, int l, int r) {
    if (tl >= r || tr <= l) {
      return;
    }
    if (l <= tl && tr <= r) {
      tree[v].push_clear = 1;
      tree[v].sum = 0;
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    modify_clear(2 * v, tl, tm, l, r);
    modify_clear(2 * v + 1, tm, tr, l, r);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
  }
  int get_sum(int r) {
    return rsq(1, 0, shift, 0, r);
  }
  int rsq(int v, int tl, int tr, int l, int r) {
    if (tl >= r || tr <= l) {
      return 0;
    }
    if (l <= tl && tr <= r) {
      return tree[v].sum;
    }
    push(v);
    int tm = (tl + tr) / 2;
    return rsq(2 * v, tl, tm, l, r) + rsq(2 * v + 1, tm, tr, l, r);
  }
};

struct Segment {
  int l, r;
  int start, finish;
  bool operator < (const Segment& ot) const {
    return make_pair(l, r) < make_pair(ot.l, ot.r);
  }
};

void solve(__attribute__((unused)) bool read) {
  string s;
  //read = false;
  if (read) {
    cin >> s;
  } else {
    s = string(200000, 'a');
    for (int i = 0; i < s.length(); ++i) {
      s[i] = 'a' + rand() % 26;
      //s[i] = "ab"[i / 100000];
      //s[i] = 'a';
    }
  }
  int n = (int)s.length();
  SegTree tree(n);
  set<Segment> sorted_segments;
  vector<Segment> different_segments[26];
  vector<int> scores(26);
  for (int i = 0; i < n; ) {
    int j = i + 1;
    while (j < n && s[j] != s[j - 1]) {
      ++j;
    }
    Segment cur_seg = {i, j, s[i] - 'a', s[j - 1] - 'a'};
    if (j < n) {
      ++scores[s[j] - 'a'];
    }
    sorted_segments.insert(cur_seg);
    if (cur_seg.start != cur_seg.finish && cur_seg.l > 0 && cur_seg.r < n) {
      different_segments[cur_seg.start].push_back(cur_seg);
      different_segments[cur_seg.finish].push_back(cur_seg);
    }
    i = j;
  }
  vector<pair<int, int>> ans;
  vector<int> perm(26, 0);
  iota(all(perm), 0);
  while (true) {
    bool found = false;
    sort(all(perm), [&] (int q, int w) {
      return scores[q] > scores[w];
    });
    for (int w = 0; w < 26; ++w) {
      auto& dif_segs = different_segments[perm[w]];
      while (!dif_segs.empty()) {
        auto cur_seg = dif_segs.back();
        dif_segs.pop_back();
        auto it = sorted_segments.find(cur_seg);
        if (it == sorted_segments.end()) {
          continue;
        }
        found = true;
        ans.push_back({tree.get_sum(it->l), tree.get_sum(it->r)});
        tree.clear(it->l, it->r);
        auto prev_it = prev(it);
        auto next_it = next(it);

        Segment new_seg = {prev_it->l, next_it->r, prev_it->start, next_it->finish};
        --scores[cur_seg.start];
        --scores[cur_seg.finish];

        sorted_segments.erase(it);
        sorted_segments.erase(prev_it);
        sorted_segments.erase(next_it);

        sorted_segments.insert(new_seg);
        if (new_seg.start != new_seg.finish && new_seg.l > 0 && new_seg.r < n) {
          different_segments[new_seg.start].push_back(new_seg);
          different_segments[new_seg.finish].push_back(new_seg);
        }

        break;
      }
      if (found) {
        break;
      }
    }
    if (!found) {
      break;
    }
  }

  for (auto cur_seg : sorted_segments) {
    ans.push_back({tree.get_sum(cur_seg.l), tree.get_sum(cur_seg.r)});
    tree.clear(cur_seg.l, cur_seg.r);
  }

  cout << ans.size() << "\n";
  if (read) {
    for (auto item : ans) {
      cout << item.first + 1 << " " << item.second << "\n";
    }
  }

}