#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<8000> l, r;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  d += 10;
  vector<int> a(n*2);
  map<int,int> count;
  for (int i = 0; i < n; i++) {
    cin >> a[i*2];
    a[i*2+1] = a[i*2]+1;
    count[a[i*2]]++;
    count[a[i*2]+1]++;
  }
  n *= 2;
  int m;
  cin >> m;
  vector<int> x(m);
  for (int&v : x) cin >> v;
  int li = 0, ri = 0;
  for (int i = 0; i < m; i++) {
    if (i) {
      l <<= x[i]-x[i-1];
      r >>= x[i]-x[i-1];
    }
    while (li < n && a[li] <= x[i]) {
      if (x[i]-a[li] < d)
	l.set(x[i]-a[li]);
      li++;
    }
    while (ri < n && a[ri] < x[i]+d) {
      if (a[ri]-x[i] >= 0)
	r.set(a[ri]-x[i]);
      ri++;
    }
    if (!count.count(x[i]) || count[x[i]] < 2)
      r.set(0,0);

    int one = min(l._Find_first(), r._Find_first());
    double ans = atan2(1,one);
    int two = (l&r)._Find_first();
    if (two < d)
      ans = max(ans, 2*atan2(1,two));
    cout << fixed << setprecision(15) << ans << endl;
  }
}