#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200000];
int oddsz[200000], evensz[200000];
ll ans = 0, n;

void dfs(int p, int par = -1) {
  evensz[p] = 1;
  oddsz[p] = 0;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i, p);
    ll sz = oddsz[i]+evensz[i];
    ans += sz*(n-sz);
    evensz[p] += oddsz[i];
    oddsz[p] += evensz[i];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0);
  cout << (ans+1ll*evensz[0]*oddsz[0])/2 << endl;
}