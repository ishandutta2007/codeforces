#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 5000;
vector<int> node[nax], rnode[nax];

vector<int> topo;
int done1[nax];
void dfs1(int p) {
  if (done1[p]++) return;
  for (int i : node[p]) dfs1(i);
  topo.push_back(p);
}

int component[nax], components = 0;
int done2[nax];
void dfs2(int p) {
  if (done2[p]++) return;
  for (int i : rnode[p]) dfs2(i);
  component[p] = components;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, s;
  cin >> n >> m >> s;
  s--;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    rnode[b].push_back(a);
  }
  for (int i = 0; i < n; i++) dfs1(i);
  reverse(topo.begin(), topo.end());
  for (int i : topo) {
    if (!done2[i]) {
      dfs2(i);
      components++;
    }
  }

  vector<int> ins(n);
  for (int i = 0; i < n; i++) {
    for (int j : node[i]) {
      if (component[i] != component[j])
	ins[component[j]]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < components; i++) {
    ans += !ins[i] && i != component[s];
  }
  cout << ans << endl;
}