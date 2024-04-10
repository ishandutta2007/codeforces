#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<pair<int, int>> node[nax];

int n;
ll G, B;
int extra[nax], ma[nax], sz[nax];
void dfs(int p, int par) {
  extra[p] = 1;
  sz[p] = 1;
  ma[p] = 1;
  for (auto [i,c] : node[p]) {
    if (i == par) continue;
    dfs(i, p);
    G += (ll)c*extra[i];
    extra[p] += extra[i];
    sz[p] += sz[i];
    B += (ll)c*ma[i];
    ma[p] += ma[i];
  }
  // ma[p] <= n-sz[p]
  int k = (ma[p]-(n-sz[p])+1)/2;
  if (k > 0)
    ma[p] -= 2*k;
  extra[p] %= 2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i++) node[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      node[a].emplace_back(b, c);
      node[b].emplace_back(a, c);
    }
    G = B = 0;
    dfs(0, -1);
    cout << G << ' ' << B << endl;
  }
}