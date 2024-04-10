#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int da = a[i]-'0';
    int db = b[i]-'0';
    ans += min((da-db+10)%10, (db-da+10)%10);
  }
  cout << ans << endl;
}