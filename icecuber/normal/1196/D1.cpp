#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    string rgb = "RGB";
    int ans = k;
    int diff[3] = {};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
	diff[j] += s[i] != rgb[(i+j)%3];
	if (i >= k)
	  diff[j] -= s[i-k] != rgb[(i+j-k%3+3)%3];
      }
      if (i >= k-1) ans = min({ans, diff[0],diff[1],diff[2]});
    }
    cout << ans << endl;
  }
}