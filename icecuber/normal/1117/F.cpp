#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int adj[17][17];
char constr[1<<17][17][17];
int ok[1<<17], reachable[1<<17];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<int> v;
  int count[17] = {};
  for (int i = 0; i < n; i++) {
    v.push_back(s[i]-'a');
    count[v[i]]++;
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
      cin >> adj[i][j];
  int last_mask[17] = {}, seen[17] = {};
  for (int i = 0; i < n; i++) {
    int b = v[i];
    for (int a = 0; a < m; a++) {
      if (seen[a] && !adj[b][a]) {
	constr[last_mask[a]][a][b] = 1;
      }
    }
    seen[b] = 1;
    for (int a = 0; a < m; a++)
      last_mask[a] |= 1<<b;
    last_mask[b] = 0;
  }

  for (int i = 0; i < 1<<m; i++)
    for (int c = 0; c < m; c++)
      for (int a = 0; a < m; a++)
	for (int b = 0; b < m; b++)
	  constr[i|1<<c][a][b] |= constr[i][a][b];

  for (int i = 0; i < 1<<m; i++) {
    ok[i] = 1;
    for (int a = 0; a < m; a++)
      for (int b = 0; b < m; b++)
	if (!(i>>a&1) && !(i>>b&1) && constr[i][a][b]) ok[i] = 0;
  }
  int ans = n;
  reachable[0] = 1;
  for (int i = 0; i < 1<<m; i++) {
    if (!ok[i]) continue;
    int score = n;
    for (int a = 0; a < m; a++) {
      if (i>>a&1) {
	reachable[i] |= reachable[i^1<<a];
	score -= count[a];
      }
    }
    if (reachable[i])
      ans = min(ans, score);
  }
  cout << ans << endl;
}