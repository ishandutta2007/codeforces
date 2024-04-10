#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(string s, ll x, ll y) {
  int n = s.size();
  vector<array<ll,3>> pref(n+1), suf(n+1);
  ll base = 0;
  for (int i = 0; i < n; i++) {
    int j;
    if (s[i] == '0') j = 0;
    else if (s[i] == '1') j = 1;
    else j = 2;
    for (int k = 0; k < 3; k++)
      pref[i+1][k] = pref[i][k]+(j==k);

    if (j%2 == 0)
      base += pref[i][1]*y;
    else
      base += (pref[i][0]+pref[i][2])*x;
  }
  for (int i = n-1; i >= 1; i--) {
    int j;
    if (s[i] == '0') j = 0;
    else if (s[i] == '1') j = 1;
    else j = 2;
    for (int k = 0; k < 3; k++)
      suf[i-1][k] = suf[i][k]+(j==k);
  }

  ll ans = base;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      base -= (pref[i][1] + pref[i][2])*y + suf[i][1]*x;
      base += pref[i][0]*x + (suf[i][0] + suf[i][2])*y;
    }
    ans = min(ans, base);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  ll x, y;
  cin >> s >> x >> y;
  ll ans = f(s, x, y);
  reverse(s.begin(), s.end());
  cout << min(ans, f(s, y, x)) << endl;
}