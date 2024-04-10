#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> node(n);
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }

    if (k == 1) {
      cout << n-1 << endl;
      continue;
    }

    vector<int> deg(n);
    for (int i = 0; i < n; i++)
      deg[i] = node[i].size();

    vector<int> rem(n);

    map<int,vector<int>> children;

    queue<int> todo;

    int ans = 0;
    auto add = [&](int p, int c) {
      children[p].push_back(c);
      if ((int)children[p].size() == k) {
	ans++;
	deg[p] -= k;
	if (deg[p] == 1) todo.push(p);
	for (int i : children[p]) {
	  rem[i] = 1;
	  //cout << i+1 << ' ';
	}
	//cout << endl;
	children[p].clear();
      }
    };

    for (int i = 0; i < n; i++) {
      if (deg[i] == 1) {
	todo.push(i);
      }
    }

    while (todo.size()) {
      int i = todo.front();
      todo.pop();

      if (!rem[i] && deg[i] == 1) {
	deg[i] = 0;
	int par;
	for (int j : node[i])
	  if (!rem[j]) par = j;
	add(par, i);
      }
    }
    cout << ans << endl;
  }
}