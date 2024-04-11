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
//const int mod = 998244353;
//using ull = unsigned long long;

int get_bit(li num, int bit) {
  return (int)(bool)(num & (1LL << bit));
}

const int C = 1000500;
li scores_single[C][2];
li scores_double[C][2][2];

void solve(__attribute__((unused)) bool read) {
  int n;
  li k;
  //read = false;
  if (read) {
    cin >> n >> k;
  } else {
    n = rand() % 10 + 1;
    //n = 1000000;
    k = n * 1LL * n;
    k = ((rand() * (1LL << 32)) | rand()) % (n * n) + 1;
    //k = 1;
  }
  auto K = k;
  //cout << n << " " << k << endl;
  vector<li> xors(n, 0);
  for (int i = 1; i < n; ++i) {
    int p;
    li w;
    if (read) {
      cin >> p >> w;
      --p;
    } else {
      p = i - 1;
      w = (((li)rand() * (1LL << 32)) | (li)rand()) % (1LL << 10);
    }
    xors[i] = xors[p] ^ w;
  }
  int comps = 1;
  vector<int> in_second(n, 0);
  vector<int> num_comp(n, 0);
  li res = 0;
  vector<vector<int>> has_in_comp;
  for (int bit = 61; bit >= 0; --bit) {
    //cout << "start: " << res << endl;
    if (res == 0) {
      for (int i = 0; i < comps; ++i) {
        for (int j = 0; j < 2; ++j) {
          scores_single[i][j] = 0;
        }
      }
      for (int i = 0; i < n; ++i) {
        int val = get_bit(xors[i], bit);
        int c = num_comp[i];
        assert(c != -1);
        ++scores_single[c][val];
      }
      li zeros = 0;
      for (int i = 0; i < comps; ++i) {
        for (int r = 0; r < 2; ++r) {
          zeros += scores_single[i][r] * scores_single[i][r];
        }
      }
      int cur_val;
      if (zeros >= k) {
        cur_val = 0;
      } else {
        k -= zeros;
        cur_val = 1;
      }
      res = res * 2 + cur_val;
      if (cur_val == 0) {
        has_in_comp.assign(2, vector<int>(comps, -1));
        for (int i = 0; i < n; ++i) {
          int c = num_comp[i];
          int val = get_bit(xors[i], bit);
          if (has_in_comp[val][c] != -1) {
            num_comp[i] = has_in_comp[val][c];
          } else if (has_in_comp[val ^ 1][c] == -1) {
            has_in_comp[val][c] = num_comp[i];
          } else {
            num_comp[i] = comps++;
            has_in_comp[val][c] = num_comp[i];
          }
        }
      } else {
        for (int i = 0; i < n; ++i) {
          int c = num_comp[i];
          int val = get_bit(xors[i], bit);
          in_second[i] = val;
        }
      }
      continue;
    }
    for (int i = 0; i < comps; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int r = 0; r < 2; ++r) {
          scores_double[i][j][r] = 0;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      int val = get_bit(xors[i], bit);
      int c = num_comp[i];
      if (c == -1) {
        continue;
      }
      ++scores_double[c][in_second[i]][val];
    }
    li zeros = 0;
    for (int i = 0; i < comps; ++i) {
      for (int j = 0; j < 2; ++j) {
        zeros += scores_double[i][0][j] * scores_double[i][1][j] * 2;
      }
    }
    int cur_val;
    if (zeros >= k) {
      cur_val = 0;
    } else {
      k -= zeros;
      cur_val = 1;
    }
    res = res * 2 + cur_val;
    has_in_comp.assign(2, vector<int>(comps, -1));
    for (int i = 0; i < n; ++i) {
      int c = num_comp[i];
      if (c == -1) {
        continue;
      }
      int val = get_bit(xors[i], bit);
      if (!in_second[i]) {
        if (has_in_comp[val][c] != -1) {
          num_comp[i] = has_in_comp[val][c];
        } else if (has_in_comp[val ^ 1][c] == -1) {
          has_in_comp[val][c] = num_comp[i];
        } else {
          num_comp[i] = comps++;
          has_in_comp[val][c] = num_comp[i];
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      int c = num_comp[i];
      if (c == -1) {
        continue;
      }
      int val = get_bit(xors[i], bit);
      if (in_second[i]) {
        val ^= cur_val;
        num_comp[i] = has_in_comp[val][c];
      }
    }
  }

  cout << res << endl;
  return;

  cout << "res: " << res << endl;

  vector<int> vals;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int cur_res = xors[i] ^ xors[j];
      vals.push_back(cur_res);
    }
  }
  sort(all(vals));
  cout << "stupid: " << vals[K - 1] << endl;
  if (vals[K - 1] != res) {
    cout << "test:" << endl;
    cout << n << " " << K << endl;
    for (int x : xors) {
      cout << x << " ";
    }
    cout << endl;
  }
  assert(vals[K - 1] == res);

}