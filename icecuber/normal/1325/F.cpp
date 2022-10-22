#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
vector<int> node[nax];
int depth[nax];
vector<int> child[nax];

int need;
void dfs1(int p, int par = -1, int d = 0) {
  static vector<int> stack = {};
  if (depth[p] != -1) {
    if (d-depth[p] >= need) {
      cout << 2 << endl;
      cout << d-depth[p] << endl;
      for (int i = depth[p]; i < d; i++)
	cout << stack[i]+1 << ' ';
      cout << endl;
      exit(0);
    }
    return;
  }
  if (par != -1)
    child[par].push_back(p);
  depth[p] = d;
  stack.push_back(p);
  for (int i : node[p]) {
    if (i == par) continue;
    dfs1(i, p, d+1);
  }
  stack.pop_back();
}

vector<int> indep;
int dfs2(int p, int par = -1) {
  int mind = need;
  for (int i : child[p]) {
    mind = min(mind, dfs2(i));
  }
  if (mind >= need-1) {
    indep.push_back(p);
    mind = 0;
  }
  return mind+1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  need = 0;
  while (need*need < n) need++;

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  fill_n(depth, nax, -1);
  dfs1(0);

  dfs2(0);
  assert((int)indep.size() >= need);
  indep.resize(need);
  cout << 1 << endl;
  for (int i : indep) cout << i+1 << ' ';
  cout << endl;
}