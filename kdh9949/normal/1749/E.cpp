#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> b(n);
  vector<vector<int>> c(n, vector<int>(m));
  auto d = c;
  for(int i = 0; i < n; ++i) {
    cin >> b[i];
    for(int j = 0; j < m; ++j) if(b[i][j] == '#') {
      c[i][j] = 2;
      const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
      for(int k = 0; k < 4; ++k) {
        int nx = i + dx[k], ny = j + dy[k];
        if(0 <= nx && nx < n && 0 <= ny && ny < m) if(!c[nx][ny]) c[nx][ny] = 1;
      }
    }
  }

  const int inf = int(1e9);
  using pii = pair<int, int>;
  using pip = pair<int, pii>;
  priority_queue<pip, vector<pip>, greater<pip>> pq;
  vector<vector<pii>> p(n, vector<pii>(m));
  for(int i = 0; i < n; ++i) {
    fill(d[i].begin(), d[i].end(), inf);
    if(c[i][0] != 1) {
      d[i][0] = (c[i][0] == 0);
      pq.emplace(d[i][0], pii(i, 0));
      p[i][0] = pii(0, -1);
    }
  }
  while(!pq.empty()) {
    pip t = pq.top();
    pq.pop();
    if(d[t.second.first][t.second.second] != t.first) continue;
    const int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};
    for(int i = 0; i < 4; ++i) {
      int nx = t.second.first + dx[i], ny = t.second.second + dy[i];
      if(nx < 0 || n <= nx || ny < 0 || m <= ny || c[nx][ny] == 1) continue;
      if(d[nx][ny] > t.first + (c[nx][ny] == 0)) {
        d[nx][ny] = t.first + (c[nx][ny] == 0);
        p[nx][ny] = t.second;
        pq.emplace(d[nx][ny], pii(nx, ny));
      }
    }
  }

  int ans = inf / 2, ai = -1;
  for(int i = 0; i < n; ++i) if(ans > d[i][m - 1]) { ans = d[i][m - 1]; ai = i; }
  if(ai < 0) { cout << "NO\n"; return; }
  for(int i = ai, j = m - 1; j >= 0; ) {
    b[i][j] = '#';
    pii t = p[i][j];
    i = t.first;
    j = t.second;
  }
  cout << "YES\n";
  for(string s : b) cout << s << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while(t--) solve();

  return 0;
}