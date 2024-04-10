#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s[2000];
int col_sum[2001][2001];
int row_sum[2001][2001];
int col_score[2001][2001];
int row_score[2001][2001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      col_sum[i+1][j] = (s[i][j] == 'B')+col_sum[i][j];
      row_sum[i+1][j] = (s[j][i] == 'B')+row_sum[i][j];
    }
  }

  for (int t : {0,1}) {
    int (*score)[2001] = t ? row_score : col_score;
    int (*sum)[2001] = t ? row_sum : col_sum;
    for (int i = 0; i+k <= n; i++) {
      for (int x = 0; x < k; x++)
	score[i][0] += (sum[n][x]-sum[i+k][x]+sum[i][x] == 0);
      for (int x = k; x < n; x++)
	score[i][0] += (sum[n][x] == 0);

      for (int x = 1; x+k <= n; x++) {
	score[i][x] = score[i][x-1]+
	  (sum[n][x-1] == 0)-
	  (sum[n][x-1]-sum[i+k][x-1]+sum[i][x-1] == 0)-
	  (sum[n][x+k-1] == 0)+
	  (sum[n][x+k-1]-sum[i+k][x+k-1]+sum[i][x+k-1] == 0);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i+k <= n; i++) {
    for (int j = 0; j+k <= n; j++) {
      ans = max(ans, col_score[i][j]+row_score[j][i]);
    }
  }
  cout << ans << endl;
}