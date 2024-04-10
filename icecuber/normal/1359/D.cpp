#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  int ans = 0;
  for (int ma = -30; ma <= 30; ma++) {
    int mi = 0, acc = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > ma) {
	mi = 0, acc = 0;
      } else {
	mi = min(mi, acc);
	acc += a[i];
	ans = max(ans, acc-mi-ma);
      }
    }
  }
  cout << ans << endl;
}