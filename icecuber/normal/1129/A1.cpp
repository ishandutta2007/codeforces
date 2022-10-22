#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[5000];
int c[5000], d[5000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    c[x]++;
    int d_ = (y-x+n)%n;
    if (!d[x] || d_ < d[x])
      d[x] = d_;
  }
  for (int i = 0; i < n; i++) {
    int ans = 0;
    for (int j = 0; j < n; j++) {
      int k = (i+j)%n;
      int d_ = (c[k]-1)*n+j+d[k];
      if (c[k]) ans = max(ans, d_);
    }
    cout << ans << ' ';
  }
  cout << endl;
}