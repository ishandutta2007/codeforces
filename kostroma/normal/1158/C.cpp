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

vector<vector<int>> g;
vector<char> used;
vector<int> topsort;

void dfs(int v) {
  if (used[v]) {
    return;
  }
  used[v] = true;
  for (int to : g[v]) {
    dfs(to);
  }
  topsort.push_back(v);
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<int> nex(n);
  for (int i = 0; i < n; ++i) {
    cin >> nex[i];
    if (nex[i] != -1) {
      --nex[i];
    }
  }
  int shift = 1;
  while (shift < n) {
    shift *= 2;
  }
  g.clear();
  g.resize(shift + n);
  for (int i = 0; i < shift; ++i) {
    for (int h = 0; h < 2; ++h) {
      int v = 2 * i + h;
      if (v < g.size()) {
        g[v].push_back(i);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (nex[i] == -1) {
      continue;
    }
    int l = i + 1 + shift, r = nex[i] + shift;
    while (l < r) {
      if (l & 1) {
        g[l].push_back(i + shift);
        ++l;
        continue;
      }
      if (r & 1) {
        --r;
        g[r].push_back(i + shift);
        continue;
      }
      l /= 2;
      r /= 2;
    }
    if (nex[i] < n) {
      g[i + shift].push_back(nex[i] + shift);
    }
  }
  used.assign(n + shift, false);
  topsort.clear();
  for (int i = 0; i < used.size(); ++i) {
    if (!used[i]) {
      dfs(i);
    }
  }
  reverse(all(topsort));
  vector<int> ans(n);
  int cnt = 0;
  vector<int> ind(n + shift);
  for (int i = 0; i < topsort.size(); ++i) {
    ind[topsort[i]] = i;
  }
  for (int i = 0; i < g.size(); ++i) {
    for (int to : g[i]) {
      if (ind[to] < ind[i]) {
        cout << "-1\n";
        return;
      }
    }
  }
  for (int v : topsort) {
    if (v >= shift && v < shift + n) {
      ans[v - shift] = cnt++;
    }
  }
  for (int x : ans) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}