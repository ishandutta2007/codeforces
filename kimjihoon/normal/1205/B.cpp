#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

vector<int> r[109], v[100009];
map<int, bool> mp[100009];
int d[100009], vs[100009], rc = 0, ans = 1000000000;
queue<pair<int, int> > q;

int sp(int ra, int rb)
{
	while (!q.empty()) q.pop();
	q.push(make_pair(ra, 0));
	rc++;
	while (!q.empty()) {
		int hn = q.front().first, hc = q.front().second; q.pop();
		if (hn == rb) return hc;
		for (int i = 0; i < v[hn].size(); i++) {
			int tn = v[hn][i];
			if (hn == ra && tn == rb) continue;
			if (vs[tn] != rc) {
				vs[tn] = rc; q.push(make_pair(tn, hc + 1));
			}
		}
	}
	return 1000000000;
}

void dfs(int n, int dt)
{
	d[n] = dt;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (d[tn]) {
			if (d[tn] < d[n] && d[tn] + 1 != d[n]) 
				ans = min(ans, sp(n, tn) + 1);
		}
		else
			dfs(tn, dt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		long long a; cin >> a;
		for (int j = 0; (1LL << j) <= a; j++)
			if ((1LL << j) & a) {
				r[j].push_back(i);
			}
	}
	for (int i = 0; i < 70; i++) {
		if (r[i].size() >= 3) {
			cout << 3 << '\n';
			return 0;
		}
		if (r[i].size() == 2) {
			int a = r[i][0], b = r[i][1];
			if (mp[a].find(b) != mp[a].end()) continue;
			mp[a][b] = mp[b][a] = true; v[a].push_back(b); v[b].push_back(a);
		}
	}
	for (int i = 0; i < n; i++)
		if (d[i] == 0)
			dfs(i, 1);
	if (ans == 1000000000) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}