#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  map<int,vector<int>> x, y;
  for (int i = 0; i < 3; i++) {
    int a, b;
    cin >> a >> b;
    x[a].push_back(b),y[b].push_back(a);
  }
  if (x.size()==1 || y.size()==1) {
    cout << 1 << endl;
    return 0;
  }
  int ans = 3;
  if (x.size() == 2 && y.size() == 2) ans = 2;
  else if (x.size() == 2 && y.begin()->second[0] != y.rbegin()->second[0] ||
	   y.size() == 2 && x.begin()->second[0] != x.rbegin()->second[0]) ans = 2;
  cout << ans << endl;
}
//vekkerklokke