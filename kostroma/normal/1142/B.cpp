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
  int n, m, Q;
  cin >> n >> m >> Q;
  vector<int> p(n), rev(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    rev[p[i]] = i;
  }
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    --a[i];
    a[i] = rev[a[i]];
  }
  vector<pair<int, int>> cur_dp(n, {-1, -1});
  if (n == 1) {
    for (int i = 0; i < Q; ++i) {
      cout << 1;
    }
    cout << endl;
    return;
  }
  vector<int> max_first(m, -1);
  vector<int> max_first_by_val(n, -1);
  for (int i = 0; i < m; ++i) {
    if (a[i] == 0) {
      max_first[i] = i;
      max_first_by_val[0] = i;
      continue;
    }
    max_first[i] = max_first_by_val[a[i]] = max_first_by_val[a[i] - 1];
  }
  vector<int> min_first(m, m), min_first_by_val(n, m);
  for (int i = m - 1; i >= 0; --i) {
    if (a[i] == 0) {
      min_first[i] = i;
      min_first_by_val[0] = i;
      continue;
    }
    min_first[i] = min_first_by_val[a[i]] = min_first_by_val[(a[i] + 1) % n];
  }
  vector<map<int, int>> lef(m), rig(m);
  for (int i = 0; i < m; ++i) {
    //cout << i << " " << min_first[i] << " " << max_first[i] << endl;
    int pos = min_first[i];
    if (pos != -1 && pos != m) {
      if (!lef[pos].count(a[i])) {
        lef[pos][a[i]] = -1;
      }
      relax_max(lef[pos][a[i]], i);
    }
    pos = max_first[i];
    if (pos != -1 && pos != m) {
      if (!rig[pos].count(a[i])) {
        rig[pos][a[i]] = m;
      }
      relax_min(rig[pos][a[i]], i);
      //cout << pos << " " << a[i] << " " << i << endl;
    }
  }
  vector<int> min_rig(m, m);
  map<int, int> pref_lef;
  for (int i = 0; i < m; ++i) {
    for (auto item : lef[i]) {
      if (pref_lef.count(item.first)) {
        relax_max(pref_lef[item.first], item.second);
      } else {
        pref_lef[item.first] = item.second;
      }
    }
    for (auto item : rig[i]) {
      auto it = pref_lef.find((item.first + 1 + n) % n);
      if (it == pref_lef.end()) {
        continue;
      }
      //cout << item.second << " " << it->second << endl;
      relax_min(min_rig[it->second], item.second);
    }
  }
  for (int i = m - 2; i >= 0; --i) {
    relax_min(min_rig[i], min_rig[i + 1]);
  }
  for (int i = 0; i < Q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    if (min_rig[l] < r) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;
}