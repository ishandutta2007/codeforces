#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[200001], y[200001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int gx, gy;
  cin >> gx >> gy;
  if (n%2 != abs(gx+gy)%2 || abs(gx)+abs(gy) > n) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    x[i+1] = x[i]+(s[i]=='R')-(s[i]=='L');
    y[i+1] = y[i]+(s[i]=='U')-(s[i]=='D');
  }
  int a = 0, b = 0;
  int ans = n;
  while (b <= n) {
    int d = abs(x[a]+x[n]-x[b]-gx)+abs(y[a]+y[n]-y[b]-gy);
    if (d > b-a) b++;
    else {
      ans = min(ans, b-a);
      a++;
    }
  }
  cout << ans << endl;
}