#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[2][1000][1000];
int dp[1000][1000];
char par[1000][1000];

pair<int,string> solve(int a[][1000], int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      dp[i][j] = i+j == 0 ? a[i][j] : 1e9;
      if (i) {
	int v = dp[i-1][j]+a[i][j];
	if (v < dp[i][j]) {
	  dp[i][j] = v;
	  par[i][j] = 'D';
	}
      }
      if (j) {
	int v = dp[i][j-1]+a[i][j];
	if (v < dp[i][j]) {
	  dp[i][j] = v;
	  par[i][j] = 'R';
	}
      }
    }

  string path;
  int i = n-1, j = n-1;
  while (i+j) {
    path += par[i][j];
    if (par[i][j] == 'D') assert(i--);
    else if (par[i][j] == 'R') assert(j--);
    else assert(0);
  }
  reverse(path.begin(), path.end());
  return {dp[n-1][n-1],path};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int zero = 0, zi, zj;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int w;
      cin >> w;
      while (w && w%2 == 0) a[0][i][j]++, w /= 2;
      while (w && w%5 == 0) a[1][i][j]++, w /= 5;
      if (!w) zero = 1, zi = i, zj = j, a[0][i][j] = a[1][i][j] = 1;
    }
  auto x = min(solve(a[0], n), solve(a[1], n));
  if (x.first && zero) {
    x.first = 1;
    x.second = "";
    for(int i = 0; i < zi; i++)
      x.second += 'D';
    for(int j = 0; j < zj; j++)
      x.second += 'R';
    for(int i = 0; i < n-1-zi; i++)
      x.second += 'D';
    for(int j = 0; j < n-1-zj; j++)
      x.second += 'R';
  }
  cout << x.first << endl << x.second << endl;
}