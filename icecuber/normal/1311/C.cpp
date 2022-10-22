#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cnt(26,vector<int>(n+1));
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 26; j++)
	cnt[j][i+1] = cnt[j][i]+(s[i] == 'a'+j);
    }
    vector<int> ans(26);
    for (int i = 0; i < m; i++) {
      int p;
      cin >> p;
      for (int j = 0; j < 26; j++)
	ans[j] += cnt[j][p];
    }
    for (int j = 0; j < 26; j++)
      ans[j] += cnt[j][n];
    for (int j = 0; j < 26; j++)
      cout << ans[j] << ' ';
    cout << endl;
  }
}