#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100000], rnode[100000];

int done1[100000];
vector<int> topo;
void dfs1(int p) {
  if (done1[p]++) return;
  for (int i : node[p])
    dfs1(i);
  topo.push_back(p);
}

int components = 1;
int sz = 0;
int component[100000];
int done2[100000];
vector<int> v;
void dfs2(int p) {
  if (done2[p]++) return;
  for (int i : rnode[p]) {
    dfs2(i);
  }
  component[p] = components;
  v.push_back(p);
  sz++;
}

int u[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, h;
  cin >> n >> m >> h;
  for (int i = 0; i < n; i++) {
    cin >> u[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    assert(u[a] != u[b]);
    if ((u[a]+1)%h == u[b]) {
      node[a].push_back(b);
      rnode[b].push_back(a);
    }
    if ((u[b]+1)%h == u[a]) {
      node[b].push_back(a);
      rnode[a].push_back(b);
    }
  }

  for (int i = 0; i < n; i++) {
    dfs1(i);
  }

  /*for (int i = 0; i < n; i++)
    for (int j : node[i])
    cout << i << ' ' << j << endl;*/

  reverse(topo.begin(), topo.end());
  int ans = n+1, best = -1;
  for (int i : topo) {
    if (done2[i]) continue;
    sz = 0;
    v.clear();
    dfs2(i);
    for (int j : v)
      for (int k : node[j])
	if (component[k] != components)
	  sz = 1e9;
    //cout << i << ' ' << sz << endl;
    if (sz < ans) {
      ans = sz;
      best = components;
    }
    components++;
  }
  /*for (int i = 0; i < n; i++)
    cout << component[i] << ' ';
    cout << endl;*/

  cout << ans << endl;
  for (int i = 0; i < n; i++)
    if (component[i] == best) {
      cout << i+1 << ' ';
    }
  cout << endl;
}