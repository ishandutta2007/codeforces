#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[3000];

int sz[3000];
void Sz(int p, int par) {
  sz[p] = 1;
  for (int i : node[p]) {
    if (i != par) {
      Sz(i, p);
      sz[p] += sz[i];
    }
  }
}

ll mem[3000][3000];
ll dfs(int a, int b, int pa, int pb) {
  ll&memo = mem[a][b];
  if (!memo) {
    ll ans = 0;
    for (int ca : node[a]) {
      if (ca != pa)
	ans = max(ans, dfs(ca, b, a, pb) + sz[ca] * sz[b]);
    }
    for (int cb : node[b]) {
      if (cb != pb)
	ans = max(ans, dfs(a, cb, pa, b) + sz[a] * sz[cb]);
    }
    //cout << a << ' '<< b << ": " << ans << endl;
    memo = ans+1;
  }
  return memo-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j : node[i]) {
      Sz(i, j);
      Sz(j, i);
      ans = max(ans, dfs(i,j,j,i) + sz[i]*sz[j]);
    }
  }
  cout << ans << endl;
}