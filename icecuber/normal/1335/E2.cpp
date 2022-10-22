#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10, m = 200;
int acc[nax][m];
int a[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<vector<int>> ind(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      ind[a[i]].push_back(i);
      copy_n(acc[i], m, acc[i+1]);
      acc[i+1][a[i]] = acc[i][a[i]]+1;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) ans = max(ans, acc[n][i]);
    for (auto&v : ind) {
      int l = 0, r = (int)v.size()-1;
      int base = 0;
      while (r > l) {
	base += 2;
	int a = v[l]+1, b = v[r];
	for (int j = 0; j < m; j++)
	  ans = max(ans, base+acc[b][j]-acc[a][j]);
	r--, l++;
      }
    }
    cout << ans << endl;
  }
}