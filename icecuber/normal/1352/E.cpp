#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    vector<int> found(n);
    for (int i = 0; i < n; i++) {
      int acc = 0;
      int p = 0;
      for (int j = i; j < n; j++) {
	acc += a[j];
	if (j > i) {
	  while (p < n && sorted[p] < acc) p++;
	  while (p < n && sorted[p] == acc) found[p++] = 1;
	}
      }
    }
    int ans = 0;
    for (int v : found) ans += v;
    cout << ans << endl;
  }
}