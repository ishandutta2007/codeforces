#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  ll mul = 1e8;
  ll pass = 0, fail = 1e8*(n>0)+1;
  while (fail-pass > 1) {
    ll mid = pass+fail>>1;
    // dp[i][k] = score (mid*success-tot*mul)
    // using s[:i]
    // next command is "LR"[k]
    ll dp[2] = {0,-mid};
    if (s[0] == 'R' && s[n-1] == 'R')
      dp[0] = -mid*2;
    for (int i = 0; i < n; i++) {
      ll ndp[2];
      ndp[0] = dp[1]-mid+mul*(s[i]=='R');
      ndp[1] = dp[0]-mid+mul*(s[i]=='L');
      dp[0] = ndp[0], dp[1] = ndp[1];
      if (i == n-1 && s[0] == 'L' && s[i] == 'L')
	ndp[0] = dp[1]-mid;
      if (i+1 < n && s[i+1] == s[i] && s[i] != 'X') {
	ndp[0] = dp[1]-mid;
	ndp[1] = dp[0]-mid;
      }
      dp[0] = ndp[0], dp[1] = ndp[1];
      ndp[0] = max(ndp[0], dp[1]-mid);
      ndp[1] = max(ndp[1], dp[0]-mid);
      dp[0] = ndp[0], dp[1] = ndp[1];
    }
    ll score = dp[0];
    if (score >= 0) pass = mid;
    else fail = mid;
  }
  printf("%.6f\n", pass*1e-6);
}