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
    int mi = 1e9, ma = -1e9, cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i]) {
	mi = min(mi, i);
	ma = max(ma, i);
	cnt++;
      }
    }
    cout << ma-mi+1-cnt << endl;
  }
}