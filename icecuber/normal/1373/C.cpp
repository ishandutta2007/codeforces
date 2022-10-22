#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    ll ans = n, balance = 0;
    int mi = 0;
    for (int i = 0; i < n; i++) {
      balance += (s[i] == '+')*2-1;
      if (balance < mi) {
	ans += i+1;
	mi = balance;
      }
    }
    cout << ans << endl;
  }
}