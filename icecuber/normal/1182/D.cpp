#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100000];

int par[100000], maxd = -1, edge;
void dfs(int p, int d = 0, int parent = -1) {
  par[p] = parent;
  if (d > maxd) maxd = d, edge = p;
  for (int i : node[p]) {
    if (i == parent) continue;
    dfs(i, d+1, p);
  }
}

vector<int> v[100000];
void dfscheck(int p, int d = 0, int par = -1) {
  v[d].push_back(node[p].size());
  for (int i : node[p])
    if (i != par)
      dfscheck(i,d+1,p);
}

int n;
void check(int p) {
  for (int i = 0; i < n; i++)
    v[i].clear();
  dfscheck(p);
  int ok = 1;
  for (int i = 0; i < n; i++)
    for (int j = 1; j < v[i].size(); j++)
      if (v[i][j] != v[i][0]) ok = 0;
  if (ok) {
    cout << p+1 << endl;
    exit(0);
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
  int leafa = edge;
  maxd = -1;
  dfs(edge);
  int leafb = edge;
  check(leafa);
  check(leafb);
  if (maxd%2 == 0) {
    int p = leafb;
    for (int i = 0; i < maxd/2; i++) p = par[p];
    check(p);
    int mi = 1e9, mii = -1;
    for (int i : node[p]) {
      int d = 0, ok = 1, prev = p;
      while (node[i].size() > 1) {
	if (node[i].size() > 2) { ok = 0; break; }
	int tmp = i;
	i = node[i][0] == prev ? node[i][1] : node[i][0];
	prev = tmp;
	d++;
      }
      if (ok && d < mi) {
	mi = d;
	mii = i;
      }
    }
    if (mii != -1) check(mii);
  }
  cout << -1 << endl;
}