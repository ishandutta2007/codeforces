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
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int best = 1e9;
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
      if (a[i] > best) ans++;
      best = min(best, a[i]);
    }
    cout << ans << endl;
  }
}