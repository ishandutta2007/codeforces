#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
    if (a > b) swap(a,b);
    int ans = 0;
    if (a) ans++, a--;
    if (b) ans++, b--;
    if (c) ans++, c--;
    if (a >= 3 && b >= 3 && c >= 3) {
      cout << 7 << endl;
      continue;
    }
    if (c && b) c--, b--, ans++;
    if (a && c) a--, c--, ans++;
    if (a && b) a--, b--, ans++;
    cout << ans << endl;
  }
}