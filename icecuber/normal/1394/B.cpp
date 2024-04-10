#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];
bitset<nax> reach[10][10];
int bad[10][10];
int collide[10][10][10][10];

int ans = 0;
void rec(vector<int> path, int k) {
  int p = path.size();
  if (p == k) {
    ans++;
    return;
  }
  for (int i = 0; i <= p; i++) {
    int ok = !bad[p][i];
    for (int j = 0; j < p; j++) {
      if (collide[j][path[j]][p][i]) ok = 0;
    }
    if (ok) {
      path.push_back(i);
      rec(path, k);
      path.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<array<int,3>> edge;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--, b--, w--;
    edge.push_back({w, a,b});
  }
  sort(edge.begin(), edge.end());
  for (auto [w, a,b] : edge)
    node[a].push_back(b);

  for (int i = 0; i < k; i++) {
    for (int j = 0; j <= i; j++) {
      for (int p = 0; p < n; p++) {
	if ((int)node[p].size() != i+1) continue;
	if (reach[i][j][node[p][j]])
	  bad[i][j] = 1;
	reach[i][j][node[p][j]] = 1;
      }
    }
  }

  for (int i = 0; i < k; i++)
    for (int j = 0; j <= i; j++)
      for (int ii = 0; ii < k; ii++)
	for (int jj = 0; jj <= ii; jj++) {
	  if (bad[i][j] || bad[ii][jj] || (reach[i][j]&reach[ii][jj]).any())
	    collide[i][j][ii][jj] = 1;
	}
  rec({}, k);
  cout << ans << endl;
}