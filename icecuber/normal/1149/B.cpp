#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mynext[100001][26];
int dp[251][251][251];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int last[26];
  for (int i = 0; i < 26; i++) last[i] = n;
  for (int i = n-1; i >= 0; i--) {
    last[s[i]-'a'] = i;
    for (int j = 0; j < 26; j++)
      mynext[i][j] = last[j];
  }
  string rel[3] = {};
  while (q--) {
    char cmd;
    int i;
    cin >> cmd >> i;
    i--;
    if (cmd == '-') {
      rel[i].pop_back();
    } else {
      char c;
      cin >> c;
      rel[i] += c;
      for (int a = (i==0?rel[0].size():0); a <= rel[0].size(); a++) {
	for (int b = (i==1?rel[1].size():0); b <= rel[1].size(); b++) {
	  for (int c = (i==2?rel[2].size():0); c <= rel[2].size(); c++) {
	    dp[a][b][c] = a+b+c ? n+1 : 0;
	    if (a && dp[a-1][b][c] < n)
	      dp[a][b][c] = min(dp[a][b][c], mynext[dp[a-1][b][c]][rel[0][a-1]-'a']+1);
	    if (b && dp[a][b-1][c] < n)
	      dp[a][b][c] = min(dp[a][b][c], mynext[dp[a][b-1][c]][rel[1][b-1]-'a']+1);
	    if (c && dp[a][b][c-1] < n)
	      dp[a][b][c] = min(dp[a][b][c], mynext[dp[a][b][c-1]][rel[2][c-1]-'a']+1);
	  }
	}
      }
    }
    cout << (dp[rel[0].size()][rel[1].size()][rel[2].size()] <= n ? "YES" : "NO") << endl;
  }
}