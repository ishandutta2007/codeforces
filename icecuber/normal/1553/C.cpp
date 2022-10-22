#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int ans = 10;
    for (int k : {0,1}) {
      int c[2] = {}, l[2] = {5,5};
      for (int i = 0; i < 10; i++) {
        if (s[i] == '1' || (s[i] == '?' && i%2 == k)) c[i%2]++;
        l[i%2]--;
        if (c[0] > c[1]+l[1] || c[1] > c[0]+l[0]) {
          ans = min(ans, i+1);
          break;
        }
      }
    }
    cout << ans << endl;
  }
}