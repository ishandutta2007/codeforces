#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sparse[20][1<<19];

#define s first
#define p second

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> sparse[0][i];
    }
    for (int l = 0; l+1 < 20; l++)
      for (int j = 0; j+(1<<l+1) <= n; j++)
	sparse[l+1][j] = max(sparse[l][j], sparse[l][j+(1<<l)]);

    int m;
    cin >> m;
    vector<pair<int,int>> hero(m);
    for (int i = 0; i < m; i++) {
      cin >> hero[i].p >> hero[i].s;
    }
    sort(hero.begin(), hero.end());
    vector<pair<int,int>> pareto;
    for (auto h : hero) {
      while (pareto.size() && h.p >= pareto.back().p)
	pareto.pop_back();
      pareto.push_back(h);
    }

    int ans = 0, ai = 0;
    while (ai < n) {
      int pass = ai, fail = n+1;
      while (fail-pass > 1) {
	int mid = pass+fail>>1;
	int l = 0;
	while ((2<<l) < mid-ai) l++;
	int ma = max(sparse[l][ai], sparse[l][mid-(1<<l)]);
	auto it = lower_bound(pareto.begin(), pareto.end(), make_pair(mid-ai, 0));
	if (it != pareto.end() && it->p >= ma)
	  pass = mid;
	else
	  fail = mid;
      }
      if (pass == ai) {
	cout << -1 << '\n';
	break;
      }
      ai = pass;
      ans++;
    }
    if (ai == n)
      cout << ans << '\n';
  }
}