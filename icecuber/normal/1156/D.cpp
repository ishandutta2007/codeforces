#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll par[2][200000], sz[2][200000];
ll find(int c, int p) {
  ll&pp = par[c][p];
  if (pp != par[c][pp])
    pp = find(c,pp);
  return pp;
}
void join(int c, int a, int b) {
  a = find(c,a), b = find(c,b);
  if (a == b) return;
  if (sz[c][a] > sz[c][b]) swap(a,b);
  par[c][a] = b;
  sz[c][b] += sz[c][a];
}

int main() {
  int n;
  cin >> n;
  for (int c = 0; c < n; c++)
    for (int i = 0; i < n; i++)
      par[c][i] = i, sz[c][i] = 1;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    join(c, a, b);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int i0 = find(0,i);
    int i1 = find(1,i);
    ans += (sz[0][i0]-1)*(sz[1][i1]-1)+sz[0][i0]+sz[1][i1]-2;
  }
  cout << ans << endl;
}