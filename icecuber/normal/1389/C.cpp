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
    int cnt[10] = {};
    for (char c : s) cnt[c-'0']++;
    int ans = n;
    for (int i = 0; i < 10; i++)
      ans = min(ans, n-cnt[i]);
    for (int a = 0; a < 10; a++) {
      for (int b = 0; b < 10; b++) {
	int score = 0;
	for (char c : s) {
	  if (score%2 == 0 && c-'0' == a) score++;
	  else if (score%2 && c-'0' == b) score++;
	}
	ans = min(ans, n-score/2*2);
      }
    }
    cout << ans << endl;
  }
}