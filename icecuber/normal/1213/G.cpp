#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
ll ans[nax];
int sz[nax], par[nax];

int find(int p) {
  return p == par[p] ? p : (par[p] = find(par[p]));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    par[i] = i, sz[i] = 1;
  vector<tuple<int,int,int>> edges;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({c,a-1,b-1});
  }
  sort(edges.begin(), edges.end());
  for (auto e : edges) {
    int a, b, c;
    tie(c,a,b) = e;
    a = find(a);
    b = find(b);
    if (a == b) continue;
    if (sz[a] < sz[b]) swap(a,b);
    ans[c] += (ll)sz[a]*sz[b];
    sz[a] += sz[b];
    par[b] = a;
  }
  for (int i = 1; i < nax; i++)
    ans[i] += ans[i-1];
  while (q--) {
    int v;
    cin >> v;
    cout << ans[v] << ' ';
  }
  cout << endl;
}