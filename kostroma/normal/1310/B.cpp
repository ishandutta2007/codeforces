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

const int INF = (int)1e9;

vector<int> get_dp(vector<int> a) {
  vector<int> res(4, -INF);
  if (a.size() == 2) {
    if (a[0] != a[1]) {
      res[1] = res[2] = 1;
    } else if (a[0]) {
      res[3] = 1;
    } else {
      res[0] = 0;
    }
    return res;
  }
  int mid = (int)a.size() / 2;
  auto lef_dp = get_dp(vector<int>(a.begin(), a.begin() + mid));
  auto rig_dp = get_dp(vector<int>(a.begin() + mid, a.end()));
  for (int m1 = 0; m1 < 4; ++m1) {
    for (int m2 = 0; m2 < 4; ++m2) {
      int new_m = (m1 | m2);
      if (lef_dp[m1] < 0 || rig_dp[m2] < 0) {
        continue;
      }
      int new_dp_val = lef_dp[m1] + rig_dp[m2];
      for (int j = 0; j < 2; ++j) {
        if (new_m & (1 << j)) {
          ++new_dp_val;
        }
      }
      if (new_m & 2) {
        ++new_dp_val;
      }
      /*if (new_m == 3 && (m1 != 3 || m2 != 3)) {
        ++new_dp_val;
      }*/
      //cout << m1 << " " << m2 << " " << new_dp_val << endl;
      relax_max(res[new_m], new_dp_val);
    }
  }
  /*cout << "vals: ";
  for (int x : a) {
    cout << x;
  }
  cout << endl;
  cout << "res: ";
  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;*/
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << "0\n";
    return;
  }
  vector<int> a(k);
  vector<int> have(1 << n);
  for (int& x : a) {
    cin >> x;
    --x;
    have[x] = 1;
  }
  auto res = get_dp(have);
  int mx = *max_element(all(res));
  cout << mx + 1 << endl;
}