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
//const li mod = 1000000007;
//using ull = unsigned long long;

vector < vector<int> > g;
vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
  if (used[v])  return false;
  used[v] = true;
  for (size_t i=0; i<g[v].size(); ++i) {
    int to = g[v][i];
    if (mt[to] == -1 || try_kuhn (mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

int get_res(int n, int m) {
  g.clear();
  mt.clear();
  used.clear();
  int N = n * m;
  g.resize(N);
  mt.assign(N, -1);
  for (int i = 0; i < N; ++i) {
    int x = i / m, y = i % m;
    if ((x + y) % 2 == 0) {
      for (int dx = -3; dx <= 3; ++dx) {
        for (int dy = -3; dy <= 3; ++dy) {
          if (abs(dx) + abs(dy) == 3) {
            int X = x + dx, Y = y + dy;
            if (X >= 0 && X < n && Y >= 0 && Y < m) {
              g[i].push_back(X * m + Y);
            }
          }
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i < N; ++i) {
    used.assign(N, false);
    if (try_kuhn(i)) {
      ++res;
    }
  }
  return res;
}

int stupid_solve(int n, int m) {
  if (n > m) {
    swap(n, m);
  }
  int res = n * m / 2;
  if (m < 10) {
    res = get_res(n, m);
  } else if (n == 1) {
    if (m % 6 != 0 && m % 6 != 5 && m % 6 != 1 && res > 0) {
      --res;
    }
  }
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  int res = stupid_solve(n, m);
  cout << res * 2 << endl;
  return;

  for (n = 1; n <= 40; ++n) {
    for (m = 1; m <= 40; ++m) {
      int stup = stupid_solve(n, m);
      int fact = get_res(n, m);
      if (stup != fact) {
        cout << "FOUND " << n << " " << m << " " << stup << " " << fact <<endl;
        exit(0);
      }
    }
  }

  //cout << res * 2 << endl;

}