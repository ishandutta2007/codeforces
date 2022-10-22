#pragma GCC optimize("O2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull cover[500][500][8];

typedef pair<int,int> point;
#define x first
#define y second

point a[500], b[500];

bool check(const point&a, const point&b, const point&c, const point&d) {
  ll ax = a.x-b.x, ay = a.y-b.y;
  ll bx = c.x-d.x, by = c.y-d.y;
  return ax*by > ay*bx;
}

#define f(x,y,z)				\
	  !(x[0]&y[0]&z[0] |			\
	    x[1]&y[1]&z[1] |			\
	    x[2]&y[2]&z[2] |			\
	    x[3]&y[3]&z[3] |			\
	    x[4]&y[4]&z[4] |			\
	    x[5]&y[5]&z[5] |			\
	    x[6]&y[6]&z[6] |			\
	    x[7]&y[7]&z[7])

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
  for (int i = 0; i < m; i++) cin >> b[i].x >> b[i].y;
  sort(a, a+n);
  sort(b, b+m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
	if (check(a[i],a[j],b[k],a[j])) {
	  cover[i][j][k>>6] |= 1ull<<(k&63);
	}
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      for (int k = 0; k < j; k++) {
	if (check(a[i],a[j],a[k],a[j]))
	  ans += f(cover[i][j],cover[j][k],cover[k][i]);
	else
	  ans += f(cover[j][i],cover[k][j],cover[i][k]);
      }
  cout << ans << endl;
}