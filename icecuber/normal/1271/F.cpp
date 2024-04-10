#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a[3], b[3];
    for (int i : {2,1,0}) cin >> a[i];
    for (int i : {2,1,0}) cin >> b[i];

    int d[7];
    for (int i = 0; i < 7; i++) cin >> d[i];
    for (int x = 0; x <= d[1]; x++) {
      for (int y = 0; y <= d[2]; y++) {
	int na[3], nb[3], ans[7];
	copy_n(a, 3, na);
	copy_n(b, 3, nb);
	int ok = 1;
	auto red = [&](int*a, int i, int c) {
	  if (a == na) ans[i] = c;
	  for (int j = 0; j < 3; j++) {
	    if (!(i>>j&1)) {
	      a[j] -= c;
	      if (a[j] < 0) ok = 0;
	    }
	  }
	};
	red(na, 1, x);
	red(nb, 1, d[1]-x);
	red(na, 2, y);
	red(nb, 2, d[2]-y);
	for (int j = 0; j < 3; j++)
	  if (na[j] < 0 || nb[j] < 0) ok = 0;
	if (!ok) continue;
	for (int i : {0,4,3,5,6}) {
	  int ma = d[i];
	  for (int j = 0; j < 3; j++) {
	    if (!(i>>j&1)) ma = min(ma, na[j]);
	  }
	  red(na, i, ma);
	  red(nb, i, d[i]-ma);
	  if (!ok) break;
	}
	if (ok) {
	  for (int j = 0; j < 7; j++) {
	    cout << ans[j] << ' ';
	  }
	  cout << endl;
	  goto next;
	}
      }
    }
    cout << -1 << endl;
    continue;
  next:;
  }
}