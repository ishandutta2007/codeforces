#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if ((s[i]-'0')%2 == 0) ans += i+1;
  }
  cout << ans << endl;
}