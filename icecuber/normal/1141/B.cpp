#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[400000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  copy_n(a, n, a+n);
  int streak = 0, ans = 0;
  for (int i = 0; i < n*2; i++) {
    if (!a[i]) streak = 0;
    else ans = max(ans, ++streak);
  }
  cout << ans << endl;
}