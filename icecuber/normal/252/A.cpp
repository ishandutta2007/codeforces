#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i+1; j <= n; j++) {
      int x = 0;
      for (int k = i; k < j; k++)
	x ^= a[k];
      ans = max(ans, x);
    }
  cout << ans << endl;
}