#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; i++)
    edges.emplace_back(i, i+1);
  for (int i = 1; i <= n; i++) {
    if (edges.size() >= m) break;
    for (int j = 1; j < i-1; j++) {
      if (gcd(i,j) == 1) {
	edges.emplace_back(i,j);
      }
      if (edges.size() >= m) break;
    }
  }
  if (edges.size() != m) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for (auto [a,b] : edges) {
    cout << a << ' ' << b << endl;
  }
}