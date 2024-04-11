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

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

const int L = 12;

struct Sparse {
  vector<vector<int>> sparse;
  Sparse(vector<int> a) {
    sparse.assign(12, vector<int>(a.size()));
    sparse[0] = a;
    for (int i = 1; i < sparse.size(); ++i) {
      for (int j = 0; j < a.size(); ++j) {
        sparse[i][j] = sparse[i - 1][j];
        int nex = j + (1 << (i - 1));
        if (nex < a.size()) {
          relax_max(sparse[i][j], sparse[i - 1][nex]);
        }
      }
    }
  }
  int get_max(int l, int r) {
    int bit = 31 - __builtin_clz(r - l);
    return max(sparse[bit][l], sparse[bit][r - (1 << bit)]);
  }
};

const int C = 1510;
int dp[C][C];
const int INF = (int)1e9;

void solve(__attribute__((unused)) bool read) {
  int n, s, m, k;
  //read =false;
  if (read) {
    cin >> n >> s >> m >> k;
  } else {
    n = s = m = k = 1500;
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = rand() % 1000000000 + 1;
    }
  }
  auto b = a;
  sort(all(b));
  b.erase(unique(all(b)), b.end());
  vector<pair<int, int>> segs;
  for (int i = 0; i < s; ++i) {
    int l, r;
    if (read) {
      cin >> l >> r;
      --l;
      --r;
    } else {
      do {
        l = rand() % n;
        r = rand() % n;
      } while (l > r);
    }
    segs.push_back({l, r});
  }
  int L = -1, R = (int)b.size();
  while (L + 1 < R) {
    int M = (L + R) / 2;
    int border = b[M];
    vector<int> poses;
    for (int i = 0; i < n; ++i) {
      if (a[i] <= border) {
        poses.push_back(i);
      }
    }
    vector<int> max_rig(poses.size(), -1);
    iota(all(max_rig), 0);
    for (auto seg : segs) {
      auto l = lower_bound(all(poses), seg.first) - poses.begin();
      auto r = upper_bound(all(poses), seg.second) - poses.begin();
      if (l < max_rig.size()) {
        relax_max(max_rig[l], (int) r);
      }
    }
    for (int i = 1; i < max_rig.size(); ++i) {
      relax_max(max_rig[i], max_rig[i - 1]);
    }
    for (int i = 0; i <= poses.size(); ++i) {
      for (int j = 0; j <= poses.size(); ++j) {
        dp[i][j] = -INF;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < poses.size(); ++i) {
      for (int used = 0; used <= i; ++used) {
        if (dp[i][used] < 0) {
          continue;
        }
        relax_max(dp[i + 1][used], dp[i][used]);
        int nex = max_rig[i];
        if (nex != -1) {
          relax_max(dp[nex][used + 1], dp[i][used] + (nex - i));
        }
      }
    }
    bool found = false;
    for (int used = 0; used <= poses.size() && used <= m; ++used) {
      if (dp[poses.size()][used] >= k) {
        found = true;
        break;
      }
    }
    if (found) {
      R = M;
    } else {
      L = M;
    }
  }
  if (R == (int)b.size()) {
    cout << "-1\n";
  } else {
    cout << b[R] << endl;
  }
}