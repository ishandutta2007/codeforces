#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<int> node[200000];

int getDepth(int p) {
  cout << "d " << p+1 << endl;
  int depth;
  cin >> depth;
  return depth;
}

int parent[200000];
int depth[200000];
void setDepth(int maxdepth, int p, int par = -1, int d = 0) {
  depth[p] = d;
  parent[p] = par;
  node[p].erase(par);
  if (d == maxdepth)
    node[p].clear();
  for (int i : node[p])
    setDepth(maxdepth, i, p, d+1);
}

int sz[200000];
int newroot;
void genSizes(int n, int maxdepth, int p) {
  sz[p] = (depth[p] == maxdepth);
  int good_root = 1;
  for (int i : node[p]) {
    genSizes(n, maxdepth, i);
    sz[p] += sz[i];
    if (sz[i] >= (n+1)/2) good_root = 0;
  }
  if (sz[p] < (n+1)/2) good_root = 0;
  if (good_root) newroot = p;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].insert(b);
    node[b].insert(a);
  }
  int root = 0;
  int depth_x = getDepth(root);
  setDepth(depth_x, root);
  while (1) {
    //cerr << "Root: " << root+1 << endl;
    genSizes(0, depth_x, root);
    //cerr << "Size: " << sz[root] << endl;
    newroot = -1;
    genSizes(sz[root], depth_x, root);
    assert(newroot != -1);
    if (sz[root] == 1) {
      cout << "! " << newroot+1 << endl;
      return 0;
    }
    int d = getDepth(newroot);
    if (d == 0) {
      root = newroot;
      continue;
    }
    if (depth[newroot]+d == depth_x) {
      root = newroot;
      cout << "s " << newroot+1 << endl;
      int subtree;
      cin >> subtree;
      root = subtree-1;
    } else {
      node[parent[newroot]].erase(newroot);
    }
  }
}