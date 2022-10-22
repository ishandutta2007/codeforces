#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5+10;
vector<int> node[nax];
int par[20][nax];
int depth[nax];

void dfs(int p, int parent, int d = 0) {
  par[0][p] = parent;
  depth[p] = d;
  for (int i : node[p]) {
    if (i != parent) dfs(i, p, d+1);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }

  dfs(0, n);
  par[0][n] = n;
  for (int l = 0; l+1 < 20; l++) {
    for (int i = 0; i < n; i++)
      par[l+1][i] = par[l][par[l][i]];
  }
  auto dist = [&](int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int ans = 0;
    for (int i = 0; i < 20; i++)
      if (depth[b]-depth[a]>>i&1) {
	b = par[i][b];
	ans += 1<<i;
      }
    for (int i = 19; i >= 0; i--) {
      if (par[i][a] != par[i][b]) {
	a = par[i][a];
	b = par[i][b];
	ans += 2<<i;
      }
    }
    if (a != b) ans += 2;
    return ans;
  };
  int q;
  cin >> q;
  while (q--) {
    int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;
    x--, y--, a--, b--;
    int d0 = dist(a, b);
    int d1 = dist(a,x)+dist(y,b)+1;
    int d2 = dist(a,y)+dist(x,b)+1;
    int ok = 0;
    for (int d : {d0, d1, d2}) {
      if (k >= d && k%2 == d%2) ok = 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}