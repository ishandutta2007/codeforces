//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

bitset<1200001> f;

#define pb push_back
#define fi first
#define se second

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int p; cin >> p; graph[p - 1].push_back(i); graph[i].push_back(p - 1);
  }
  vector<int> sz(n);
  auto dfs = [&](auto&& self, int v, int p = -1) -> void {
    sz[v] = 1;
    for (int u : graph[v]) {
      if (u != p) {
        self(self, u, v);
        sz[v] += sz[u];
      }
    }
  };
  dfs(dfs, 0);
  auto findCentroid = [&](int v) {
    int s = sz[v];
    int p = -1;
    while (true) {
      bool found = false;
      for (int u : graph[v]) {
        if (u != p && 2 * sz[u] > s) {
          p = v;
          v = u;
          found = true;
          break;
        }
      }
      if (!found) {
        return v;
      }
    }
    assert(false);
  };
  int c = findCentroid(0);
  ll ans = 0;
  dfs(dfs, c);
  for (int v = 0; v < n; ++v) {
    ans += sz[v];
  }
  vector<int> a;
  map<int, int> s;
  for (int u : graph[c]) {
    a.push_back(sz[u]);
    ++s[sz[u]];
  }
  vector<int> b;
  while (!s.empty()) {
    auto p=*s.begin(); s.erase(s.begin());
    if (p.se%2==0) {
      b.pb(p.fi); b.pb(p.fi);
      if (p.se!=2) s[p.fi+p.fi]+=(p.se-2)/2;
    } else {
      b.pb(p.fi);
      if (p.se!=1) s[p.fi+p.fi]+=(p.se-1)/2;
    }
  }
  f[0]=1;
  for (auto p:b) f|=f<<p;
  int cur = (n - 1) / 2;
  while (!f[cur]) --cur;
  ans += ll(cur) * (n - 1 - cur);
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}