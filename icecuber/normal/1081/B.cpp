#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000], b[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int, vector<int>> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[n-a[i]].push_back(i);
  }
  int col = 1;
  for (auto p : m) {
    auto&v = p.second;
    if (v.size()%p.first) {
      cout << "Impossible" << endl;
      return 0;
    }
    for (int i = 0; i < v.size()/p.first; i++) {
      for (int j = 0; j < p.first; j++)
	b[v[i*p.first+j]] = col;
      col++;
    }
  }
  cout << "Possible" << endl;
  for (int i = 0; i < n; i++)
    cout << b[i] << ' ';
  cout << endl;
}