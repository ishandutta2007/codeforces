#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (string&s : a) cin >> s;

    for (char d = '0'; d <= '9'; d++) {
      int ans = 0;
      for (int r = 0; r < 4; r++) {

        int ma = -1;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (a[i][j] == d) ma = max(ma, i);
          }
        }
        if (ma >= 0) {
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
              if (a[i][j] == d) {
                ans = max(ans, max(j,n-1-j)*(ma-i));
              }
            }
          }
        }
        auto cp = a;
        for (int i = 0; i < n; i++)
          for (int j = 0; j < n; j++)
            a[i][j] = cp[j][n-1-i];
      }
      cout << ans << ' ';
    }
    cout << endl;
  }
}