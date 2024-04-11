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
  int n, k;
  cin >> n >> k;
  vector<set<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].insert(b);
    g[b].insert(a);
  }
  vector<char> used(n, false);
  vector<int> cur_leaves;
  for (int i = 0; i < n; ++i) {
    if (g[i].size() == 1) {
      cur_leaves.push_back(i);
      used[i] = true;
    }
  }
  auto erase_edge = [&] (int a, int b) {
    g[a].erase(b);
    g[b].erase(a);
  };
  int TIMER = 1;
  vector<int> in_next(n, 0);
  vector<int> erased(n, 0);
  int rest_vertices = n;
  while (k > 0) {
    ++TIMER;
    if (cur_leaves.empty()) {
      cout << "No\n";
      return;
    }
    vector<int> next_leaves;
    for (int v : cur_leaves) {
      int current_v = v;

      auto process_parent = [&] (int p) {
        ++erased[p];
        if (in_next[p] != TIMER) {
          next_leaves.push_back(p);
          in_next[p] = TIMER;
        }
      };

      {
        //cout << "process " << current_v + 1 << " k: " << k << endl;
        --rest_vertices;
        int p = *g[current_v].begin();
        erase_edge(p, current_v);
        if (in_next[p] == TIMER) {
          process_parent(p);
        } else {
            if (g[p].empty()) {
              cout << "No\n";
              return;
            }
            process_parent(p);
        }
      }

    }
    if (k == 1 && next_leaves.size() == 1 && rest_vertices == 1 && erased[next_leaves[0]] >= 3) {
      cout << "Yes\n";
      return;
    }
    for (int v : next_leaves) {
      if (erased[v] < 3 || g[v].size() != 1) {
        cout << "No\n";
        return;
      }
    }
    cur_leaves.swap(next_leaves);
    --k;
  }
  cout << "No\n";

}