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

void solve(__attribute__((unused)) bool read) {
  int h, g;
  //read = false;
  if (read) {
    cin >> h >> g;
  } else {
    h = 20;
    g = 10;
  }
  int n = (1 << h);
  vector<int> a(n);
  for (int i = 1; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = (n - i) * 10;
    }
  }
  vector<int> down(n);
  for (int i = n - 1; i >= 0; --i) {
    down[i] = i;
    if (2 * i < n) {
      down[i] = (a[2 * i] < a[2 * i + 1] ? down[2 * i + 1] : down[2 * i]);
    }
  }
  int small_n = (1 << g);

  queue<int> q;
  q.push(1);
  vector<int> res;
  while (!q.empty()) {
    int start_v = q.front();
    q.pop();
    if (a[start_v] == 0) {
      continue;
    }
    while (true) {
      bool flag = true;
      for (int need_swap = 0; need_swap < 2; ++need_swap) {
        int v = start_v;
        while (true) {
          if (2 * v >= n || (a[2 * v] == 0 && a[2 * v + 1] == 0)) {
            if (need_swap) {
              a[v] = 0;
            }
            break;
          }
          for (int w = 0; w < 2; ++w) {
            if (a[2 * v + w] > a[2 * v + (!w)]) {
              if (need_swap) {
                swap(a[2 * v + w], a[v]);
              }
              v = 2 * v + w;
              break;
            }
          }
        }
        if (need_swap == 0) {
          if (v >= small_n) {
            continue;
          } else {
            flag = false;
            break;
          }
        }
      }
      if (!flag) {
        break;
      }
      res.push_back(start_v);
    }
    if (2 * start_v < n) {
      q.push(2 * start_v);
      q.push(2 * start_v + 1);
    }

    /*cout << "after " << start_v << endl;
    for (int x : a) {
      cout << x << " ";
    }
    cout << "\n";*/

  }

  for (int i = small_n; i < n; ++i) {
    assert(a[i] == 0);
  }
  li sum = 0;
  for (int x : a) {
    sum += x;
  }
  cout << sum << "\n";
  for (int x : res) {
    cout << x << " ";
  }
  cout << "\n";

}