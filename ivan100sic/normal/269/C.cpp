#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct grana {
	int v, f, dir, id;
};

int n, m;
basic_string<grana> e[200005];
int ans[200005];
int unknown[200005], excess[200005];
bool inq[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, f;
		cin >> u >> v >> f;
		e[u] += grana{v, f, 0, i};
		e[v] += grana{u, f, 1, i};
		unknown[u] += f;
		unknown[v] += f;
		ans[i] = -1;
	}

	queue<int> q;

	for (auto [v, f, dir, id] : e[1]) {
		ans[id] = dir;
		unknown[v] -= f;
		excess[v] += f;
		if (unknown[v] == abs(excess[v]) && !inq[v]) {
			q.push(v);
			inq[v] = 1;
		}
	}

	for (auto [v, f, dir, id] : e[n]) {
		ans[id] = dir ^ 1;
		unknown[v] -= f;
		excess[v] -= f;
		if (unknown[v] == abs(excess[v]) && !inq[v]) {
			q.push(v);
			inq[v] = 1;
		}
	}

	while (q.size()) {
		int u = q.front(); q.pop();
		if (unknown[u] == 0)
			continue;
		if (unknown[u] == excess[u]) {
			for (auto [v, f, dir, id] : e[u]) {
				if (ans[id] != -1)
					continue;
				ans[id] = dir;
				unknown[v] -= f;
				excess[v] += f;
				if (unknown[v] == abs(excess[v]) && !inq[v]) {
					q.push(v);
					inq[v] = 1;
				}			
			}
		} else {
			for (auto [v, f, dir, id] : e[u]) {
				if (ans[id] != -1)
					continue;
				ans[id] = dir ^ 1;
				unknown[v] -= f;
				excess[v] -= f;
				if (unknown[v] == abs(excess[v]) && !inq[v]) {
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}

	for (int i=0; i<m; i++)
		cout << ans[i] << '\n';
}