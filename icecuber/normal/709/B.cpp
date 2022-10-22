#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[100000];
int main() {
  ios::sync_with_stdio(0);
  int n, a;
  cin >> n >> a;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  sort(x,x+n);
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  int ans = 1e9;
  for (int i = 0; i < 2; i++) {
    int mi = x[!i];
    int ma = x[n-1-i];
    ans = min(ans, ma-mi+min(abs(a-mi),abs(a-ma)));
  }
  cout << ans << endl;
}