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

#define int li
//const int mod = 1000000007;

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  map<int, int> powers;
  vector<int> rest;
  set<int> all_primes;
  for (int i = 0; i < n; ++i) {
    int cur;
    cin >> cur;
    bool found = false;
    set<int> new_primes;
    for (int l = 4; l >= 2; --l) {
      auto val = powl(cur, (ld)1.0 / l);
      val = max((ld)0., val - 3);
      int now = (int)val;
      bool f = false;
      while (true) {
        int cur_val = 1;
        for (int j = 0; j < l; ++j) {
          cur_val *= now;
        }
        if (cur_val > cur) {
          f = false;
          break;
        }
        if (cur_val == cur) {
          f = true;
          break;
        }
        ++now;
      }
      if (f) {
        powers[now] += l;
        new_primes.insert(now);
        found = true;
        break;
      }
    }
    if (!found) {
      int a = -1, b = -1;
      for (auto p : all_primes) {
        if (cur % p == 0) {
          a = p;
          b = cur / p;
          break;
        }
      }
      for (auto prev_val : rest) {
        auto g = gcd(prev_val, cur);
        if (g > 1 && g < cur) {
          a = g;
          b = cur / g;
          break;
        }
      }
      if (a != -1) {
        new_primes.insert(a);
        new_primes.insert(b);
      }
      rest.push_back(cur);
    }
    vector<int> q_primes;
    for (auto p : new_primes) {
      q_primes.push_back(p);
    }
    for (int u = 0; u < q_primes.size(); ++u) {
      int p = q_primes[u];
      vector<int> new_rest;
      for (auto prev_val : rest) {
        if (prev_val % p == 0) {
          powers[p] += 1;
          int q = prev_val / p;
          if (!new_primes.count(q)) {
            new_primes.insert(q);
            q_primes.push_back(q);
          }
          powers[q] += 1;
        } else {
          new_rest.push_back(prev_val);
        }
      }
      rest.swap(new_rest);
      all_primes.insert(p);
    }
  }

  int res = 1;
  const int mod = 998244353;
  map<int, int> from_rest;
  for (int i = 0; i < rest.size(); ++i) {
    from_rest[rest[i]]++;
  }
  for (auto item : from_rest) {
    res = res * (item.second + 1) % mod * (item.second + 1) % mod;
  }
  for (auto item : powers) {
    res = res * (item.second + 1) % mod;
  }
  cout <<res << endl;

}