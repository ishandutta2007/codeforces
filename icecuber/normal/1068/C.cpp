#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> rook[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int e = n+1;
  while (m--) {
    int a, b;
    cin >> a >> b;
    rook[a].push_back(e);
    rook[b].push_back(e);
    e++;
  }
  for (int i = 1; i <= n; i++) {
    if (!rook[i].size()) cout << 1 << endl << i << ' ' << i << endl;
    else {
      cout << rook[i].size() << endl;
      for (int j : rook[i]) cout << i << ' ' << j << endl;
    }
  }
}