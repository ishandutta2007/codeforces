#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    m--;
    if (k > m) k = m;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int x = 0;
    for (int r = 0; r <= k; r++) {
      int l = k-r;
      int mi = 1e9;
      for (int i = l; i <= m-r; i++) {
	mi = min(mi, max(a[i], a[n-1-(m-i)]));
      }
      x = max(x, mi);
    }
    cout << x << endl;
  }
}