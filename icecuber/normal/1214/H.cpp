#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200000];

int furthest(int p, int depth = 0, int par = -1) {
  static int ans, max_depth;
  if (depth == 0 || depth > max_depth) {
    max_depth = depth;
    ans = p;
  }
  for (int i : node[p]) {
    if (i == par) continue;
    furthest(i, depth+1, p);
  }
  return ans;
}


int col[200000];
int n, k;

int node_depth[200000], max_depth[200000], heavy[200000];
void dfs1(int p, int depth = 0, int par = -1) {
  node_depth[p] = depth;
  max_depth[p] = 0;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs1(i,depth+1,p);
    if (max_depth[i]+1 > max_depth[p]) {
      heavy[p] = i;
      max_depth[p] = max_depth[i]+1;
    }
  }
}

void greedy(int p, int c, int dc, int par) {
  c = (c+k+dc)%k;
  col[p] = c;
  for (int i : node[p]) {
    if (i == par) continue;
    greedy(i, c, dc, p);
  }
}

void check(int a, int b, int c) {
  if (k > 2 && a+b+1 >= k && a+c+1 >= k && b+c+1 >= k) {
    cout << "No" << endl;
    exit(0);
  }
}

void dfs2(int p, int depth = 0, int par = -1) {
  col[p] = depth%k;
  for (int i : node[p]) {
    if (i == par) continue;
    if (i == heavy[p]) {
      dfs2(i, depth+1, p);
    } else {
      check(max_depth[p], depth, max_depth[i]+1);
      //cout << p+1 << ' ' << depth << ' ' << max_depth[p] << endl;
      greedy(i, depth%k, depth > max_depth[p] ? 1 : -1, p);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  int x = furthest(0);
  int root = furthest(x);
  dfs1(root);
  dfs2(root);
  cout << "Yes" << endl;
  for (int i = 0; i < n; i++)
    cout << col[i]+1 << ' ';
  cout << endl;
}