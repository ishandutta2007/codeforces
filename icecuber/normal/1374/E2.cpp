#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<ll,int>> time[2][2];
  for (int i = 0; i < n; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    time[a][b].emplace_back(t, i+1);
  }
  for (int a : {0,1}) {
    for (int b : {0,1}) {
      sort(time[a][b].begin(), time[a][b].end());
    }
  }

  int both = time[1][1].size(), twos = min(time[0][1].size(), time[1][0].size());
  if (both+min(twos, (m-both)/2) < k) {
    cout << -1 << endl;
    return 0;
  }

  for (int a : {0,1}) {
    for (int b : {0,1}) {
      while ((int)time[a][b].size() <= m)
	time[a][b].emplace_back(3e9, 0);
    }
  }

  array<array<int,2>,2> c;
  c[0][0] = c[0][1] = c[1][0] = c[1][1] = 0;
  pair<ll,array<array<int,2>,2>> ans = {1e18, c};

  ll cur = 0;
  for (int i = k; i >= 0; i--) {
    array<array<int,2>,2> mi;
    mi[0][0] = 0;
    mi[0][1] = mi[1][0] = k-i;
    mi[1][1] = i;
    for (int a : {0,1}) {
      for (int b : {0,1}) {
	while (c[a][b] < mi[a][b])
	  cur += time[a][b][c[a][b]++].first;
      }
    }

    while (c[0][0]+c[0][1]+c[1][0]+c[1][1] < m) {
      cur += time[1][1][c[1][1]++].first;
    }
    while (c[0][0]+c[0][1]+c[1][0]+c[1][1] > m) {
      int found = 0;
      for (int l = 0; l < 4; l++) {
	int a = l/2, b = l%2;
	if (c[a][b] > mi[a][b]) {
	  cur -= time[a][b][--c[a][b]].first;
	  found = 1;
	  break;
	}
      }
      if (!found) break;
    }

    while (1) {
      pair<ll,int> add = {1e18, -1}, rem = {-1e18, -1};
      for (int l = 0; l < 4; l++) {
	int a = l/2, b = l%2;
	add = min(add, make_pair(time[a][b][c[a][b]].first, l));
	if (c[a][b] > mi[a][b])
	  rem = max(rem, make_pair(time[a][b][c[a][b]-1].first, l));
      }
      if (add.first < rem.first) {
	int a = add.second/2, b = add.second%2;
	cur += time[a][b][c[a][b]++].first;
	a = rem.second/2, b = rem.second%2;
	cur -= time[a][b][--c[a][b]].first;
      } else break;
    }

    if (c[0][0]+c[0][1]+c[1][0]+c[1][1] == m)
      ans = min(ans, make_pair(cur, c));
  }
  cout << ans.first << endl;
  for (int a : {0,1}) {
    for (int b : {0,1}) {
      for (int i = 0; i < ans.second[a][b]; i++)
	cout << time[a][b][i].second << ' ';
    }
  }
  cout << endl;
}