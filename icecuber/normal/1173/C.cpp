#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000], b[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int already = b[n-1];
  for (int i = n-1; i >= n-b[n-1]; i--) {
    if (b[i] != b[n-1]-(n-1-i)) already = 0;
  }
  int ok = already;
  for (int i = 0; i < n; i++) {
    if (b[i] > already && i+1 >= b[i]-already) ok = 0;
  }
  if (ok) {
    cout << n-already << endl;
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (b[i])
      ans = max(ans, i+2-b[i]);
  }
  cout << ans+n << endl;
}