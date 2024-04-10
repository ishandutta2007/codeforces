#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int adj[50][50];
int solid[50][50];
int deg[50];
int done[50];

int n, m;
int dfs(int p, int par, int target) {
  if (par == -1) fill_n(done, n, 0);
  if (done[p]++) return 0;
  if (deg[p] <= target) return 1;
  for (int i = 0; i < n; i++) {
    if (adj[p][i] && !solid[p][i] && dfs(i,p,target)) {
      deg[p]--;
      deg[i]++;
      adj[p][i] = 0;
      adj[i][p] = 1;
      return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      adj[i][j] = i < j;

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a][b] = 1;
    adj[b][a] = 0;
    solid[a][b] = solid[b][a] = 1;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      deg[i] += adj[i][j];

  int change = 1;
  while (change) {
    change = 0;
    for (int i = 0; i < n; i++) {
      while (dfs(i, -1, deg[i]-2)) {
	/*for (int j = 0; j < n; j++)
	  cout << deg[j] << ' ';
	  cout << endl;*/
	change = 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << adj[i][j];
    cout << endl;
  }
}