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
const int mod = 31607;
//using ull = unsigned long long;

void add(int& cur, int delta) {
  cur = (cur + delta) % mod;
}

const int N = 21;
int products[N][1 << N];

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 21;
  }
  vector<vector<int>> a(n, vector<int>(n));
  //cout << binpow(100LL, mod - 2LL, (li)mod) << endl;
  int rev_down = binpow(10000LL, mod - 2LL, (li)mod);
  for (auto& vec : a) {
    for (auto& x : vec) {
      if (read) {
        cin >> x;
      } else {
        x = rand() % 9999 + 1;
      }
      x = x * rev_down % mod;
    }
  }
  int res = 0;
  {
    int pref_prod = 1;
    for (int i = 0; i < n; ++i) {
      int prod = 1;
      for (int x : a[i]) {
        prod = prod * x % mod;
      }
      add(res, pref_prod * prod);
      pref_prod = pref_prod * (mod + 1 - prod) % mod;
    }
  }

  //cout << "raw_res: " << res << endl;

  vector<int> col_prods(n, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      col_prods[j] = col_prods[j] * a[i][j] % mod;
    }
  }
  vector<int> col_mask_prods(1 << n, 1);
  for (int mask = 1; mask < (1 << n); ++mask) {
    int bit = __builtin_ctz(mask);
    col_mask_prods[mask] = col_mask_prods[mask ^ (1 << bit)] * col_prods[bit] % mod;
  }

  vector<int> to_conv(1 << (n + 2), 0);
  for (int d1 = 0; d1 < 2; ++d1) {
    for (int d2 = 0; d2 < 2; ++d2) {
      memset(products, 0, sizeof(products));
      for (int i = 0; i < n; ++i) {
        products[i][0] = 1;
        for (int mask = 1; mask < (1 << n); ++mask) {
          int bit = __builtin_ctz(mask);
          products[i][mask] = products[i][mask ^ (1 << bit)];
          if ((i == bit && d1) || (i + bit == n - 1 && d2)) {
            continue;
          } else {
            products[i][mask] = products[i][mask] * a[i][bit] % mod;
          }
        }
        for (int mask = 0; mask < (1 << n); ++mask) {
          int fixed = 1;
          bool is_on_diag = (d1 && (mask & (1 << i)));
          if (is_on_diag) {
            fixed = fixed * a[i][i] % mod;
          }
          if (d2 && (mask & (1 << (n - i - 1))) && (!is_on_diag || i != n - i - 1)) {
            fixed = fixed * a[i][n - i - 1] % mod;
          }
          products[i][mask] = fixed * (mod + 1 - products[i][mask]) % mod;
        }
      }
      for (int mask = 0; mask < (1 << n); ++mask) {
        int cur_prod = 1;
        int rev_mask = (1 << n) - 1 - mask;
        for (int i = 0; i < n; ++i) {
          cur_prod = cur_prod * products[i][rev_mask] % mod;
        }
        add(to_conv[mask * 4 + d1 * 2 + d2], cur_prod * col_mask_prods[mask]);
      }
    }
  }
//  auto old = to_conv;
  for (int b = 0; b < n + 2; ++b) {
    for (int mask = 0; mask < to_conv.size(); ++mask) {
      if (mask & (1 << b)) {
        add(to_conv[mask ^ (1 << b)], mod - to_conv[mask]);
      }
    }
  }
  /*for (int mask = 0; mask < to_conv.size(); ++mask) {
    int s = 0;
    for (int m = 0; m < to_conv.size(); ++m) {
      if ((m & mask) == mask) {
        add(s, to_conv[m]);
      }
    }
    cout << old[mask] << " " << s << endl;
    assert(s == old[mask]);
  }*/

  /*{
    vector<int> stupid(1 << (n + 2), 0);
    int raw_prob = 0;
    for (int ma = 0; ma < (1 << (n * n)); ++ma) {
      vector<vector<int>> matrix(n, vector<int>(n, 0));
      bool f = true;
      int prob = 1;
      for (int i = 0; i < n; ++i) {
        bool is_good = true;
        for (int j = 0; j < n; ++j) {
          matrix[i][j] = (bool)(ma & (1 << (i * n + j)));
          if (!matrix[i][j]) {
            is_good = false;
            prob = prob * (mod + 1 - a[i][j]) % mod;
          } else {
            prob = prob * a[i][j] % mod;
          }
        }
        if (is_good) {
          f = false;
        }
      }
      if (!f) {
        add(raw_prob, prob);
        continue;
      }
      int mask = 0;
      for (int i = 0; i < n; ++i) {
        bool is_good = true;
        for (int j = 0; j < n; ++j) {
          if (!matrix[j][i]) {
            is_good = false;
            break;
          }
        }
        if (is_good) {
          mask |= (1 << (i + 2));
        }
      }
      int d1 = 1, d2 = 1;
      for (int i = 0; i < n; ++i) {
        if (!matrix[i][i]) {
          d1 = 0;
        }
        if (!matrix[i][n - i - 1]) {
          d2 = 0;
        }
      }
      mask += d1 * 2 + d2;
      //cout << mask << " " << prob << endl;
      add(stupid[mask], prob);
    }

    cout << "raw_prob: " << raw_prob << endl;
    for (int i = 0; i < stupid.size(); ++i) {
      if (stupid[i] != to_conv[i]) {
        cout << "mask: " << i << " stupid: " << stupid[i] << " res: " << to_conv[i] << endl;
      }
    }
  }*/

  for (int mask = 1; mask < to_conv.size(); ++mask) {
    add(res, to_conv[mask]);
  }

  cout << res << "\n";
}