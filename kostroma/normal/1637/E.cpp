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

#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void solve(__attribute__((unused)) bool read) {
  int n, m;
  //read = false;
  if (read) {
    cin >> n >> m;
  } else {
    n = m = 300000;
  }
  map<int, int> mapa;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    int x;
    if (read) {
      cin >> x;
    } else {
      x = rand() % 200;
    }
    ++mapa[x];
    a[i] = x;
  }
  vector<int> cnts, vals;
  for (auto& item : mapa) {
    cnts.push_back(item.second);
    vals.push_back(item.first);
  }
  n = cnts.size();
  vector<map<int, vector<int>>> bad(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    if (read) {
      cin >> x >> y;
    } else {
      do {
        x = a[rand() % a.size()];
        y = a[rand() % a.size()];
      } while (x >= y);
    }
    x = lower_bound(all(vals), x) - vals.begin();
    y = lower_bound(all(vals), y) - vals.begin();
    bad[y][cnts[x]].push_back(x);
  }
  vector<vector<pair<int, vector<int>>>> edges(n);
  for (int i = 0; i < n; ++i) {
    for (auto& item : bad[i]) {
      sort(all(item.second));
      edges[i].push_back(item);
    }
  }
  int res = 0;

  auto relax_ans = [&] (int pos1, int pos2) {
    relax_max(res, (cnts[pos1] + cnts[pos2]) * (vals[pos1] + vals[pos2]));
  };

  map<int, vector<int>> indices_by_cnt;
  for (int i = 0; i < n; ++i) {
    //cerr << indices_by_cnt.size() << endl;
    int list_uk = 0;
    for (auto& indices : indices_by_cnt) {
      int cnt = indices.first;
      auto& vec = indices.second;
      while (list_uk < edges[i].size() && edges[i][list_uk].first < cnt) {
        ++list_uk;
      }
      int can_pos = (int)vec.size() - 1;
      if (list_uk < edges[i].size() && edges[i][list_uk].first == cnt) {
        auto& banned = edges[i][list_uk].second;
        int ban_uk = (int)banned.size() - 1;
        while (can_pos >= 0) {
          while (ban_uk >= 0 && banned[ban_uk] > vec[can_pos]) {
            --ban_uk;
          }
          if (ban_uk >= 0 && banned[ban_uk] == vec[can_pos]) {
            --can_pos;
            continue;
          }
          break;
        }
      }
      if (can_pos >= 0) {
        relax_ans(vec[can_pos], i);
      }
    }
    indices_by_cnt[cnts[i]].push_back(i);
  }
  cout << res << "\n";
}