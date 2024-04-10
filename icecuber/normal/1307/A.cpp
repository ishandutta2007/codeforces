#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    int ans;
    cin >> ans;
    for (int i = 1; i < n; i++) {
      int a;
      cin >> a;
      int take = min(a, d/i);
      ans += take;
      d -= take*i;
    }
    cout << ans << endl;
  }
}