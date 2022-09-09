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

struct Op {
  int x, y;
  char op;
};

void solve(__attribute__((unused)) bool read) {
  vector<Op> ops;

  auto get_xor = [&] (int x, int y) {
    ops.push_back({x, y, '^'});
    return x ^ y;
  };

  auto get_sum = [&] (int x, int y) {
    ops.push_back({x, y, '+'});
    return x + y;
  };

  auto get_and = [&] (int x, int y) {
    int s = get_sum(x, y);
    int xo = get_xor(x, y);
    int n = 0;
    while ((1LL << n) <= 2 * (x & y)) {
      ++n;
    }
    for (int i = 0; i < n; ++i) {
      s = get_sum(s, xo);
      xo = get_sum(xo, xo);
    }
    return get_xor(xo, s);
  };

  //for (int X = 3; X < 1000000; X += 2) {
    ops.clear();
    int x;
    cin >> x;
    //x = X;
    while (x > 1) {
      int n = 0;
      while ((1LL << n) < x) {
        ++n;
      }
      while (x >= (1LL << (n - 1))) {
        int cur_x = x;
        for (int i = 0; i < n - 1; ++i) {
          cur_x = get_sum(cur_x, cur_x);
        }
        int cur_and = get_and(cur_x, x);
        int xorred_x = get_xor(get_sum(x, x), cur_and);
        x = get_xor(xorred_x, x);
      }
      //cout << "x: " << x << endl;
    }
    //cout << "x: " << X << " ops: " << ops.size() << "\n";
    assert(ops.size() <= 100000);
  /*}
  return;*/

  cout << ops.size() << "\n";

  for (auto op : ops) {
    cout << op.x << " " << op.op << " " << op.y << "\n";
  }

}