// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> e[300005];
int p[20][300005], d[300005];

void dfs1(int x, int pr) {
  p[0][x] = pr;
  for (int i=1; i<20; i++) {
    p[i][x] = p[i-1][p[i-1][x]];
  }

  for (int y : e[x]) {
    if (y == pr) continue;
    d[y] = d[x] + 1;
    dfs1(y, x);
  }
}

int dizi(int x, int w) {
  for (int i=0; i<20; i++) {
    if (w & (1 << i)) {
      x = p[i][x];
    }
  }
  return x;
}

int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  x = dizi(x, d[x] - d[y]);
  if (x == y) return x;
  for (int i=19; i>=0; i--) {
    int xx = p[i][x], yy = p[i][y];
    if (xx != yy) {
      x = xx;
      y = yy;
    }
  }
  return p[0][x];
}

int m0[300005], m1[300005], m2[300005];
vector<ll> me;

void dfs2(int x) {
  for (int y : e[x]) {
    if (y != p[0][x]) {
      dfs2(y);
      m0[x] += m0[y];
      m1[x] += m1[y];
      m2[x] += m2[y];
    }
  }
}

void ade(int x, int y) {
  if (x > y) swap(x, y);
  me.emplace_back(123123123ll*x+y);
}

ll ch(ll x) {
  return x*(x-1) / 2;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;
  for (int i=1; i<n; i++) {
    int x, y;
    cin >> x >> y;
    e[x] += y;
    e[y] += x;
  }

  dfs1(1, 1);

  int m;
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    int z = lca(x, y);

    m0[x]++;
    m0[y]++;
    m0[z]--;
    if (z != 1) {
      m0[p[0][z]]--;
    }

    m1[x]++;
    m1[y]++;
    m1[z] -= 2;

    int xx = -1;
    if (d[x] - d[z] >= 1) {
      m2[x]++;
      xx = dizi(x, d[x] - d[z] - 1);
      m2[xx]--;
    }

    int yy = -1;
    if (d[y] - d[z] >= 1) {
      m2[y]++;
      yy = dizi(y, d[y] - d[z] - 1);
      m2[yy]--;
    }

    if (xx != -1 && yy != -1) {
      ade(xx, yy);
    }
  }

  dfs2(1);

  ll sol = 0;
  for (int i=1; i<=n; i++) {
    sol += ch(m0[i]) + ch(m2[i]) - 2*ch(m1[i]);
  }

  sort(begin(me), end(me));

  ll last = -1, streak = 0;
  for (ll x : me) {
    streak = x == last ? streak + 1 : 0;
    sol += streak;
    last = x;
  }

  cout << sol << '\n';
}