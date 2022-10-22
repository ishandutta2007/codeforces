#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int nax = 2e5+10;
vector<array<int,2>> node[nax], rnode[nax];
 
vector<int> topo;
int done1[nax];
void dfs1(int p) {
  if (done1[p]++) return;
  for (auto [i,l] : node[p]) dfs1(i);
  topo.push_back(p);
}
 
int comp[nax];
ll dp[nax];
ll G[nax];
int comps = 1;
void dfs2(int p, ll len = 0) {
  if (comp[p]) return;
  dp[p] = len;
  comp[p] = comps;
  for (auto [i,l] : rnode[p]) {
    if (comp[i] == comps) {
      G[comps] = gcd(G[comps], len+l - dp[i]);
    } else 
      dfs2(i, len+l);
  }
}
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].push_back({b,c});
    rnode[b].push_back({a,c});
  }
  for (int i = 0; i < n; i++) {
    dfs1(i);
  }
  reverse(topo.begin(), topo.end());
  for (int i : topo) {
    if (!comp[i]) {
      dfs2(i);
      comps++;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int p, a, mod;
    cin >> p >> a >> mod;
    p--;
    cout << (gcd(a,mod)%gcd(G[comp[p]],mod) == 0 ? "YES" : "NO") << '\n';
  }
}