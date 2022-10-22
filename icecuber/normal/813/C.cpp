#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200000];

int dista[200000], distb[200000];

void dfs(int*dist, int p, int par = -1, int d = 0) {
  dist[p] = d;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(dist,i,p,d+1);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x;
  cin >> n >> x;
  x--;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(dista, 0);
  dfs(distb, x);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (distb[i] < dista[i])
      ans = max(ans, dista[i]*2);
  }
  cout << ans << endl;
}