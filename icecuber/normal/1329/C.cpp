#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(1<<(n+1));
    for (int i = 1; i < 1<<n; i++)
      cin >> a[i];

    function<int(int)> f = [&](int i) {
      if (a[i*2] == 0 && a[i*2+1] == 0) {
	if (i < 1<<m) return 0;
	a[i] = 0;
	return 1;
      } else {
	int j = a[i*2] > a[i*2+1] ? i*2 : i*2+1;
	int cp = a[j];
	int good = f(j);
	if (good) {
	  a[i] = cp;
	  return 1;
	} else {
	  return 0;
	}
      }
      assert(0);
    };
    vector<int> ans;
    for (int i = 1; i < 1<<n; i++) {
      while (a[i]) {
	int good = f(i);
	if (good) ans.push_back(i);
	else break;
      }
    }
    ll sum = 0;
    for (int i = 1; i < 1<<m; i++)
      sum += a[i];
    cout << sum << endl;
    for (int i : ans) cout << i << ' ';
    cout << endl;
  }
}