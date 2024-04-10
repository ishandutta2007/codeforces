#include <bits/stdc++.h>


bool a[22][365], b[22][365];
int c[22];
bool vis[22][365];
void dfs(int x, int y) {
  if (vis[x][y]) return;
  // std::cerr << x << " " << y << "\n";
  vis[x][y] = true;
  if (x == 20) return;
  if (c[x] <= 1) {
    for (int l = 0; l < 360; l++) {
      if (!a[x + 1][l]) dfs(x + 1, l);
      if (x && !a[x][l]) dfs(x - 1, l);
    }
  } else {
    int l = y, r = (y + 1) % 360;
    while (!b[x][l]) l = (l + 360 - 1) % 360;
    while (!b[x][r]) r = (r + 1) % 360;
    while (l != r) {
      if (!a[x + 1][l]) dfs(x + 1, l);
      if (x && !a[x][l]) dfs(x - 1, l);
      l = (l + 1) % 360;
    }
  }
  
}
void solve() {
  int n;
  std::cin >> n;

  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  memset(c, 0, sizeof c);
  memset(vis, 0, sizeof vis);
  
  while (n--) {
    std::string s;
    std::cin >> s;
    if (s[0] == 'C') {
      int r, x, y;
      std::cin >> r >> x >> y;
      while (x != y) {
	a[r][x] = true;
	x = (x + 1) % 360;
      }
    } else {
      int x, y, k;
      std::cin >> x >> y >> k;
      while (x != y) {
	b[x][k] = true;
	c[x]++;
	x++;
      }
    }
  }
  dfs(0, 0);
  bool ok = false;
  for (int i = 0; i < 360; i++) if (vis[20][i]) ok = true;
  std::cout << (ok ? "YES\n" : "NO\n");
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}