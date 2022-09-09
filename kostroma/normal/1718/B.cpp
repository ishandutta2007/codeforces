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
    cin >> t;
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

#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void precalc() {
}

const int C = (int)1e9 + 100;

void solve(__attribute__((unused)) bool read) {
  vector<int> fib = {1, 1};
  while (fib.back() < C) {
    int val = fib[fib.size() - 2] + fib.back();
    fib.push_back(val);
  }
  vector<int> cnt(fib.size(), 0);
  int k;
  //read = false;
  if (read) {
    cin >> k;
  } else {
    k = 100;
  }
  vector<int> a;
  vector<vector<int>> reprs;
  vector<int> repr;
  for (int w = 0; w < k; ++w) {
    int cur;
    if (read) {
      cin >> cur;
    } else {
      cur = rand() % (int)1e9 + 1;
    }
    a.push_back(cur);
    repr.clear();
    for (int i = (int)fib.size() - 1; i >= 0; --i) {
      if (cur >= fib[i]) {
        repr.push_back(i);
        ++cnt[i];
        cur -= fib[i];
      }
    }
    reprs.push_back(repr);
    assert(cur == 0);
  }
  for (int one = 0; one < a.size(); ++one) {
    for (int x : reprs[one]) {
      --cnt[x];
    }
    int rest = a[one] - 1;
    repr.clear();
    for (int i = (int)fib.size() - 1; i > 1; --i) {
      if (rest >= fib[i]) {
        repr.push_back(i);
        rest -= fib[i];
      }
    }
    assert(rest <= 1);
    if (rest == 0) {
      for (int x : repr) {
        ++cnt[x];
      }
      int mx = (int)fib.size() - 1;
      while (mx > 0 && cnt[mx] == 0) {
        --mx;
      }
      bool f = true;
      for (int i = 1; i <= mx; ++i) {
        if (cnt[i] != 1) {
          f = false;
          break;
        }
      }
      if (f) {
        cout << "YES\n";
        return;
      }
      for (int x : repr) {
        --cnt[x];
      }
    }
    for (int x : reprs[one]) {
      ++cnt[x];
    }
  }
  cout << "NO\n";
}