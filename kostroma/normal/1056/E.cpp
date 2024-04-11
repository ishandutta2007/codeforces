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

const int INF = 1000000000;

int my_rand() {
  return rand() % 1000000 + INF;
}

bool is_prime(int cur) {
  for (int i = 2; i * i <= cur; ++i) {
    if (cur % i == 0) return false;
  }
  return true;
}

void solve(__attribute__((unused)) bool read) {
  srand((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());
  string s, t;
  if (read) {
    cin >> s >> t;
  } else {
    int z = 0, o = 0;
    do {
      s = string(rand() % 100 + 2, '0');
      z= 0; o = 0;
      for (int i = 0; i < s.length(); ++i) {
        if (rand() & 1) {
          s[i] = '1';
          ++o;
        } else {
          ++z;
        }
      }
    } while (z == 0 || o == 0);

    t = string(rand() % 100 + 1, 'a');
    for (int i = 0; i < t.length(); ++i) {
      t[i] += rand() % 26;
    }
  }
  if (s[0] == '1') {
    for (char& c : s) {
      if (c == '0') {
        c = '1';
      } else {
        c = '0';
      }
    }
  }
  int zeros = 0, ones = 0;
  for (char c : s) {
    if (c == '0') {
      ++zeros;
    } else {
      ++ones;
    }
  }
  vector<int> mods;
  for (int w = 0; w < 2; ++w) {
    mods.push_back(my_rand());
    while (!is_prime(mods.back())) {
      ++mods.back();
    }
    if (w == 1 && mods[1] == mods[0]) {
      mods.pop_back();
      --w;
    }
  }
  vector<int> pr = {31, 2017};
  vector<vector<int>> hashes(2, vector<int>(t.length() + 1, 0));
  vector<vector<int>> powers(2, vector<int>(t.length() + 1, 1));
  for (int w = 0; w < 2; ++w) {
    for (int i = 0; i < t.length(); ++i) {
      hashes[w][i + 1] = (hashes[w][i] * pr[w] + t[i]) % mods[w];
      powers[w][i + 1] = powers[w][i] * pr[w] % mods[w];
    }
  }
  auto get_hash = [&] (int l, int r) {
    int res = 0;
    for (int w = 0; w < 2; ++w) {
      int cur = hashes[w][r] - hashes[w][l] * powers[w][r - l];
      cur %= mods[w];
      if (cur < 0) {
        cur += mods[w];
      }
      res <<= 32;
      res |= cur;
    }
    return res;
  };

  vector<int> nums;
  for (int i = 0; i < s.length(); ++i) {
    int j = i;
    while (j < s.length() && s[j] == '0') {
      ++j;
    }
    nums.push_back(j - i);
    i = j;
  }
  int ans = 0;
  for (int len = 1; len <= t.length(); ++len) {
    int rest = (int)t.length() - len * zeros;
    if (rest <= 0 || rest % ones) {
      continue;
    }
    int rest_len = rest / ones;
    int fixL = len * nums[0];
    int fixR = fixL + rest_len;
    int pos = 0;
    bool f = true;
    for (int x : nums) {
      if (x > 0 && get_hash(0, len) != get_hash(pos, pos + len)) {
        f = false;
        break;
      }
      if (x > 0 && get_hash(pos, pos + (x - 1) * len) != get_hash(pos + len, pos + x * len)) {
        f = false;
        break;
      }
      pos += x * len;
      if (pos < t.length()) {
        if (get_hash(fixL, fixR) != get_hash(pos, pos + rest_len)) {
          f = false;
          break;
        }
      }
      pos += rest_len;
    }
    if (f) {
      if (len != rest_len || get_hash(fixL, fixL + rest_len) != get_hash(0, len)) {
        ++ans;
      }
    }
  }
  cout << ans << endl;
}