#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a[4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      int v;
      cin >> v;
      a[i].push_back(v);
    }
  }

  vector<tuple<int,int,int>> path;
  int parked = 0;
  while (parked < m) {
    int fr = -1, fc = -1;
    for (int k = 0; k < 2; k++) {
      for (int j = 0; j < n; j++) {
	if (a[k+1][j] && a[k+1][j] == a[k*3][j]) {
	  path.emplace_back(a[k+1][j], k*3, j);
	  a[k+1][j] = 0;
	  parked++;
	}
	if (!a[k+1][j]) fr = k+1, fc = j;
      }
    }
    if (fr == -1) {
      cout << -1 << endl;
      return 0;
    }
    auto f = [&](int i) {
      int r = fr, c = fc;
      if (r == 2) r = 1, c = n+n-1-c;
      i = (c+i)%(n*2);
      if (i < n) return make_pair(1,i);
      else return make_pair(2,n-1-(i-n));
    };

    for (int i = 0; i < 2*n-1; i++) {
      auto [ar,ac] = f(i+1);
      auto [br,bc] = f(i);
      if (a[ar][ac]) {
	path.emplace_back(a[ar][ac], br, bc);
	swap(a[br][bc], a[ar][ac]);
      }
    }
  }
  cout << path.size() << endl;
  for (auto [a,b,c] : path)
    cout << a << ' ' << b+1 << ' ' << c+1 << '\n';
}