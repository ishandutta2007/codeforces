#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, a[200009], d[2][200009];
pair<int, int> p[200009];
vector<int> v[200009];
queue<int> q;

void bfs(int S, int t)
{
	for (int i = 1; i <= n; i++) 
		d[t][i] = 1000000000;
	d[t][S] = 0;
	while (!q.empty()) q.pop();
	q.push(S);
	while (!q.empty()) {
		int hn = q.front(); q.pop();
		for (int i = 0; i < v[hn].size(); i++) {
			int tn = v[hn][i];
			if (d[t][tn] > d[t][hn] + 1) {
				d[t][tn] = d[t][hn] + 1;
				q.push(tn);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, k; cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y); v[y].push_back(x);
	}
	bfs(1, 0); bfs(n, 1);
	for (int i = 1; i <= k; i++) {
		p[i].first = d[0][a[i]]; p[i].second = a[i];
	}
	sort(p + 1, p + k + 1);
	int mx = -1000000000, tmx = 0;
	for (int i = 1; i <= k; i++) {
		tmx = max(tmx, mx + d[1][p[i].second]);
		mx = max(mx, d[0][p[i].second]);
	}
	cout << min(tmx + 1, d[0][n]) << '\n';
	return 0;
}