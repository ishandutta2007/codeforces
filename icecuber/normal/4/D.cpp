#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second
pair<pair<int,int>,int> p[5000];

int dp[5000], par[5000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, w, h;
  cin >> n >> w >> h;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x.x >> p[i].x.y;
    p[i].y = i+1;
  }
  sort(p, p+n);

  int ans = 0, besti = -1;
  for (int i = 0; i < n; i++) {
    dp[i] = (w < p[i].x.x && h < p[i].x.y ? 1 : -1e9);
    par[i] = -1;
    for (int j = 0; j < i; j++)
      if (p[i].x.x > p[j].x.x && p[i].x.y > p[j].x.y && dp[j]+1 > dp[i]) {
	dp[i] = dp[j]+1;
	par[i] = j;
      }
    if (dp[i] > ans) {
      ans = dp[i];
      besti = i;
    }
  }
  int i = besti;
  vector<int> path;
  while (i > -1) {
    path.push_back(p[i].y);
    i = par[i];
  }
  reverse(path.begin(), path.end());
  cout << ans << endl;
  for (int i : path) cout << i << ' ';
  cout << endl;
}