#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>
#ifdef AIM
#include <sys/resource.h>
#endif
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
  string s = FILENAME;
//    assert(!s.empty());
  freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
//freopen("/home/alexandero/ClionProjects/cryptozoology/output.txt", "w", stdout);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif

#ifdef AIM
  const rlim_t kStackSize = 256 * 1024 * 1024;
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

  precalc();
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  int testNum = 1;
  while (t--) {
      //cout << "Case #" << testNum++ << ": ";
      solve(true);
  }
  cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
  cout.flush();
  auto end = clock();

  usleep(10000);
  print_stats(end - start);
  usleep(10000);
#endif

    return 0;
}

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
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {
}

//#define int li
//const int mod = 1000000007;

const int C = 300300;
int lp[C];
int fred[C];
bool done[C];
int dp[1 << 10];

void solve(__attribute__((unused)) bool read) {
  for (int p = 2; p < C; ++p) {
    if (lp[p] == 0) {
      lp[p] = p;
      for (li j = p * 1LL * p; j < C; j += p) {
        if (lp[j] == 0) {
          lp[j] = p;
        }
      }
    }
  }
  fred[1] = 1;
  for (int i = 2; i < C; ++i) {
    int p = lp[i];
    if ((i / p) % p == 0) {
      fred[i] = fred[i / p];
    } else {
      fred[i] = fred[i / p] * p;
    }
    /*if (i < 100) {
      cout << i << " " << fred[i] << endl;
    }*/
  }

  auto get_divisors = [&] (int val) {
    vector<int> divs = {1};
    while (val > 1) {
      int p = lp[val];
      int cnt = 0;
      while (val % p == 0) {
        ++cnt;
        val /= p;
      }
      int sz = divs.size();
      for (int i = 0; i < sz; ++i) {
        int cur = divs[i];
        for (int j = 0; j < cnt; ++j) {
          cur *= p;
          divs.push_back(cur);
        }
      }
    }
    return divs;
  };

  //read = false;
  int n;
  if (read) {
    cin >> n;
  } else {
    n =300000;
  }
  vector<int> a(n);
  vector<int> score(C, 0);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = rand() % 300000 + 2;
    }
    a[i] = fred[a[i]];
    auto divs = get_divisors(a[i]);
    for (int x : divs) {
      ++score[x];
    }
  }
  const int INF = (int)1e9;
  int res = INF;

  for (int val : a) {
    if (done[val]) {
      continue;
    }
    done[val] = true;
    vector<int> primes;
    while (val > 1) {
      primes.push_back(lp[val]);
      val /= lp[val];
    }
    vector<int> scores(1 << primes.size()), cnt(1 << primes.size(), 0), num(1 << primes.size(), 0);
    for (int mask = 0; mask < (1 << primes.size()); ++mask) {
      dp[mask] = INF;
      int prod = 1;
      for (int i = 0; i < primes.size(); ++i) {
        if (mask & (1 << i)) {
          ++cnt[mask];
          prod *= primes[i];
        }
      }
      scores[mask] = score[prod];
    }
    for (int mask = 0; mask < (1 << primes.size()); ++mask) {
      for (int s = mask; ; s = (s - 1) & mask) {
        if (cnt[s] & 1) {
          num[mask] -= scores[s];
        } else {
          num[mask] += scores[s];
        }
        if (s == 0) {
          break;
        }
      }
    }
    int full_mask = (1 << primes.size()) - 1;
    dp[full_mask] = 1;
    for (int mask = full_mask; mask >= 0; --mask) {
      for (int s = mask; ; s = (s - 1) & mask) {
        if (num[s] > 0) {
          relax_min(dp[mask ^ s], dp[mask] + 1);
        }
        if (s == 0) {
          break;
        }
      }
    }
    //cout << val << " " << dp[0] << endl;
    relax_min(res, dp[0]);
  }
  if (res == INF) {
    res = -1;
  }
  cout << res << "\n";
}