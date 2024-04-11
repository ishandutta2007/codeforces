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

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

bool local = false;

int n;
vector<int> vec;
vector<int> start_vec;

int queries = 0;

int get_cnt(int l, int r) {
  ++queries;
  if (local) {
    if (rand() & 1) {
      for (int i = l; i < n; ++i) {
        vec[i] = 1 - vec[i];
      }
    } else {
      for (int i = 0; i <= r; ++i) {
        vec[i] = 1 - vec[i];
      }
    }
    int res = 0;
    for (int x : vec) {
      res += x;
    }
    return res;
  } else {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int res;
    cin >> res;
    if (res == -1) {
      exit(0);
    }
    return res;
  }
}

void output_ans(vector<int> res) {
  if (local) {
    assert(res == start_vec);
  }
  cout << "! ";
  for (int x : res) {
    cout << x;
  }
  cout << endl;
}

void solve(__attribute__((unused)) bool read) {
  queries = 0;
  int t = 0;
  if (local) {
    n = rand() % 10 + 1;
    vec.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      vec[i] = rand() & 1;
      t += vec[i];
    }
    start_vec = vec;
  } else {
    cin >> n;
    cin >> t;
  }
  if (n == 1) {
    output_ans({t});
    return;
  }
  int new_t = get_cnt(0, n - 2);
  vector<int> prefs(n, 0), sufs(n, 0);
  while (new_t == n - t) {
    ++prefs[n - 1];
    t = new_t;
    new_t = get_cnt(0, n - 2);
  }
  ++prefs[n - 2];
  vector<int> got(n, -1);
  if (new_t == n - t + 1) {
    got[n - 1] = 1;
  } else if (new_t == n - 1 - t) {
    got[n - 1] = 0;
  } else {
    assert(false);
  }
  t = new_t;
  for (int suf = n - 2; suf >= 0; --suf) {
    bool found;
    do {
      found = false;
      int y = 0;
      int b = 0;
      for (int i = suf + 1; i < n; ++i) {
        b += got[i];
      }
      int a = t - b;
      for (int pref = suf; pref < n; ++pref) {
        if ((n - suf + pref) % 2) {
          continue;
        }
        if (pref > suf) {
          y += got[pref];
        }
        int easy = b - y + (pref + 1 - a - y);
        int hard = n - suf + a - b;
        new_t = get_cnt(suf, pref);
        if (new_t == easy) {
          for (int i = suf + 1; i <= pref; ++i) {
            got[i] = 1 - got[i];
          }
          ++prefs[pref];
          found = false;
        } else {
          int val = hard - new_t;
          assert(val == 0 || val == 2);
          got[suf] = val / 2;
          ++sufs[suf];
          for (int i = suf; i < n; ++i) {
            got[i] = 1 - got[i];
          }
          found = true;
        }
        t = new_t;
        break;
      }
    } while (!found);
  }

  for (int i = 0; i < n; ++i) {
    got[i] ^= (sufs[i] & 1);
    if (i + 1 < n) {
      sufs[i + 1] += sufs[i];
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    got[i] ^= (prefs[i] & 1);
    if (i) {
      prefs[i - 1] += prefs[i];
    }
  }
  output_ans(got);

  cerr << "used " << queries << endl;

}