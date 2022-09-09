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

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;


li dp[2][12][1 << 12];

void solve(__attribute__((unused)) bool read) {
  int n;
  li k;
  //read = false;
  if (read) {
    cin >> n >> k;
  } else {
    n = 1e6;
    k = (li)1e12;
  }
  vector<li> a(n), cost(n);
  li g = 0;
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = 200560490130LL;
      //a[i] = 2 * 3 * 5 * 7 * 11 * 13 * (rand() % (int)1e7 + 1);
    }
    g = gcd(a[i], g);
  }
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> cost[i];
    } else {
      cost[i] = rand();
    }
  }
  vector<li> primes;
  for (li p = 2; p * p <= g; ++p) {
    if (g % p == 0) {
      primes.push_back(p);
      while (g % p == 0) {
        g /= p;
      }
    }
  }
  if (g > 1) {
    primes.push_back(g);
  }
  if (primes.empty()) {
    cout << "0\n";
    return;
  }
  vector<pair<li, li>> mapa;
  for (int i = 0; i < n; ++i) {
    li cur_val = 1;
    for (int j = 0; j < primes.size(); ++j) {
      auto p = primes[j];
      while (a[i] % p == 0) {
        a[i] /= p;
        cur_val *= p;
      }
    }
    mapa.push_back({cur_val, cost[i]});
    /*mapa[vec].push_back(cost[i]);
    auto it = actual_val.find(vec);
    if (it == actual_val.end()) {
      actual_val[vec] = cur_val;
    }*/
  }
  sort(all(mapa));
  vector<vector<li>> vecs;
  vector<li> costs;
  for (int i = 0; i < mapa.size(); ) {
    int j = i;
    vector<li> vec;
    auto cur_val = mapa[i].first;
    vector<li> key(primes.size(), 1);
    for (int r = 0; r < primes.size(); ++r) {
      while (cur_val % primes[r] == 0) {
        cur_val /= primes[r];
        key[r] *= primes[r];
      }
    }
    while (j < mapa.size() && mapa[j].first == mapa[i].first) {
      vec.push_back(mapa[j].second);
      ++j;
    }
    i = j;
    int enough_space = 0;
    li cur_prod = 1;
    for (li x : key) {
      if (x > k) {
        continue;
      }
      if (x * cur_prod <= k) {
        if (cur_prod == 1) {
          ++enough_space;
        }
        cur_prod *= x;
        continue;
      } else {
        ++enough_space;
        cur_prod = x;
      }
    }
    if (vec.size() > enough_space) {
      vec.resize(enough_space);
    }
    for (li c : vec) {
      vecs.push_back(key);
      costs.push_back(c);
    }
  }
  const li INF = (li)1e18;
  int full_mask = (1 << primes.size()) - 1;

  auto clear_dp = [&] (int par) {
    for (int cnt = 0; cnt <= primes.size(); ++cnt) {
      for (int mask = 0; mask <= full_mask; ++mask) {
        dp[par][cnt][mask] = INF;
      }
    }
  };

  //vector<vector<vector<int>>> dp(2, vector<vector<int>>(primes.size() + 1, vector<int>(full_mask + 1, INF)));
  int par = 0;
  for (int i = 0; i < 2; ++i) {
    clear_dp(i);
  }
  dp[par][0][full_mask] = 0;
  //cout << "sz: " << vecs.size() << " dp_size: " << (int)vecs.size() * (int)primes.size() * full_mask << endl;
  vector<li> prods;
  for (int i = 0; i < vecs.size(); ++i) {
    //clear_dp(par ^ 1);
    //dp[par ^ 1].assign(primes.size() + 1, vector<int>(full_mask + 1, INF));
    for (int cnt = 0; cnt <= primes.size(); ++cnt) {
      for (int mask = 0; mask <= full_mask; ++mask) {
        dp[par ^ 1][cnt][mask] = dp[par][cnt][mask];
      }
    }
    prods.assign(1 << primes.size(), 1);
    for (int mask = 0; mask < (1 << primes.size()); ++mask) {
      for (int j = 0; j < primes.size(); ++j) {
        if (mask & (1 << j)) {
          prods[mask] *= vecs[i][j];
        }
      }
    }
    for (int cnt = 0; cnt <= primes.size(); ++cnt) {
      for (int mask = 0; mask <= full_mask; ++mask) {
        li cur_dp = dp[par][cnt][mask];
        if (cur_dp == INF) {
          continue;
        }
        for (int s = mask; s > 0; s = (s - 1) & mask) {
          li prod = prods[s];
          if (prod <= k) {
            relax_min(dp[par ^ 1][cnt + 1][mask ^ s], cur_dp + costs[i]);
          }
        }
      }
    }
    par ^= 1;
  }

  li res = INF;
  for (int cnt = 0; cnt <= primes.size(); ++cnt) {
    li cur_dp = dp[par][cnt][0];
    if (cur_dp == INF) {
      continue;
    }
    relax_min(res, cnt * cur_dp);
  }
  if (res == INF) {
    res = -1;
  }
  cout << res << "\n";

}