#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) node[i].clear();
    while (m--) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
    }
    vector<int> depth(n);
    vector<int> ans;
    for (int p = 0; p < n; p++) {
      if (depth[p] >= 2) {
	ans.push_back(p);
	continue;
      }
      for (int i : node[p]) {
	depth[i] = max(depth[i], depth[p]+1);
      }
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i+1 << ' ';
    cout << endl;
  }
}