// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
ll w;
int a[2005][2005];
int da[2005][2005], db[2005][2005];

template<class T>
void bfs(int x, int y, T d) {
  memset(d, 255, sizeof da);
  d[x][y] = 0;
  queue<pair<int, int>> q;
  q.push({x, y});
  while (q.size()) {
    auto [x, y] = q.front(); q.pop();
    for (int dir : {0, 1, 2, 3}) {
      int u = x + dx[dir];
      int v = y + dy[dir];
      if (u >= 0 && v >= 0 && u < n && v < m && a[u][v] != -1 && d[u][v] == -1) {
        d[u][v] = d[x][y] + 1;
        q.push({u, v});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m >> w;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> a[i][j];
    }
  }

  bfs(0, 0, da);
  bfs(n-1, m-1, db);

  ll z = db[0][0] == -1 ? 1e18 : db[0][0] * w;
  ll za = 1e18, zb = 1e18;

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (a[i][j] > 0) {
        if (da[i][j] != -1) {
          za = min(za, 0ll + a[i][j] + da[i][j] * w);
        }

        if (db[i][j] != -1) {
          zb = min(zb, 0ll + a[i][j] + db[i][j] * w);
        }
      }
    }
  }

  z = min(z, za + zb);
  if (z > 1e16) {
    z = -1;
  }
  cout << z << '\n';
}