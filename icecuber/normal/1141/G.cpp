#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200000];

int ans;

map<pair<int,int>,int> edge_col;
void dfs(int p, int par = -1, int col = -1) {
  for (int i : node[p]) {
    if (i == par) continue;
    col = (col+1)%ans;
    edge_col[{p,i}] = col;
    dfs(i, p, col);
  }
}

int a[200000], b[200000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    node[a[i]].push_back(b[i]);
    node[b[i]].push_back(a[i]);
  }
  int fail = 0, pass = n-1;
  while (pass-fail > 1) {
    int mid = pass+fail>>1;
    int bads = 0;
    for (int i = 0; i < n; i++)
      if (node[i].size() > mid)
	bads++;
    if (bads <= k) pass = mid;
    else fail = mid;
  }
  ans = pass;
  dfs(0);
  cout << ans << endl;
  for (int i = 1; i < n; i++) {
    if (!edge_col.count({a[i],b[i]})) swap(a[i],b[i]);
    cout << edge_col[{a[i],b[i]}]+1 << ' ';
  }
  cout << endl;
}