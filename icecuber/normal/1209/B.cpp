#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int m = 5*4*3*2 * 10;
  vector<int> on(m,0);
  vector<int> a(n),b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    for (int j = 0; j < m; j++) {
      if ((j >= b[i] && (j-b[i])/a[i]%2 == 0) == (s[i] == '0')) {
	on[j]++;
      }
    }
  }

  int ans = 0;
  for (int j = 0; j < m; j++)
    ans = max(ans, on[j]);
  cout << ans << endl;
}