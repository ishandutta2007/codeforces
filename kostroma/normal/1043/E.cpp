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
//const int mod = 1000000007;

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> x(2, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    cin >> x[0][i] >> x[1][i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    for (int to : g[i]) {
      int score = min(x[0][i] + x[1][to], x[0][to] + x[1][i]);
      res[i] -= score;
    }
  }
  vector<int> perm(n);
  iota(all(perm), 0);
  sort(all(perm), [&] (int q, int w) {
    return x[0][q] - x[1][q] < x[0][w] - x[1][w];
  });
  int cnt_small = 0, cnt_large = n;
  vector<int> sums_small(2, 0), sums_large(2, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      sums_large[j] += x[j][i];
    }
  }
  for (int it = 0; it < n; ++it) {
    int cur = perm[it];
    --cnt_large;
    for (int j = 0; j < 2; ++j) {
      sums_large[j] -= x[j][cur];
    }
    res[cur] += sums_small[0] + sums_large[1];
    res[cur] += x[1][cur] * cnt_small + x[0][cur] * cnt_large;
    ++cnt_small;
    for (int j = 0; j < 2; ++j) {
      sums_small[j] += x[j][cur];
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " \n"[i + 1 == n];
  }
}