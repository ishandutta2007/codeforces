#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string a, b;
    for (int i = 0; i <= k; i++) {
      a += '0'+(i==0);
      b += '0'+(i==k);
    }
    s = a+s+b;
    n = s.size();

    int ans = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
	ans += (i-last-1-k)/(k+1);
	last = i;
      }
    }
    cout << ans << endl;
  }
}