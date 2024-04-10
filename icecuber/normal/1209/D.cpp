#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100000];
int done[100000];
void dfs(int p) {
  if (done[p]++) return;
  for (int i : node[p]) dfs(i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (node[i].size()) {
      ans++;
      if (!done[i]) {
	ans--;
	dfs(i);
      }
    }
  }
  cout << m-ans << endl;
}