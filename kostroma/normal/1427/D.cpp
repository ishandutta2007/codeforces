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

//#define int li
//const int mod = 1000000007;

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int& x : p) {
    cin >> x;
    --x;
  }

  vector<vector<int>> ans;

  auto perform = [&] (vector<int> d) {
    while (!d.empty() && d.back() == 0) {
      d.pop_back();
    }
    assert(!d.empty());
    if (d.size() == 1) {
      assert(d[0] == n);
      return;
    }
    ans.push_back(d);
    reverse(all(d));
    vector<int> res_p;
    for (int x : d) {
      vector<int> vec;
      for (int j = 0; j < x; ++j) {
        vec.push_back(p.back());
        p.pop_back();
      }
      reverse(all(vec));
      for (int x : vec) {
        res_p.push_back(x);
      }
    }
    p.swap(res_p);
  };

  for (int have = 0; have + 1 < n; ++have) {
    if (have % 2 == 0) {
      for (int i = 0; i < n; ++i) {
        if (p[i] == have) {
          vector<int> ops(have, 1);
          ops.push_back(i + 1 - have);
          ops.push_back(n - i - 1);
          perform(ops);
          break;
        }
      }
    } else {
      for (int i = 0; i < n; ++i) {
        if (p[i] == have) {
          vector<int> ops;
          if (i) {
            ops.push_back(i);
          }
          ops.push_back(n - have - i);
          for (int j = 0; j < have; ++j) {
            ops.push_back(1);
          }
          perform(ops);
          break;
        }
      }
    }
  }
  if (p[0] != 0) {
    perform(vector<int>(n, 1));
  }

  for (int i = 0; i < n; ++i) {
    assert(p[i] == i);
  }
  assert(ans.size() <= n);

  cout << ans.size() << "\n";
  for (auto& vec : ans) {
    cout << vec.size() << " ";
    for (int x : vec) {
      cout << x << " ";
    }
    cout << "\n";
  }

}