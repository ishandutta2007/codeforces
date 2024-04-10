#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist[200][200];
vector<pair<int,int>> node[200];

int col[200];
void dfs(int p, int c = 1) {
  if (col[p]) {
    if (col[p] != c) {
      cout << "NO" << endl;
      exit(0);
    }
    return;
  }
  col[p] = c;
  for (auto [i,dir] : node[p])
    dfs(i, 3-c);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dist[i][j] = (i == j ? 0 : 1e9);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].emplace_back(b, c);
    node[b].emplace_back(a,-c);
    if (c == 0) {
      dist[a][b] = min(dist[a][b], 1);
      dist[b][a] = min(dist[b][a], 1);
    } else {
      dist[a][b] = min(dist[a][b], 1);
      dist[b][a] = min(dist[b][a],-1);
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
        dist[i][j] = max(min(dist[i][j], dist[i][k]+dist[k][j]), (int)-1e9);
      }
    }
  }

  dfs(0);

  int besti = -1, best = -1e9;
  for (int i = 0; i < n; i++) {
    int ok = 1, ma = 0;
    for (int j = 0; j < n; j++) {
      if (dist[i][j] < 0) ok = 0;
      ma = max(ma, dist[i][j]);
    }
    if (ok && ma > best) {
      best = ma;
      besti = i;
    }
  }

  int ok = 1;
  if (besti != -1) {
    for (int i = 0; i < n; i++) {
      for (auto [j, dir] : node[i]) {
        if (dir == -1) continue;
        else if (dir == 0 && abs(dist[besti][i]-dist[besti][j]) != 1) ok = 0;
        else if (dir == 1 && dist[besti][j] != dist[besti][i]+1) ok = 0;
      }
    }
  }

  if (!ok || besti == -1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << best << endl;
    for (int i = 0; i < n; i++) {
      cout << dist[besti][i] << ' ';
    }
    cout << endl;
  }
}