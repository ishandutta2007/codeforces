#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string A, B;
    cin >> A >> B;

    int a[2][2] = {};
    for (int i = 0; i < n; i++) {
      a[A[i]-'0'][B[i]-'0']++;
    }

    int b[2][2] = {{a[1][0]-1, a[1][1]}, 
                   {a[0][0]+1, a[0][1]}};
    int c[2][2] = {{a[1][0], a[1][1]-1}, 
                   {a[0][0], a[0][1]+1}};

    int ans = 1e9;
    if (a[0][1] == a[1][0]) {
      ans = min(ans, a[0][1]*2);
    }
    if (b[0][0] >= 0 && b[0][1] == b[1][0]) {
      ans = min(ans, b[0][1]*2+1);
    }
    if (c[0][1] >= 0 && c[0][1] == c[1][0]) {
      ans = min(ans, c[0][1]*2+1);
    }
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
  }
}