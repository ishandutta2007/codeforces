#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int eq[1000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> query;
  while (m--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      for (int i = l; i < r; i++)
	eq[i] = 1;
    } else query.emplace_back(l,r);
  }

  for (auto p : query) {
    int l = p.first, r = p.second;
    int ok = 0;
    for (int i = l; i < r; i++)
      if (!eq[i]) ok = 1;
    if (!ok) {
      cout << "NO" << endl;
      return 0;
    }
  }
  int v = n;
  cout << "YES" << endl;
  cout << v;
  for (int i = 1; i < n; i++) {
    if (!eq[i]) v--;
    cout << ' ' << v;
  }
  cout << endl;
}