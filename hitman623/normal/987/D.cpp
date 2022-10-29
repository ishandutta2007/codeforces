#include <bits/stdc++.h>
using namespace std;

int n, m, k, s;
vector<int> e[100005];
vector<int> gudz[105];

int d[105][100005];

void bfs(vector<int> v0, int* d) {
	queue<int> q;
	fill(d+1, d+n+1, -1);
	for (int x : v0) {
		q.push(x);
		d[x] = 0;
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k >> s;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		gudz[x].push_back(i);
	}
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i=1; i<=k; i++)
		bfs(gudz[i], d[i]);

	for (int i=1; i<=n; i++) {
		vector<int> v;
		for (int j=1; j<=k; j++)
			v.push_back(d[j][i]);
		sort(v.begin(), v.end());
		cout << accumulate(v.begin(), v.begin() + s, 0) << ' ';
	}

}