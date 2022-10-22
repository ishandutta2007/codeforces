#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist[10][10];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      fill_n((int*)dist, 100, 1e9);
      for (int j = 0; j < 10; j++) {
	dist[j][(j+x)%10] = 1;
	dist[j][(j+y)%10] = 1;
      }
      for (int k = 0; k < 10; k++)
	for (int i = 0; i < 10; i++)
	  for (int j = 0; j < 10; j++)
	    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

      ll ans = 0;
      int p = 0;
      for (int i = 0; i < s.size(); i++) {
	if (i == 0) {
	  ans += s[0] == '0' ? 0 : dist[0][s[i]-'0'];
	} else {
	  ans += dist[s[i-1]-'0'][s[i]-'0']-1;
	}
      }
      if (ans >= 1e8)
	cout << -1 << ' ';
      else
	cout << ans << ' ';
    }
    cout << endl;
  }
}