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
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 200000;
  }
  vector<int> a(n);
  vector<int> cnt;
  int zz = 0;
  for (int& x : a) {
    if (read) {
      cin >> x;
      --x;
    } else {
      x = rand() % 100;
      if (zz % 3 == 0) {
        x = 0;
      }
      ++zz;
    }
    while (cnt.size() <= x) {
      cnt.push_back(0);
    }
    ++cnt[x];
  }
  int best = 0;
  for (int i = 0; i < cnt.size(); ++i) {
    if (cnt[i] > cnt[best]) {
      best = i;
    }
  }
  for (int i = 0; i < cnt.size(); ++i) {
    if (i != best && cnt[i] == cnt[best]) {
      cout << n << "\n";
      return;
    }
  }
  const int C = 100;
  vector<int> pref_count(C, 0);
  vector<vector<pair<int, int>>> dp(cnt.size());
  for (int i = 0; i < n; ++i) {
    ++pref_count[a[i]];
    if (a[i] == best) {
      for (int j = 0; j < cnt.size(); ++j) {
        int val = pref_count[best] - pref_count[j];
        if (val > 0) {
          dp[j].emplace_back(i, val);
        }
      }
    }
  }
  vector<pair<int, int>> sorted;
  for (int i = 0; i < dp.size(); ++i) {
    sorted.clear();
    for (auto item : dp[i]) {
      if (sorted.empty() || item.second > sorted.back().second) {
        sorted.push_back(item);
      }
    }
    dp[i].swap(sorted);
  }
  int res = 0;
  for (int i = n - 1; i >= 0; --i) {
    bool is_good = false;
    for (int j = 0; j < cnt.size(); ++j) {
      if (j != best && cnt[j] == cnt[best]) {
        relax_max(res, i + 1);
        is_good = true;
        break;
      }
    }
    if (is_good) {
      break;
    }
    for (int j = 0; j < cnt.size(); ++j) {
      if (j == best) {
        continue;
      }
      int need = cnt[best] - cnt[j];
      if (dp[j].empty() || dp[j].back().second < need) {
        continue;
      }
      int l = -1, r = (int)dp[j].size() - 1;
      while (l + 1 < r) {
        int m = (l + r) / 2;
        if (dp[j][m].second >= need) {
          r = m;
        } else {
          l = m;
        }
      }
      int lef = dp[j][r].first + 1;
      if (lef <= i) {
        relax_max(res, i - lef + 1);
      }
    }
    --cnt[a[i]];
  }
  cout << res << "\n";
}