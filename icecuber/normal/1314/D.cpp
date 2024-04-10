#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist0[80][80];
int dist[80][80];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dist0[i][j];
    }
  }
  mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());
  int ans = 1e9;
  for (int it = 0; it < 10000; it++) {
    vector<int> side(n);
    for (int i = 0; i < n; i++) {
      side[i] = mrand()%2;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	dist[i][j] = side[i] != side[j] ? dist0[i][j] : 1e9;

    vector<int> cost(n, 1e9);
    cost[0] = 0;
    for (int i = 0; i < k; i++) {
      vector<int> ncost(n, 1e9);
      for (int a = 0; a < n; a++)
	for (int b = 0; b < n; b++)
	  ncost[a] = min(ncost[a], cost[b]+dist[b][a]);
      swap(cost, ncost);
    }
    ans = min(ans, cost[0]);
  }
  cout << ans << endl;
}