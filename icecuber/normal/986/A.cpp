#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100000];
queue<int> q[100];
int dist[100][100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  for (int a = 0; a < k; a++)
    for (int i = 0; i < n; i++)
      dist[a][i] = 1e9;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a--;
    q[a].push(i);
    dist[a][i] = 0;
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }

  for (int a = 0; a < k; a++) {
    while (q[a].size()) {
      int p = q[a].front();
      q[a].pop();
      int d = dist[a][p]+1;
      for (int i : node[p]) {
	if (d < dist[a][i]) {
	  dist[a][i] = d;
	  q[a].push(i);
	}
      }
    }
  }

  for (int i = 0; i < n; i++) {
    vector<int> d;
    for (int a = 0; a < k; a++) {
      d.push_back(dist[a][i]);
    }
    sort(d.begin(), d.end());
    int ans = 0;
    for (int i = 0; i < s; i++)
      ans += d[i];
    cout << ans << ' ';
  }
  cout << endl;
}