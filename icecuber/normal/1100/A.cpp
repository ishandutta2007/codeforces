#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int sum = 0;
  for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
  int ans = 0;
  for (int j = 0; j < k; j++) {
    int t = sum;
    for (int i = j; i < n; i += k) t -= a[i];
    ans = max(ans,abs(t));
  }
  cout << ans << endl;
}