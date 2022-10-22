#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
vector<int> node[nax];

int reach[nax], done[nax], cyclei[nax], clen;

void umax(int base, int&a, int b) {
  if ((b-base+clen-1)%clen > (a-base+clen-1)%clen)
    a = b;
}

void dfs(int p, int base) {
  if (!done[p]) {
    done[p] = 1;
    reach[p] = (base+1)%clen;
    for (int i : node[p]) {
      //cout << p+1 << "->" << i+1 << ' ' << cyclei[i] << endl;
      int r;
      if (cyclei[i] != -1)
	r = cyclei[i];
      else {
	dfs(i, base);
	r = reach[i];
      }
      umax(base, reach[p], r);
    }
  }
}

void fail() {
  cout << -1 << endl;
  exit(0);
}

int depth[nax], col[nax];
vector<int> cycle;
int findCycle(int p, int d = 0) {
  static vector<int> path;
  if (col[p]) {
    if (col[p] == 2) return 0;
    for (int i = depth[p]; i < d; i++) {
      cycle.push_back(path[i]);
    }
    return 1;
  }
  col[p] = 1;
  depth[p] = d;
  path.push_back(p);
  for (int i : node[p]) {
    if (findCycle(i, d+1)) return 1;
  }
  col[p] = 2;
  path.pop_back();
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
  }
  for (int i = 0; i < n; i++) {
    if (findCycle(i)) break;
  }
  if (!cycle.size()) fail();

  fill_n(cyclei, n, -1);
  clen = cycle.size();
  for (int i = 0; i < clen; i++) {
    cyclei[cycle[i]] = i;
    reach[cycle[i]] = (i+1)%clen;
    //cout << cycle[i]+1 << ' ';
  }
  //cout << endl;

  for (int ci = 0; ci < clen; ci++) {
    int i = cycle[ci];
    dfs(i, ci);
    //cout << i+1 << ' ' << cycle[reach[i]]+1 << endl;
  }

  vector<int> acc(clen);
  for (int i = 0; i < clen; i++) {
    int l = (i+1)%clen, r = reach[cycle[i]];
    acc[l]++;
    acc[r]--;
    if (r < l) {
      acc[0]++;
    }
  }

  for (int i = 1; i < clen; i++)
    acc[i] += acc[i-1];
  int ans = -1;
  for (int i = 0; i < clen; i++)
    if (!acc[i]) ans = cycle[i];

  if (ans == -1) fail();
  node[ans].clear();
  for (int i = 0; i < n; i++) {
    auto it = find(node[i].begin(), node[i].end(), ans);
    if (it != node[i].end())
      node[i].erase(it);
  }
  cycle.clear();
  fill_n(col, n, 0);
  fill_n(depth, n, 0);
  for (int i = 0; i < n; i++) {
    if (!col[i])
      if (findCycle(i)) fail();
  }
  cout << ans+1 << endl;
}