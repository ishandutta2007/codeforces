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

struct Row {
  vector<int> vals;
  int wei;
  bool operator < (const Row& ot) const {
    return wei < ot.wei;
  }
  void scan(int m, bool read) {
    vals.resize(m);
    for (int& x : vals) {
      if (read) {
        cin >> x;
      } else {
        x = rand() % 1000 + 1;
      }
    }
    sort(all(vals));
    if (read) {
      cin >> wei;
    } else {
      wei = rand() % 10000 + 1;
    }
  }
  bool contains(int val) const {
    auto it = lower_bound(all(vals), val);
    return it != vals.end() && *it == val;
  }
};

const int M = 5;

struct Vertex {
  int pos;
  vector<int> positions;
  vector<int> old_values;
  vector<int> new_values;
  array<int, 1 << M> trans;
  bool is_leaf;

  Vertex(int pos): pos(pos), is_leaf(true) {
    trans.fill(-1);
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, m;
  //read = false;
  if (read) {
    cin >> n >> m;
  } else {
    n = 100000;
    //n = rand() % 50 + 2;
    m = rand() % 5 + 1;
    m = 5;
  }
  vector<Row> rows(n);
  for (int i = 0; i < n; ++i) {
    rows[i].scan(m, read);
  }
  sort(all(rows));
  vector<Vertex> bor;
  bor.emplace_back(0);
  bor[0].new_values = rows[0].vals;
  for (int i = 1; i < n; ++i) {
    bor[0].positions.push_back(i);
  }

  auto propagate = [&] (int v) {
    if (!bor[v].is_leaf) {
      return;
    }
    vector<vector<int>> positions_by_mask(1 << bor[v].new_values.size());
    for (int next_pos : bor[v].positions) {
      int mask = 0;
      for (int i = 0; i < bor[v].new_values.size(); ++i) {
        if (rows[next_pos].contains(bor[v].new_values[i])) {
          mask |= (1 << i);
        }
      }
      for (int next_mask = 0; next_mask < positions_by_mask.size(); ++next_mask) {
        if (!(mask & next_mask)) {
          positions_by_mask[next_mask].push_back(next_pos);
        }
      }
    }
    for (int next_mask = 0; next_mask < positions_by_mask.size(); ++next_mask) {
      auto& vec = positions_by_mask[next_mask];
      if (vec.empty()) {
        continue;
      }
      sort(all(vec));
      bor[v].trans[next_mask] = bor.size();
      bor.emplace_back(vec[0]);
      //cout << "v: " << v << " next_mask: " << next_mask << " next_pos: " << vec[0] << endl;
      bor.back().old_values = bor[v].old_values;
      for (int x : bor[v].new_values) {
        bor.back().old_values.push_back(x);
      }
      sort(all(bor.back().old_values));
      for (int x : rows[vec[0]].vals) {
        auto it = lower_bound(all(bor.back().old_values), x);
        if (it == bor.back().old_values.end() || *it != x) {
          bor.back().new_values.push_back(x);
        }
      }
      vec.erase(vec.begin());
      bor.back().positions = vec;
    }
    bor[v].is_leaf = false;
  };

  const int INF = (int)2e9 + 100;
  int res = INF;

  for (int i = 1; i < n; ++i) {
    int v = 0;
    while (v != -1) {
      propagate(v);
      int mask = 0;
      for (int j = 0; j < bor[v].new_values.size(); ++j) {
        if (rows[i].contains(bor[v].new_values[j])) {
          mask |= (1 << j);
        }
      }
      //cout << "i: " << i << " v: " << v << " mask: " << mask << " pos: " << bor[v].pos << endl;
      if (mask == 0) {
        //cout << i << " " << bor[bor[v].trans[0]].pos << endl;
        relax_min(res, rows[bor[v].pos].wei + rows[i].wei);
        break;
      }
      v = bor[v].trans[mask];
    }
  }
  if (res == INF) {
    res = -1;
  }
  cout << res << "\n";

#ifdef PINELY
  if (false) {
    int stupid_res = INF;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        bool f = true;
        for (int val : rows[i].vals) {
          if (rows[j].contains(val)) {
            f = false;
            break;
          }
        }
        if (f) {
          relax_min(stupid_res, rows[i].wei + rows[j].wei);
        }
      }
    }
    if (stupid_res == INF) {
      stupid_res = -1;
    }
    if (stupid_res != res) {
      cout << "found res: " << res << " stupid: " << stupid_res << endl;
      cout << n << " " << m << endl;
      for (int i = 0; i < n; ++i) {
        for (int x : rows[i].vals) {
          cout << x << " ";
        }
        cout << rows[i].wei << endl;
      }
      exit(0);
    }
  }
#endif


}