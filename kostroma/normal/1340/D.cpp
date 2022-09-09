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

vector<vector<int>> g;

vector<pair<int, int>> ans;

void dfs(int v, int p, int t) {
  ans.emplace_back(v, t);
  vector<int> children;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    children.push_back(to);
  }
  int d = (int)children.size();
  if (v == p) {
    for (int i = 0; i < children.size(); ++i) {
      dfs(children[i], v, t + i + 1);
    }
    return;
  }
  int a = max(d - (t - 1), 0);
  for (int i = 0; i < a; ++i) {
    dfs(children[i], v, t + i + 1);
  }
  int rest = (int)children.size() - a;
  int last_t = t - 1 - rest;
  ans.emplace_back(v, last_t);
  for (int i = a; i < children.size(); ++i) {
    ++last_t;
    dfs(children[i], v, last_t);
  }
  assert(last_t == t - 1);
  if (v != p) {
    ans.emplace_back(p, t);
  }
}

void solve(__attribute__((unused)) bool read) {
  int n;
  if (read) {
    cin >> n;
  } else {
    n = rand() % 20 + 1;
  }
  g.clear();
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
      --a;
      --b;
    } else {
      b = i;
      a = rand() % i;
    }
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ans.clear();
  dfs(0, 0, 0);
  set<pair<int, int>> used;
  cout << ans.size() << "\n";
  int mx_val = 0;
  int mx_deg = 0;
  for (int v = 0; v < n; ++v) {
    relax_max(mx_deg, (int)g[v].size());
  }
  for (int i = 0; i + 1 < ans.size(); ++i) {
    if (ans[i].first != ans[i + 1].first) {
      assert(ans[i + 1].second == ans[i].second + 1);
    } else {
      assert(ans[i + 1].second < ans[i].second);
    }
  }
  for (auto item : ans) {
    assert(!used.count(item));
    /*if(used.count(item)) {
      cout << "FOUND" << endl;
      cout << item.first + 1 << " " << item.second << endl;
      cout << "n" << endl;
      cout << n << endl;
      for (int i = 0; i < n; ++i) {
        for (int to : g[i]) {
          if (to > i) {
            cout << i + 1 << " " << to + 1 << endl;
          }
        }
      }
      exit(0);
    }*/
    used.insert(item);
    cout << item.first + 1 << " " << item.second << "\n";
    relax_max(mx_val, item.second);
  }
  assert(mx_val == mx_deg);
  //cout << "mx: " << mx_val << " " << mx_deg << endl;
}