#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist[100][100];
int p[1000000];
int dp[1000000];
int par[1000000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      dist[i][j] = s[j]-'0';
      if (dist[i][j] == 0)
	dist[i][j] = 1e9;
    }
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
  for (int i = 0; i < n; i++)
    dist[i][i] = 0;

  int m;
  cin >> m;
  par[0] = -1;
  dp[0] = 1;
  cin >> p[0];
  p[0]--;
  for (int i = 1; i < m; i++) {
    cin >> p[i];
    p[i]--;
    int j = i-1;
    dp[i] = dp[j]+1;
    par[i] = j;
    while (j-1 >= 0 && dist[p[j-1]][p[i]] == i-(j-1)) {
      j--;
      if (dp[j]+1 < dp[i]) {
	dp[i] = dp[j]+1;
	par[i] = j;
      }
    }
  }
  {
    int i = m-1;
    cout << dp[i] << endl;
    vector<int> path;
    while (i > -1) {
      path.push_back(i);
      i = par[i];
    }
    reverse(path.begin(), path.end());
    for (int i : path)
      cout << p[i]+1 << ' ';
    cout << endl;
  }
}