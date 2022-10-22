#line 1 "codeforces-workspace\\contest\\1439\\b\\b.cpp"
#include <bits/extc++.h>

#line 4 "codeforces-workspace\\contest\\1439\\b\\b.cpp"

void _main() {
  using namespace std;

  long n, m, k;
  cin >> n >> m >> k;
  // vector<set<int>> g(n);
  vector<__gnu_pbds::gp_hash_table<int, __gnu_pbds::null_type>> g(n);
  for (auto t = 0; t < m; ++t) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    // g[a].emplace(b);
    // g[b].emplace(a);
    g[a].insert(b);
    g[b].insert(a);
  }

  if (k * (k - 1) > m * 2) {
    cout << -1 << "\n";
    return;
  }

  set<pair<int, int>> s;
  for (auto i = 0; i < n; ++i) {
    s.emplace(size(g[i]), i);
  }

  auto era = [&](int v) -> void {
    s.erase({size(g[v]), v});
    for (auto &&u : g[v]) {
      s.erase({size(g[u]), u});
      g[u].erase(v);
      s.emplace(size(g[u]), u);
    }
  };

  while (!s.empty()) {
    auto [deg, v] = *s.begin();
    if (deg < k - 1) {
      era(v);
      continue;
    }

    if (deg >= k) {
      cout << "1 ";
      cout << size(s) << "\n";
      for (auto &&[d, u] : s) {
        cout << u + 1 << " ";
      }
      cout << "\n";
      return;
    }

    bool fail = 0;
    for (auto i = begin(g[v]); i != end(g[v]); ++i) {
      for (auto j = begin(g[v]); j != i; ++j) {
        if (g[*i].find(*j) == end(g[*i])) {
          // if (!g[*i].count(*j)) {
          fail = true;
        }
      }
    }
    // for (auto &&x : g[v]) {
    //   for (auto &&y : g[v]) {
    //     if (x != y && !g[x].count(y)) {
    //       fail = true;
    //     }
    //   }
    // }
    if (fail) {
      era(v);
      continue;
    }

    cout << "2\n";
    cout << v + 1;
    for (auto &&x : g[v]) {
      cout << " " << x + 1;
    }
    cout << "\n";
    return;
  }

  cout << "-1\n";
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    _main();
  }
}