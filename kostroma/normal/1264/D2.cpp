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

const int C = 1000500;
int fact[C], rev_fact[C];

int get_c(int n, int k) {
  if (n < 0 || k > n || k < 0) {
    return 0;
  }
  return fact[n] * rev_fact[k] % mod * rev_fact[n - k] % mod;
}

void solve(__attribute__((unused)) bool read) {
  fact[0] = 1;
  for (int i = 1; i < C; ++i) {
    fact[i] = fact[i - 1] * i % mod;
  }
  rev_fact[C - 1] = binpow(fact[C - 1], mod - 2, mod);
  for (int i = C - 2; i >= 0; --i) {
    rev_fact[i] = rev_fact[i + 1] * (i + 1) % mod;
  }

  string s;
  //read = false;
  if (read) {
    cin >> s;
  } else {
    for (int i = 0; i < 1000000; ++i) {
      s += "()?"[rand() % 3];
    }
  }
  int open = 0, close = 0, qs = 0;
  for (char c : s) {
    if (c == '?') {
      ++qs;
    } else if (c == '(') {
      ++open;
    } else if (c == ')') {
      ++close;
    }
  }
  int pref_open = 0, pref_close = 0, pref_qs = 0;
  int res = 0;
  vector<int> powers(s.length() + 1, 1);
  for (int i = 1; i < powers.size(); ++i) {
    powers[i] = powers[i - 1] * 2 % mod;
  }
  vector<pair<int, int>> qus;
  for (int i = 0; i < s.length(); ++i) {
    pref_close += (s[i] == ')');

    int q1 = pref_qs;
    pref_qs += (s[i] == '?');

    int q2 = qs - pref_qs;
    int p1 = pref_open;

    pref_open += (s[i] == '(');
    int suf_close = close - pref_close;
    int p2 = suf_close;
    if (s[i] != ')') {
      int from = q1 + q2;
      int to = q2 + p2 - p1 - 1;
      qus.push_back({from, to});
      /*int cur_add = 0;
      for (int j = 0; j <= to; ++j) {
        cur_add += get_c(from, j);
      }
      //cout << p1 << " " << p2 << " " << q1 << " " << q2 << " " << cur_add << "\n";
      res += cur_add;
      res %= mod;*/
    }
  }
  sort(all(qus));
  vector<int> vec;
  for (int i = 0; i < qus.size(); ) {
    int j = i;
    vec.clear();
    while (j < qus.size() && qus[j].first == qus[i].first) {
      vec.push_back(qus[j].second);
      ++j;
    }
    sort(all(vec));
    int N = qus[i].first;
    int pref = 0;
    int last = 0;
    for (int x : vec) {
      while (last <= x) {
        pref = (pref + get_c(N, last)) % mod;
        ++last;
      }
      res = (res + pref) % mod;
    }
    i = j;
  }
  cout << res << "\n";
}