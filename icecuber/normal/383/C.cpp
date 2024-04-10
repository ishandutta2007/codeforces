#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;

vector<int> node[nax];
int a[nax], b[nax], depth[nax], v[nax], id = 5;
void dfs(int p, int d = 0, int par = -1) {
  depth[p] = d;
  if (d%2) v[p] *= -1;
  a[p] = id++;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i,d+1,p);
  }
  b[p] = id;
}

int data[nax];
void add(int i, int v) {
  for (; i; i -= i&-i) data[i] += v;
}

void add(int a, int b, int v) {
  add(b-1, v);
  add(a-1, -v);
}

int query(int i) {
  int r = 0;
  for (; i < nax; i += i&-i) r += data[i];
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0);
  for (int i = 0; i < n; i++)
    add(a[i],a[i]+1,v[i]);
  while (q--) {
    int type, x;
    cin >> type >> x;
    x--;
    if (type == 1) {
      int val;
      cin >> val;
      add(a[x], b[x], val*(depth[x]%2 ? -1 : 1));
    } else {
      cout << query(a[x])*(depth[x]%2 ? -1 : 1) << endl;
    }
  }
}