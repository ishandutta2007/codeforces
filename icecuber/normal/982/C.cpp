#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
int ans = 0;
vector<int> node[nax];
int sz[nax];
void dfs(int p, int par = -1) {
  sz[p] = 1;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i, p);
    sz[p] += sz[i];
  }
  ans += sz[p]%2 == 0 && par != -1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  if (n%2) {
    cout << -1 << endl;
    return 0;
  }
  dfs(0);
  cout << ans << endl;
}