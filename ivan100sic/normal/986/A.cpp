#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// this isn't number theory!
int n, m, k, s;
basic_string<int> e[100005];
int d[105][100005];
basic_string<int> a[105];

void bfs(basic_string<int> a0, int* d) {
	queue<int> q;
	fill(d+1, d+n+1, 123123123);
	for (int x : a0) {
		d[x] = 0;
		q.push(x);
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (d[y] == 123123123) {
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
		a[x] += i;
	}

	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=k; i++) {
		bfs(a[i], d[i]);
	}

	for (int i=1; i<=n; i++) {
		basic_string<int> g;
		for (int j=1; j<=k; j++)
			g += d[j][i];
		sort(g.begin(), g.end());
		cout << accumulate(g.begin(), g.begin() + s, 0) << ' ';
	}
	cout << '\n';
}