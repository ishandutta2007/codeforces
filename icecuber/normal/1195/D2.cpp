#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  int c[11] = {};
  for (string&s : a) {
    cin >> s;
    reverse(s.begin(), s.end());
    c[s.size()]++;
  }
  ll mod = 998244353;
  ll pow10[30] = {1};
  for (int i = 1; i < 30; i++)
    pow10[i] = pow10[i-1]*10%mod;
  ll ans = 0;
  for (string&s : a) {
    for (int i = 0; i < s.size(); i++) {
      for (int j = 1; j <= 10; j++) {
	(ans += pow10[min(i*2,i+j)]*c[j]*(s[i]-'0')) %= mod;
	(ans += pow10[min(i*2+1,i+j)]*c[j]*(s[i]-'0')) %= mod;
      }
    }
  }
  cout << ans << endl;
}