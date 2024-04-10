#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 3e5+10;
int par[nax], sz[nax];
ll tons[nax];

vector<array<int,2>> edge[nax];

int Find(int p) {
  return p == par[p] ? p : par[p] = Find(par[p]);
}

void join(int a, int b) {
  a = Find(a);
  b = Find(b);
  if (a == b) return;
  if (sz[b] > sz[a]) swap(a, b);
  par[b] = a;
  sz[a] += sz[b];
  tons[a] += tons[b];
  if (edge[b].size() > edge[a].size()) swap(edge[a], edge[b]);
  for (auto e : edge[b]) {
    edge[a].push_back(e);
  }
  edge[b].clear();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m, x;
  cin >> n >> m >> x;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> tons[i];
    sum += tons[i];
  }
  if (sum < (n-1)*x) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++)
    par[i] = i, sz[i] = 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge[a].push_back({b,i+1});
    edge[b].push_back({a,i+1});
  }
  set<pair<ll,int>> stons;
  for (int i = 0; i < n; i++) {
    stons.insert({tons[i],i});
  }
  for (int it = 1; it < n; it++) {
    int p = Find(stons.rbegin()->second);
    stons.erase({tons[p], p});
    while (1) {
      auto [nbr,idx] = edge[p].back();
      edge[p].pop_back();
      nbr = Find(nbr);
      if (nbr == p) continue;
      assert(tons[nbr]+tons[p] >= x);
      stons.erase({tons[nbr], nbr});
      join(p, nbr);
      p = Find(p);
      tons[p] -= x;
      cout << idx << '\n';
      break;
    }
    stons.insert({tons[p], p});
  }
  //assert(sz[Find(0)] == n);
}