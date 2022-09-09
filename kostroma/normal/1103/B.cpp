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

#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

bool local = false;

int a;

int used_queries = 0;

string get_ans(int x, int y) {
  if (local) {
    x %= a;
    y %= a;
    ++used_queries;
    if (used_queries > 60) {
      return "e";
    }
    if (x >= y) {
      return "x";
    } else {
      return "y";
    }
  } else {
    cout << "? " << x << " " << y << endl;
    string res;
    cin >> res;
    return res;
  }
}

void print_ans(int res) {
  if (local) {
    cout << "correct res: " << res << " a: " << a << endl;
    assert(res == a);
  } else {
    cout << "! " << res << endl;
  }
}

const int MAXA = 1000000000;

void solve(__attribute__((unused)) bool read) {
  string type;
  a = 0;
  while (cin >> type) {
    used_queries = 0;
    if (local) {
      a = rand() % MAXA + 1;
      ++a;
      cout << "a: " << a << endl;
    }
    if (type == "end" || type == "mistake") {
      return;
    }
    assert(type == "start");
    bool f = false;
    if (get_ans(0, 1) == "x" && get_ans(1, 0) == "x") {
      print_ans(1);
      continue;
    }
    for (int cur = 1; cur <= MAXA; cur *= 2) {
      auto query_res = get_ans(cur, cur * 2);
      if (query_res == "e") {
        return;
      }
      if (query_res == "x") {
        int L = cur, R = 2 * cur;
        while (L + 1 < R) {
          int M = (L + R) / 2;
          auto cur_res = get_ans(L, M);
          if (cur_res == "e") {
            return;
          }
          if (cur_res == "x") {
            R = M;
          } else {
            L = M;
          }
        }
        print_ans(R);
        f = true;
        break;
      }
    }
    assert(f);
  }

}