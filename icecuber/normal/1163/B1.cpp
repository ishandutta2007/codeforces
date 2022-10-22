#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100001], b[100001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int ans = 0, ma = 0;
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    b[a[u]]--;
    ma = max(ma, ++a[u]);
    b[a[u]]++;
    //cout << ma << ' ' << b[ma-1]*(ma-1)+b[ma]*ma << ' ' << i+1 << ' ' << b[ma] << endl;
    if (b[ma] == 1 && b[ma-1]*(ma-1)+b[ma]*ma == i+1 || b[ma]*ma == i && b[1] == 1 || ma == 1) ans = i+1;
  }
  cout << ans << endl;
}