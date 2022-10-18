#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

const int MAX = 220;
const int inf = 1e9;

int d[MAX][MAX];
bool e[MAX][MAX];
int f[MAX][MAX];
bool color[MAX];
bool visited[MAX];
int n, m;

bool dfs(int x, int side) {
  if (visited[x]) return color[x] == side;
  visited[x] = true;
  color[x] = side;
  bool ret = true;
  for (int y = 0; y < n; ++y) {
    if (e[x][y]) ret &= dfs(y, side ^ 1);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      e[i][j] = false;
      f[i][j] = -1;
    }
  }

  vector<pair<int, int>> neighbors;
  for (int i = 0; i < m; ++i) {
    int u, v, b;
    cin >> u >> v >> b;
    --u, --v;
    e[u][v] = e[v][u] = 1;
    if (b == 1) {
      f[u][v] = f[v][u] = u;
    }
    neighbors.emplace_back(u, v);
    neighbors.emplace_back(v, u);
  }

  for (int i = 0; i < n; ++i) {
    visited[i] = false;
  }
  bool bipartite = true;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bipartite &= dfs(i, 0);
    }
  }

  if (!bipartite) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      d[i][j] = inf;
      if (i == j) {
        d[i][j] = 0;
      } else if (e[i][j]) {
        if (f[i][j] == -1 || f[i][j] == i) {
          d[i][j] = 1;
        } else {
          d[i][j] = -1;
        }
      }
    }
  }

  bool impossible = false;
  int maxd = 0;
  vector<int> maxds(n, 0);
  for (int s = 0; s < n; ++s) {
    vector<int> dist(n, inf);
    dist[s] = 0;

    bool negCyc = false;
    for (int it = 0; it <= n; ++it) {
      for (auto& p : neighbors) {
        int i = p.first, j = p.second;
        if (dist[i] + d[i][j] < dist[j]) {
          dist[j] = dist[i] + d[i][j];
          if (it == n) negCyc = true;
        }
      }
    }

    if (negCyc) {
      impossible = true;
      continue;
    }

    int md = *max_element(dist.begin(), dist.end());
    if (md > maxd) {
      maxd = md;
      maxds = dist;
    }
  }

  if (impossible) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  cout << maxd << "\n";
  for (int i = 0; i < n; ++i) {
    cout << maxds[i] << ' ';
  }
  cout << '\n';

  return 0;
}