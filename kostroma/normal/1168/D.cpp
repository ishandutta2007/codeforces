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


void solve(__attribute__((unused)) bool read) {
  int n, Q;
  cin >> n >> Q;
  vector<int> parent(n, -1), letter(n, -1);
  vector<int> down(n, 0);
  auto get_val = [&] (char c) {
    if (c == '?') {
      return -1;
    }
    return c - 'a';
  };
  vector<int> depth(n, 0);
  for (int i = 1; i < n; ++i) {
    char c;
    cin >> parent[i] >> c;
    letter[i] = get_val(c);
    --parent[i];
    ++down[parent[i]];
    depth[i] = depth[parent[i]] + 1;
  }
  int max_depth = *max_element(all(depth));
  for (int i = 0; i < n; ++i) {
    if (down[i] == 0 && max_depth != depth[i]) {
      while (Q--) {
        cout << "Fou\n";
      }
      return;
    }
  }
  vector<int> good_parent(n, -1);
  vector<vector<int>> g(n);
  vector<char> is_good(n, false);
  for (int i = 0; i < n; ++i) {
    is_good[i] = (i == 0 || down[i] != 1);
  }
  for (int i = 1; i < n; ++i) {
    if (is_good[parent[i]]) {
      good_parent[i] = parent[i];
    } else {
      good_parent[i] = good_parent[parent[i]];
    }
    if (is_good[i]) {
      g[good_parent[i]].push_back(i);
    }
  }
  vector<int> good_down(n, -1);
  for (int i = n - 1; i >= 0; --i) {
    if (is_good[i]) {
      good_down[i] = i;
    }
    good_down[parent[i]] = good_down[i];
  }
  vector<vector<int>> score_by_edge(n, vector<int>(26, 0));
  for (int i = 1; i < n; ++i) {
    if (letter[i] != -1) {
      ++score_by_edge[good_down[i]][letter[i]];
    }
  }
  vector<vector<int>> max_score(n, vector<int>(26, 0));
  vector<int> sum_score(n, 0);
  int cnt_negative = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (!is_good[i]) {
      continue;
    }
    for (int to : g[i]) {
      for (int c = 0; c < 26; ++c) {
        relax_max(max_score[i][c], max_score[to][c] + score_by_edge[to][c]);
      }
    }
    for (int c = 0; c < 26; ++c) {
      sum_score[i] += max_score[i][c];
    }
    if (sum_score[i] > max_depth - depth[i]) {
      ++cnt_negative;
    }
  }
  while (Q--) {
    int v;
    char cc;
    cin >> v >> cc;
    --v;

    auto process_up = [&] (int v) {
      int cur_v = good_parent[v];
      int c = letter[v];
      do {
        int old_score = max_score[cur_v][c];
        int new_score = 0;
        for (int to : g[cur_v]) {
          relax_max(new_score, max_score[to][c] + score_by_edge[to][c]);
        }
        if (new_score == old_score) {
          break;
        }
        if (sum_score[cur_v] > max_depth - depth[cur_v]) {
          --cnt_negative;
        }
        sum_score[cur_v] += new_score - old_score;
        if (sum_score[cur_v] > max_depth - depth[cur_v]) {
          ++cnt_negative;
        }
        max_score[cur_v][c] = new_score;
        cur_v = good_parent[cur_v];
      } while (cur_v != -1);
    };
    if (letter[v] != -1) {
      int cur_v = good_down[v];
      --score_by_edge[cur_v][letter[v]];
      process_up(v);
    }
    letter[v] = get_val(cc);
    if (letter[v] != -1) {
      int cur_v = good_down[v];
      ++score_by_edge[cur_v][letter[v]];
      process_up(v);
    }
    if (cnt_negative > 0) {
      cout << "Fou\n";
    } else {
      cout << "Shi ";
      int cur_add = max_depth - sum_score[0];
      int res = 0;
      for (int let = 0; let < 26; ++let) {
        res += (max_score[0][let] + cur_add) * (let + 1);
      }
      cout << res << "\n";
    }

  }

}