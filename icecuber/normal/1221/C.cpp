#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int c, m, x;
    cin >> c >> m >> x;
    cout << min({c,m,(c+m+x)/3}) << '\n';
  }
}