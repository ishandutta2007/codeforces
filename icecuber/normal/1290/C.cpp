#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 3e5;
set<int> s[nax];
int cost[nax];

int par[nax];
int find(int p) {
  return p == par[p] ? p : par[p] = find(par[p]);
}
vector<int> has[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  string start;
  cin >> start;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      x--;
      has[x].push_back(i);
      s[i].insert(x);
    }
    par[i] = i;
    cost[i] = 1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    set<int> r;
    for (int j : has[i]) {
      j = find(j);
      if (s[j].count(i)) {
	r.insert(j);
      }
    }

    int flip = '1'-start[i];
    if (r.size() == 1) {
      int j = *r.begin();
      if (flip) {
	ans += cost[j];
	for (int k : s[j])
	  start[k] ^= 1;
      }
      s[j].clear();
    } else if (r.size() == 2) {
      int a = *r.begin(), b = *r.rbegin();
      if (cost[a] > cost[b]) swap(a, b);
      if (flip) {
	ans += cost[a];
	for (int k : s[a])
	  start[k] ^= 1;
	cost[a] *= -1;
      }
      par[b] = a;
      cost[a] += cost[b];
      if (s[a].size() < s[b].size()) swap(s[a], s[b]);
      for (int k : s[b]) {
	if (s[a].count(k)) s[a].erase(k);
	else s[a].insert(k);
      }
    } else assert(!flip);
    cout << ans << '\n';
  }
}