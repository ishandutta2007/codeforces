#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<int> a(h),b(w);
  int tot = 0;
  for (int&v : a) cin >> v, tot ^= v;
  for (int&v : b) cin >> v, tot ^= v;
  if (tot) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i == 0 && j == 0) {
	int ans = b[0];
	for (int k = 1; k < h; k++)
	  ans ^= a[k];
	cout << ans << ' ';
      } else if (i == 0) cout << b[j] << ' ';
      else if (j == 0) cout << a[i] << ' ';
      else cout << 0 << ' ';
    }
    cout << endl;
  }
}