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
    cin >> t;
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

const int N = 3e2 + 5;
int n, m, k, a[N], b[N];
vector<int> buf;

void solve(__attribute__((unused)) bool read) {
  //read = false;
  if (read) {
    cin >> k >> n >> m;
  } else {
    k = n = m = 5;
  }
  if (read) {
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    for (int j = 0; j < m; j++) {
      cin >> b[j];
    }
  } else {
    int end_count = n + m + k;
    for (int i = 0; i < n; ++i) {
      a[i] = rand() % (end_count + 1);
    }
    for (int i = 0; i < m; ++i) {
      b[i] = rand() % (end_count + 1);
    }
    /*vector<int> who(n, 0);
    who.resize(n + m, 1);
    shuffle(who.begin(), who.end(), rng);
    int len = k;
    int cur_count[] = {0, 0};
    for (int i = 0; i < who.size(); ++i) {
      int val = 0;
      if (rand() % 2 != 0) {
        val = 1 + rand() % len;
      }
      int index = cur_count[who[i]]++;
      if (who[i]) {
        b[index] = val;
      } else {
        a[index] = val;
      }
    }
    assert(cur_count[0] == n && cur_count[1] == m);*/
  }

  /*cout << n << " " << m << " " << k << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i + 1 == n];
  }
  for (int i = 0; i < m; ++i) {
    cout << b[i] << " \n"[i + 1 == n];
  }*/

  int x = 0, y = 0;
  bool endd = 0;
  while (x < n || y < m) {
    if (x < n && k >= a[x]) {
      if (a[x] == 0) {
        k++;
      }
      buf.push_back(a[x]);
      x++;
      continue;
    }
    if (y < m && k >= b[y]) {
      if (b[y] == 0) {
        k++;
      }
      buf.push_back(b[y]);
      y++;
      continue;
    }
    cout << -1;
    endd = 1;
    break;
  }
  if (!endd){
    for (auto to : buf) {
      cout << to << " ";
    }
  }
  buf.resize(0);
  cout << endl;
}