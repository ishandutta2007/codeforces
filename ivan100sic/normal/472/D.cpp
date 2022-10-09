#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[2005][2005];
int n;
basic_string<tuple<int, int, int>> g;

void solve(int x, basic_string<int> s) {
	if (s.size() == 0)
		return;
	int lo = -1;
	for (int y : s)
		if (lo == -1 || a[x][y] < a[x][lo])
			lo = y;

	g += {x, lo, a[x][lo]};
	// podeli

	basic_string<int> van, unu;

	for (int y : s)
		if (y == lo)
			;
		else if (a[x][y] < a[lo][y])
			van += y;
		else
			unu += y;
	
	solve(x, van);
	solve(lo, unu);
}

void ans(string s = "NO") {
	cout << s << '\n';
	exit(0);
}

basic_string<pair<int, int>> e[2005];
ll b[2005][2005];

void bfs(int x, ll* d) {
	queue<int> q;
	q.push(x);
	fill(d, d+n, 123123123123123123ll);
	d[x] = 0;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (auto f : e[x]) {
			auto [y, w] = f;
			if (d[y] == 123123123123123123ll) {
				d[y] = d[x] + w;
				q.push(y);
			}
		}
	}
}

void proveri() {
	for (auto f : g) {
		auto [u, v, w] = f;
		e[u] += {v, w};
		e[v] += {u, w};
	}
	for (int i=0; i<n; i++)
		bfs(i, b[i]);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (b[i][j] != a[i][j])
				ans();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> a[i][j];

	for (int i=0; i<n; i++)
		if (a[i][i] != 0)
			ans();

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			if (a[i][j] != a[j][i])
				ans();
			if (i != j && a[i][j] == 0)
				ans();
		}

	basic_string<int> r(n-1, 0);
	iota(r.begin(), r.end(), 1);
	solve(0, r);
	proveri();
	ans("YES");
}