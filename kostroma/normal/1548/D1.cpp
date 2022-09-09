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

using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
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
    int test_num = 1;
    while (t--) {
      //cout << "Case #" << test_num++ << ": ";
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

struct Point {
  int x, y;
};

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 6000;
  }
  vector<Point> points(n);
  vector<vector<int>> cnt(2, vector<int>(2, 0));
  for (auto& pt : points) {
    if (read) {
      cin >> pt.x >> pt.y;
    } else {
      pt.x = 2 * (rand() % (int)5e6);
      pt.y = 2 * (rand() % (int)5e6);
    }
    pt.x /= 2;
    pt.y /= 2;
    pt.x %= 2;
    pt.y %= 2;
  }
  li res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int is_ok = !((points[j].x - points[i].x) % 2 == 0 && (points[j].y - points[i].y) % 2 == 0);
      for (int a = 0; a < 2; ++a) {
        for (int b = 0; b < 2; ++b) {
          int cur = is_ok;
          cur += !((points[i].x - a) == 0 && (points[i].y - b) == 0);
          cur += !((points[j].x - a) == 0 && (points[j].y - b) == 0);
          /*if (cnt[a][b] > 0) {
            cout << "i: " << i << " j: " << j << " is_ok: " << is_ok << " a: " << a << " b: " << b << " cur: " << cur << endl;
          }*/
          if (cur % 2 == 0) {
            res += cnt[a][b];
          }
        }
      }
    }
    ++cnt[points[i].x][points[i].y];
  }
  cout << res << "\n";

}