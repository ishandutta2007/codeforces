#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, x;
  cin >> n >> x;
  int ans = 0;
  while (n--) {
    char c;
    cin >> c;
    int d;
    cin >> d;
    if (c == '+') {
      x += d;
    } else {
      if (x >= d) x -= d;
      else ans++;
    }
  }
  cout << x << ' ' << ans << endl;
}