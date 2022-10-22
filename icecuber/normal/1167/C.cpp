#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[1000010];
int n, m;
int sz[1000010];
int col[1000010], cols = 1;

void dfs(int p) {
  if (col[p]) return;
  if (p < n) sz[cols]++;
  col[p] = cols;
  for (int i : node[p]) dfs(i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    while (k--) {
      int a;
      cin >> a;
      a--;
      node[a].push_back(i+n);
      node[i+n].push_back(a);
    }
  }
  for (int i = 0; i < n; i++) {
    if (col[i]) continue;
    dfs(i);
    cols++;
  }
  for (int i = 0; i < n; i++)
    cout << sz[col[i]] << ' ';
  cout << endl;
}