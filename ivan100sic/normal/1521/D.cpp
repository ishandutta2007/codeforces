// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
set<int> e[100005];
vector<array<int, 4>> sol;
set<pair<int, int>> brisano;

int dp[100005][2];
pair<int, int> prelaz[100005];

void dfs1(int x, int p) {
  vector<pair<int, int>> dole;
  int zbir01 = 0;

  for (int y : e[x]) {
    if (y == p) continue;
    dfs1(y, x);
    zbir01 += min(dp[y][0], dp[y][1]);
    dole.emplace_back(dp[y][0] - min(dp[y][0], dp[y][1]), y);
  }

  sort(begin(dole), end(dole));

  if (dole.size() >= 2) {
    dp[x][1] = zbir01 + dole[0].first + dole[1].first - 1;
    dp[x][0] = zbir01 + dole[0].first;
    prelaz[x] = {dole[0].second, dole[1].second};
  } else if (dole.size() == 1) {
    dp[x][1] = 1e8;
    dp[x][0] = zbir01 + dole[0].first;
    prelaz[x] = {dole[0].second, -1};
  } else {
    dp[x][1] = 1e8;
    dp[x][0] = 1;
    prelaz[x] = {-1, -1};
  }
}

void dfs2(int x, int p, int t) {
  for (int y : e[x]) {
    if (y == p) continue;
    int uzmi = y == prelaz[x].first;
    if (t == 1) {
      uzmi |= y == prelaz[x].second;
    }
    dfs2(y, x, !uzmi);
    if (!uzmi) {
      brisano.insert({x, y});
    }
  }
}

int glob_list;
bool vis[100005];

void dfs3(int x, int p) {
  if (e[x].size() <= 1) {
    glob_list = x;
  }
  vis[x] = 1;
  for (int y : e[x]) {
    if (y == p) continue;
    dfs3(y, x);
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    sol = {};
    brisano = {};
    for (int i=1; i<=n; i++) {
      e[i] = {};
      vis[i] = 0;
    }

    for (int i=1; i<n; i++) {
      int x, y;
      cin >> x >> y;
      e[x].insert(y);
      e[y].insert(x);
    }

    dfs1(1, 1);
    dfs2(1, 1, dp[1][1] < dp[1][0]);

    // for (int i=1; i<=n; i++) {
    //   cerr << i << ": " << dp[i][0] << ' ' << dp[i][1] << " p " << prelaz[i].first << ' ' << prelaz[i].second << '\n';
    // }

    for (auto [x, y] : brisano) {
      e[x].erase(y);
      e[y].erase(x);
      // cerr << "brisem " << x << ' ' << y << '\n';
    }

    vector<pair<int, int>> putevi;

    for (int i=1; i<=n; i++) {
      if (!vis[i] && e[i].size() <= 1) {
        dfs3(i, i);
        putevi.push_back({i, glob_list});
        // cerr << "putevi " << i << ' ' << glob_list << '\n';
      }
    }

    int j = 0;
    for (auto [x, y] : brisano) {
      sol.push_back({x, y, putevi[j].first, putevi[j+1].second});
      j++;
    }

    cout << sol.size() << '\n';
    for (auto [a, b, c, d] : sol) {
      cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }
  }
}