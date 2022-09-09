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
  //freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
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
  int n, m;
  cin >> n >> m;
  vector<int> p(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> p[i];
  }
  vector<int> paired(2 * n, -1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    paired[a] = b;
    paired[b] = a;
  }
  vector<char> used(2 * n, false);
  int t;
  cin >> t;
  --t;
  int cnt = 2 * n;
  auto get_turn = [&]() {
    int x;
    cin >> x;
    if (x == -1) {
      exit(0);
    }
    --cnt;
    --x;
    used[x] = true;
  };
  auto make_turn = [&](int x) {
    cout << x + 1 << endl;
    used[x] = true;
    --cnt;
  };
  for (int w = 0; w < 2 * n; ++w) {
    if (w % 2 != t) {
      get_turn();
      continue;
    }
    bool has_turn = false;
    int best_turn = -1;
    int best_score = -1;
    for (int i = 0; i < 2 * n; ++i) {
      if (paired[i] == -1 || used[i]) {
        continue;
      }
      if (!used[i] && used[paired[i]]) {
        make_turn(i);
        has_turn = true;
        break;
      }
      int score = p[i] - p[paired[i]];
      if (score > best_score) {
        best_score = score;
        best_turn = i;
      }
    }
    if (has_turn) {
      continue;
    }
    if (best_turn != -1) {
      make_turn(best_turn);
      continue;
    }
    for (int i = 0; i < 2 * n; ++i) {
      if (used[i]) {
        continue;
      }
      if (p[i] > best_score) {
        best_score = p[i];
        best_turn = i;
      }
    }
    assert(best_turn != -1);
    make_turn(best_turn);
  }

}