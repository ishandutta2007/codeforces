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
 
vector<vector<int>> g;
vector<int> tin, tout;
int TIMER = 0;
 
void dfs(int v) {
  tin[v] = TIMER++;
  for (int to : g[v]) {
    dfs(to);
  }
  tout[v] = TIMER;
}
 
const double eps = 1e-9;
 
struct Line {
  li a, b;
  li get_val(li x) {
    return a + b * x;
  }
  bool operator < (const Line& ot) const {
    return b < ot.b;
  }
  double intersect(const Line& ot) const {
    return (a - ot.a) / 1.0 / (ot.b - b);
  }
};
 
bool can_erase(const Line& a, const Line& b, const Line& c) {
  return a.intersect(b) + eps > b.intersect(c);
}
 
const li INF = (li)2e18;
 
struct Block {
  vector<Line> lines;
  vector<int> perm;
  vector<Line> order;
  li cur_add = 0;
  int best_pointer = 0;
  void build() {
 best_pointer = 0;
    if (perm.empty()) {
      perm.assign(lines.size(), 0);
      iota(all(perm), 0);
      sort(all(perm), [&](int q, int w) {
        return lines[q] < lines[w];
      });
      order.reserve(lines.size());
    }
    order.clear();
    for (int w = 0; w < perm.size(); ++w) {
      auto cur_line = lines[perm[w]];
      bool need_add = true;
      while (!order.empty()) {
        if (cur_line.b == order.back().b) {
          if (cur_line.a <= order.back().a) {
            need_add = false;
            break;
          }
          order.pop_back();
          continue;
        }
        if (order.size() >= 2 && can_erase(order[order.size() - 2], order.back(), cur_line)) {
          order.pop_back();
          continue;
        }
        break;
      }
      if (need_add) {
        order.push_back(cur_line);
      }
    }
  }
  void process_pointer() {
    while (best_pointer + 1 < order.size() && order[best_pointer + 1].get_val(cur_add) > order[best_pointer].get_val(cur_add)) {
      ++best_pointer;
    }
  }
  li get_max() {
    if (lines.empty()) {
      return -INF;
    }
    process_pointer();
    li res = order[best_pointer].get_val(cur_add);
    //cout << "get max: " << res << endl;
    return res;
  }
};
 
struct Decomposition {
  vector<Block> blocks;
  int block_size;
  int n_blocks;
  Decomposition(vector<li> a, vector<li> b, int B) {
    int n = (int)a.size();
    block_size = B;
    //block_size = 5;
    n_blocks = (n - 1) / block_size + 1;
    for (int i = 0; i < n_blocks; ++i) {
      int l = i * block_size, r = min(n, (i + 1) * block_size);
      blocks.push_back({});
      for (int j = l; j < r; ++j) {
        blocks.back().lines.push_back({a[j] * b[j], b[j]});
      }
      blocks.back().build();
    }
  }
  li get_res(int l, int r) {
    int l_block = l / block_size, r_block = (r - 1) / block_size;
    li res = -INF;
    {
      auto& cur_block = blocks[l_block];
      for (int i = l; i < r && i < (l_block + 1) * block_size; ++i) {
        relax_max(res, cur_block.lines[i - l_block * block_size].get_val(cur_block.cur_add));
      }
      if (l_block == r_block) {
        return res;
      }
      ++l_block;
    }
    {
      auto& cur_block = blocks[r_block];
      for (int i = r_block * block_size; i < r; ++i) {
        relax_max(res, cur_block.lines[i - r_block * block_size].get_val(cur_block.cur_add));
      }
    }
    for (int i = l_block; i < r_block; ++i) {
      //cout << "ask block: " << i << endl;
      relax_max(res, blocks[i].get_max());
    }
    //cout << "out " << res << endl;
    return res;
  }
  void update(int l, int r, li x) {
    int l_block = l / block_size, r_block = (r - 1) / block_size;
    {
      auto& cur_block = blocks[l_block];
      for (int i = l; i < r && i < (l_block + 1) * block_size; ++i) {
        auto& cur_line = cur_block.lines[i - l_block * block_size];
        cur_line.a += cur_line.b * x;
      }
      cur_block.build();
      if (l_block == r_block) {
        return;
      }
      ++l_block;
    }
    {
      auto& cur_block = blocks[r_block];
      for (int i = r_block * block_size; i < r; ++i) {
        auto& cur_line = cur_block.lines[i - r_block * block_size];
        cur_line.a += cur_line.b * x;
      }
      cur_block.build();
    }
    for (int i = l_block; i < r_block; ++i) {
      blocks[i].cur_add += x;
    }
  }
};
 
void solve(__attribute__((unused)) bool read) {
  int n, Q;
  //read = false;
  if (read) {
    cin >> n >> Q;
  } else {
    n = 200000;
    Q = 100000;
  }
  g.resize(n);
  vector<int> parent(n, -1);
  for (int i = 1; i < n; ++i) {
    int cur;
    if (read) {
      cin >> cur;
      --cur;
    } else {
      cur = i - 1;
    }
    parent[i] = cur;
    g[cur].push_back(i);
  }
  tin.resize(n);
  tout.resize(n);
  dfs(0);
  vector<li> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = rand() % 10000 - 5000;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> b[i];
    } else {
      b[i] = rand() % 10000 - 5000;
    }
  }
  for (int i = 1; i < n; ++i) {
    a[i] += a[parent[i]];
    b[i] += b[parent[i]];
  }
  vector<li> A(n), B(n);
  for (int i = 0; i < n; ++i) {
    A[tin[i]] = a[i];
    B[tin[i]] = b[i];
  }
  A.swap(a);
  B.swap(b);
  int block_size = 150; //max(1, (int)sqrt(n + Q) / 8);
  block_size = min(block_size, n);
  vector<Decomposition> decompositions;
  for (int w = 0; w < 2; ++w) {
    decompositions.emplace_back(a, b, block_size);
    for (auto& x : b) {
      x = -x;
    }
  }
  while (Q--) {
    int type, v;
    if (read) {
      cin >> type >> v;
      --v;
    } else {
      type = 1;
      v = rand() % n;
    }
    int l = tin[v], r = tout[v];
    if (type == 1) {
      int x;
      if (read) {
        cin >> x;
      } else {
        x = rand() % 5000 + 1;
      }
      for (auto& dec : decompositions) {
        dec.update(l, r, x);
      }
    } else {
      li res = -INF;
      for (auto& dec : decompositions) {
        relax_max(res, dec.get_res(l, r));
      }
      cout << res << "\n";
    }
  }
 
}