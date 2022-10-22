#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int m = 1;
  while (m*2 <= n) m *= 2;
  vector<pair<int,int>> ans;
  for (int it : {0,1}) {
    int off = it*(n-m);
    for (int step = 1; step < m; step *= 2) {
      for (int i = 0; i < m; i += step*2) {
	for (int j = 0; j < step; j++) {
	  ans.emplace_back(off+i+j,  off+i+j+step);
	}
      }
    }
  }
  cout << ans.size() << endl;
  for (auto [a,b] : ans) cout << a+1 << ' ' << b+1 << '\n';
}