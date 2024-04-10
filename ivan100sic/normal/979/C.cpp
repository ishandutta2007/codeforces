#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x, y;
vector<int> e[300005];

int p[300005];
bool mark[300005];
int vis;

void bfs1(int x0, int y0) {
	queue<int> q;
	q.push(x0);
	fill(p+1, p+n+1, -1);
	p[x0] = x0;
	vis = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (p[y] == -1) {
				p[y] = x;
				q.push(y);
				vis++;
			}
		}
	}

	int t = y0;
	while (t != x0) {
		t = p[t];
		mark[t] = 1;
	}
	mark[y0] = 1;
}

void bfs2(int x0) {
	queue<int> q;
	q.push(x0);
	fill(p+1, p+n+1, -1);
	p[x0] = x0;
	vis = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (p[y] == -1 && !mark[y]) {
				p[y] = x;
				q.push(y);
				vis++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x >> y;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	bfs1(x, y);

	bfs2(x);
	int a = vis;
	bfs2(y);
	int b = vis;

	cerr << a << ' ' << b << '\n';

	cout << n*1ll*(n-1) - a*1ll*b << '\n';
}