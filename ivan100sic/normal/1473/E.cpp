// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll d[200005][4];
int n, m;
vector<pair<int, int>> e[200005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m;
  for (int i=0; i<m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    e[x].emplace_back(y, w);
    e[y].emplace_back(x, w);
  }

  set<tuple<ll, int, int>> pq;
  memset(d, 63, sizeof d);
  d[1][0] = 0;
  pq.insert({0ll, 1, 0});

  while (pq.size()) {
    auto [dx, x, f] = *pq.begin();
    pq.erase(pq.begin());

    for (auto [y, w] : e[x]) {
      for (int i : {0, 1}) {
        for (int j : {0, 2}) {
          if (i & f) continue;
          if (j & f) continue;
          int ff = f | i | j;

          ll wd = w;
          if (i) wd -= w;
          if (j) wd += w;

          if (d[x][f] + wd < d[y][ff]) {
            pq.erase({d[y][ff], y, ff});
            d[y][ff] = d[x][f] + wd;
            pq.insert({d[y][ff], y, ff});
          }
        }
      }
    }
  }

  for (int i=2; i<=n; i++) {
    cout << d[i][3] << " \n"[i == n];
  }
}