#pragma comment(linker, "/STACK:512000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
  cin >> t;
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

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
  }
  vector<int> color(n, -1);
  for (int d = 0; d < 10; ++d) {
    int starts[] = {n, n};
    int finishes[] = {-1, -1};
    bool f = true;
    int last_val[] = {0, 0};
    for (int i = 0; i < n; ++i) {
      if (a[i] < d) {
        if (a[i] < last_val[0]) {
          f = false;
          break;
        }
        last_val[0] = a[i];
        relax_min(starts[0], i);
        finishes[0] = i;
        color[i] = 1;
      } else if (a[i] > d) {
        if (a[i] < last_val[1]) {
          f = false;
          break;
        }
        last_val[1] = a[i];
        relax_min(starts[1], i);
        finishes[1] = i;
        color[i] = 2;
      }
    }
    for (int j = starts[1]; j < finishes[0]; ++j) {
      if (a[j] == d) {
        f = false;
        break;
      }
    }
    if (!f) {
      continue;
    }
    for (int j = finishes[0] + 1; j < n; ++j) {
      if (a[j] == d) {
        color[j] = 1;
      }
    }
    for (int j = 0; j < starts[1]; ++j) {
      if (a[j] == d) {
        color[j] = 2;
      }
    }
    for (int x : color) {
      cout << x;
    }
    cout << "\n";
    return;
  }
  cout << "-\n";
}