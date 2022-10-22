#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[101];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int ans = 1e9;
  for (int x = 1; x <= n; x++) {
    int v = 0;
    for (int i = 1; i <= n; i++)
      v += a[i]*(abs(x-1)+abs(i-x)+abs(i-1))*2;
    ans = min(ans, v);
  }
  cout << ans << endl;
}