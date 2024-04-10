#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), acc(n+1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      acc[i+1] = acc[i]+a[i];
    }
    int ans = n-1;
    for (int i = 0; i <= n; i++) {
      int x = acc[i], y = n-i-(acc[n]-acc[i]);
      ans = min(ans, x+max(0,y-x)); 
    }
    cout << ans << endl;
  }
}