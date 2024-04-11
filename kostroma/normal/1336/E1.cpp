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
const int mod = 998244353;
//using ull = unsigned long long;

void add(int& cur, int val) {
  cur += val;
  cur %= mod;
}

void solve(__attribute__((unused)) bool read) {
  int n, m;
  //read = false;
  if (read) {
    cin >> n >> m;
  } else {
    n = 200000;
    m = 35;

    n = rand() % 20 + 1;
    m = rand() % 35 + 1;
    n = 200000;
    m = 35;
  }
  vector<int> basis;
  vector<int> first_bit;
  int mult = 1;

  vector<int> inp;

  for (int w = 0; w < n; ++w) {
    int cur;
    if (read) {
      cin >> cur;
    } else {
      cur = 0;
      for (int j = 0; j < m; ++j) {
        if (j > 19) {
          break;
        }
        cur = cur * 2 + rand() % 2;
      }
      cur = (1LL << (w % m));
    }
    inp.push_back(cur);
    for (int i = 0; i < basis.size(); ++i) {
      if (cur & (1LL << first_bit[i])) {
        cur ^= basis[i];
      }
    }
    if (cur == 0) {
      mult = mult * 2 % mod;
      continue;
    }
    //cout << "append cur: " << cur << endl;
    for (int i = 0; i < m; ++i) {
      if (cur & (1LL << i)) {
        first_bit.push_back(i);
        //cout << "i: " << i << endl;
        break;
      }
    }
    for (int i = 0; i < basis.size(); ++i) {
      if (basis[i] & (1LL << first_bit.back())) {
        basis[i] ^= cur;
      }
    }
    basis.push_back(cur);
  }

  int brute_value = (1LL << basis.size());
  int dp_value = (1LL << (m - (int)basis.size()));
  //cerr << brute_value << " " << dp_value * (int)basis.size() << " basis: " << basis.size() << endl;

  auto get_stupid = [&] () {
    vector<int> ans(m + 1, 0);
    for (int mask = 0; mask < (1 << inp.size()); ++mask) {
      int cur_res = 0;
      for (int i = 0; i < inp.size(); ++i) {
        if (mask & (1 << i)) {
          cur_res ^= inp[i];
        }
      }
      add(ans[__builtin_popcountll(cur_res)], 1);
    }
    return ans;
  };

  auto get_brute = [&] () {
    vector<int> ans(m + 1, 0);
    for (int mask = 0; mask < (1 << basis.size()); ++mask) {
      int cur_res = 0;
      for (int i = 0; i < basis.size(); ++i) {
        if (mask & (1 << i)) {
          cur_res ^= basis[i];
        }
      }
      add(ans[__builtin_popcountll(cur_res)], mult);
    }
    return ans;
  };

  auto get_dp = [&] () {
    vector<int> ans(m + 1, 0);
    vector<char> is_based(m, false);
    for (auto x : first_bit) {
      is_based[x] = true;
    }
    int par = 0;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(basis.size() + 1, vector<int>(dp_value, 0)));
    dp[par][0][0] = mult;
    for (int i = 0; i < basis.size(); ++i) {
      int rest_mask = 0;
      for (int j = 0; j < m; ++j) {
        if (!is_based[j]) {
          rest_mask = rest_mask * 2 + (bool)(basis[i] & (1LL << j));
        }
      }
      dp[par ^ 1] = dp[par];
      for (int ones = 0; ones < basis.size(); ++ones) {
        for (int mask = 0; mask < dp_value; ++mask) {
          add(dp[par ^ 1][ones + 1][mask ^ rest_mask], dp[par][ones][mask]);
        }
      }
      par ^= 1;
    }
    for (int ones = 0; ones <= basis.size(); ++ones) {
      for (int mask = 0; mask < dp_value; ++mask) {
        add(ans[ones + __builtin_popcountll(mask)], dp[par][ones][mask]);
      }
    }
    return ans;
  };

  vector<int> ans;

  if (brute_value <= dp_value * ((int)basis.size() + 1)) {
    ans = get_brute();
  } else {
    ans = get_dp();
  }

  /*auto stupid_ans = get_stupid();

  if (ans != stupid_ans) {
    cout << "FOUND" << endl;
    exit(0);
  } else {
    cout << "ok\n";
  }*/

  if (read) {
    for (int x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  }

}