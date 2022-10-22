#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

ll dp[200001][2];
pair<int,int> pos[200001][2];

ll dist(pair<int,int> a, pair<int,int> b) {
  return abs(a.x-b.x)+abs(a.y-b.y);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,vector<pair<int,int>>> m;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    m[max(x,y)].push_back({x,y});
  }

  int i = 0;
  for (auto v : m) {
    i++;
    int mi = 1e9, ma = -1e9;
    for (auto p : v.second) {
      if (p.x-p.y < mi) {
	mi = p.x-p.y;
	pos[i][0] = p;
      }
      if (p.x-p.y > ma) {
	ma = p.x-p.y;
	pos[i][1] = p;
      }
    }
    for (int j = 0; j < 2; j++)
      dp[i][j] = min(dp[i-1][0]+dist(pos[i-1][0], pos[i][!j]),
		     dp[i-1][1]+dist(pos[i-1][1], pos[i][!j]))+
	dist(pos[i][0], pos[i][1]);
  }
  cout << min(dp[i][0], dp[i][1]) << endl;
}