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
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; ++i) {
    int x = i * 3, y = 0;
    ans.emplace_back(x, y);
    for (int d = 0; d < 4; ++d) {
      ans.emplace_back(x + dx[d], y + dy[d]);
    }
  }
  int lef = -2, rig = 3 * (n - 1) + 2;
  vector<pair<int, int>> ends;
  ends.emplace_back(lef, 0);
  for (int i = 0; i < n; ++i) {
    int x = i * 3, y = 0;
    ends.emplace_back(x, 2);
  }
  ends.emplace_back(rig, 0);
  for (int i = n - 1; i >= 0; --i) {
    int x = i * 3, y = 0;
    ends.emplace_back(x, -2);
  }
  assert(ends.size() % 2 == 0);
  for (int i = 0; i < ends.size(); i += 2) {
    auto fs = ends[i], sc = ends[i + 1];
    if (fs.second == sc.second) {
      for (int j = min(fs.first, sc.first); j <= max(fs.first, sc.first); ++j) {
        ans.emplace_back(j, fs.second);
      }
    } else {
      int min_x = min(fs.first, sc.first);
      int min_y = min(fs.second, sc.second);
      for (int d1 = 0; d1 < 3; ++d1) {
        for (int d2 = 0; d2 < 3; ++d2) {
          if (d1 == 1 && d2 == 1) {
            continue;
          }
          ans.emplace_back(min_x + d1, min_y + d2);
        }
      }
    }
  }
  make_unique(ans);
  cout << ans.size() << "\n";
  for (auto item : ans) {
    cout << item.first << " " << item.second << "\n";
  }
}