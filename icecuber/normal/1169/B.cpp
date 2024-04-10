#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<pair<int,int>, int> ma;
  vector<int> count(n+1, 0);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    count[x]++, count[y]++;
    ma[{min(x,y),max(x,y)}]++;
  }
  for (int x = 1; x <= n; x++) {
    if (count[x] < m/2) continue;
    for (int y = 1; y <= n; y++) {
      if (x == y) continue;
      pair<int,int> p = {min(x,y),max(x,y)};
      if (count[x]+count[y]-(ma.count(p) ? ma[p] : 0) == m) {
	//cout << x << ' ' << y << endl;
	cout << "YES" << endl;
	return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}