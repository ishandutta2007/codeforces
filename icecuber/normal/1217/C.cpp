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
    int last_one = -1;
    ll ans = 0;
    for (int l = 0; l < s.size(); l++) {
      if (s[l] == '1') {
	int zeros = l-last_one-1;
	int v = 0;
	for (int i = 0; i+l < s.size() && i < 25; i++) {
	  v = v*2+(s[l+i]-'0');
	  ans += v <= zeros+i+1 && v >= i+1;
	}
	last_one = l;
      }
    }
    cout << ans << endl;
  }
}