#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[300000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int ans = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 0; i < n; i++)
    if (c[i] != c[0]) ans = max(ans, i);
  for (int i = 0; i < n; i++)
    if (c[n-1] != c[i]) ans = max(ans, n-1-i);
  cout << ans << endl;
}