#pragma comment(linker, "/STACK:512000000")
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
const int mod = 998244353;

vector<int> dp_finish, dp_root, dp_will;
vector<vector<int>> g;

void add(int& cur, int val) {
  cur += val;
  cur %= mod;
}

void dfs(int v) {
  if (g[v].empty()) {
    dp_root[v] = 1;
    return;
  }
  for (int to : g[v]) {
    dfs(to);
  }
  vector<int> cur_dp(3, 0);
  cur_dp[0] = 1;
  for (int to : g[v]) {
    vector<int> new_dp(3, 0);
    for (int deg = 0; deg < 3; ++deg) {
      add(new_dp[deg], cur_dp[deg] * (dp_root[to] + dp_finish[to]));
      add(new_dp[min(2LL, deg + 1)], cur_dp[deg] * (dp_will[to] + dp_root[to]));
    }
    cur_dp.swap(new_dp);
  }
  add(dp_finish[v], cur_dp[0]);
  add(dp_root[v], cur_dp[2]);
  add(dp_will[v], cur_dp[1]);
  //cout << v + 1 << " " << dp_root[v] << " " << dp_will[v] << " " << dp_finish[v] << endl;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  dp_finish.assign(n, 0);
  dp_root.assign(n, 0);
  dp_will.assign(n, 0);
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    g[p].push_back(i);
  }
  dfs(0);
  cout << (dp_root[0] + dp_finish[0]) % mod << endl;
}