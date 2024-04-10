#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> x, a, b;
  for (int i = 0; i < n; i++) {
    int p;
    char c;
    cin >> p >> c;
    if (c == 'R') a.push_back(p);
    else if (c == 'G') x.push_back(p);
    else if (c == 'B') b.push_back(p);
    else assert(0);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(x.begin(), x.end());

  if (x.empty()) {
    ll ans = 0;
    if (a.size()) ans += a.back()-a[0];
    if (b.size()) ans += b.back()-b[0];
    cout << ans << endl;
  } else {
    int ans = 0;
    if (a.size()) ans += max(x[0]-a[0],0) + max(a.back()-x.back(), 0);
    if (b.size()) ans += max(x[0]-b[0],0) + max(b.back()-x.back(), 0);
    for (int i = 0; i+1 < (int)x.size(); i++) {
      int l = x[i], r = x[i+1];
      int sum = 0;
      for (int k : {0,1}) {
	auto&c = k ? b:a;
	vector<int> u(upper_bound(c.begin(), c.end(), l), lower_bound(c.begin(), c.end(), r));
	u.push_back(r);
	if (u.empty()) continue;
	int last = l;
	int ma = 0;
	for (int p : u) {
	  int w = p-last;
	  ma = max(ma, w);
	  last = p;
	}
	sum += r-l-ma;
      }
      ans += min(r-l+sum,(r-l)*2);
    }
    cout << ans << endl;
  }
}