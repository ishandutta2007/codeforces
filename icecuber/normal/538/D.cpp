#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string board[50];
string ans[99];
int good[50][50];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> board[i];
  for (int i = -n+1; i < n; i++) {
    for (int j = -n+1; j < n; j++) {
      int ok = 1;
      for (int k = 0; k < n; k++)
	for (int l = 0; l < n; l++)
	  if (board[k][l] == 'o' &&
	      k+i >= 0 && k+i < n && j+l >= 0 && j+l < n &&
	      board[k+i][j+l] == '.') ok = 0;
      for (int k = 0; k < n; k++)
	for (int l = 0; l < n; l++)
	  if (ok && board[k][l] == 'o' &&
	      k+i >= 0 && k+i < n && j+l >= 0 && j+l < n &&
	      board[k+i][j+l] == 'x') good[k+i][j+l] = 1;
      ans[i+(n-1)] += ok ? 'x' : '.';
      if (i == 0 && j == 0) ans[n-1][n-1] = 'o';
    }
  }
  int ok = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (board[i][j] == 'x' && !good[i][j]) ok = 0;
  if (!ok) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  for (int i = 0; i < n*2-1; i++)
    cout << ans[i] << endl;
}