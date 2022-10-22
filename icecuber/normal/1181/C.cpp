#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s[1000];
int dp[1000][1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      if (!i || s[i][j] != s[i-1][j]) dp[i][j] = 1;
      else dp[i][j] = dp[i-1][j]+1;
    }
  }
  ll ans = 0;
  for (int i = 0; i < h; i++) {
    int streak = 0;
    vector<int> last;
    for (int j = 0; j < w; j++) {
      int y = dp[i][j];
      if (i-2*y >= 0 && dp[i-y][j] == y && dp[i-2*y][j] >= y) {
	vector<int> stat = {y, s[i][j], s[i-y][j], s[i-y*2][j]};
	if (stat != last) streak = 0;
	ans += ++streak;
	last = stat;
      } else streak = 0, last.clear();
    }
  }
  cout << ans << endl;
}