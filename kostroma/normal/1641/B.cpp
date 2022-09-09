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

void precalc() {

}

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 500;
  }
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int& x = a[i];
    if (read) {
      cin >> x;
    } else {
      if (i % 2) {
        x = a[i - 1];
      } else {
        x = rand() % 500;
      }
    }
    ++cnt[x];
  }
  if (!read) {
    shuffle(all(a), rng);
  }
  for (auto item : cnt) {
    if (item.second % 2 == 1) {
      cout << "-1\n";
      return;
    }
  }
  vector<int> lens;
  vector<pair<int, int>> insertions;
  vector<int> to_insert;
  int pref = 0;
  while (!a.empty()) {
    int r = 1;
    while (r < a.size() && a[r] != a[0]) {
      ++r;
    }
    assert(r < a.size());
    lens.push_back(r * 2);
    to_insert.clear();
    for (int i = 1; i < r; ++i) {
      insertions.emplace_back(i + pref + r, a[i]);
    }
    for (int i = r - 1; i > 0; --i) {
      to_insert.push_back(a[i]);
    }
    a.erase(a.begin(), a.begin() + r + 1);
    for (int x : a) {
      to_insert.push_back(x);
    }
    a.swap(to_insert);
    pref += 2 * r;
    /*cout << "after" << endl;
    for (int x : a) {
      cout << x << " ";
    }
    cout << endl;*/
  }
  if (read) {
    cout << insertions.size() << "\n";
    for (auto item: insertions) {
      cout << item.first << " " << item.second << "\n";
    }
    cout << lens.size() << "\n";
    for (int &x: lens) {
      cout << x << " ";
    }
    cout << "\n";
  } else {
    cout << insertions.size() << endl;
  }

}