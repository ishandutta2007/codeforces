#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200000];
int col[200000], col1s;
void dfs(int p, int c = 1) {
  if (col[p]) return;
  col1s += c==1;
  col[p] = c;
  for (int i : node[p]) {
    dfs(i, 3-c);
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    fill_n(col, n, 0);
    for (int i = 0; i < n; i++)
      node[i].clear();
    while (m--) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    col1s = 0;
    dfs(0);
    if (col1s <= n/2) {
      cout << col1s << endl;
      for (int i = 0; i < n; i++)
	if (col[i] == 1)
	  cout << i+1 << ' ';
      cout << endl;
    } else {
      cout << n-col1s << endl;
      for (int i = 0; i < n; i++)
	if (col[i] == 2)
	  cout << i+1 << ' ';
      cout << endl;
    }
  }
}