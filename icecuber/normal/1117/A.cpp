#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int ma = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ma = max(ma, a[i]);
  }
  int streak = 0, ans = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == ma) ans = max(ans, ++streak);
    else streak = 0;
  }
  cout << ans << endl;
}