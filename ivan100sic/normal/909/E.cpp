#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int c[100005];
basic_string<int> e[100005], f[100005];
int deg[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> c[i];
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		f[v] += u;
		deg[u]++;
	}

	queue<int> q0, q1;
	for (int i=0; i<n; i++) {
		if (deg[i] == 0) {
			(c[i] ? q1 : q0).push(i);
		}
	}

	auto pop = [&](int x) {
		for (int y : f[x]) {
			if (!--deg[y]) {
				(c[y] ? q1 : q0).push(y);
			}
		}
	};

	int sol = 0;
	while (1) {
		// skidaj nule dok ima nule
		while (q0.size()) {
			int x = q0.front(); q0.pop();
			pop(x);
		}

		if (q1.size()) {
			sol++;
			while (q1.size()) {
				int x = q1.front(); q1.pop();
				pop(x);
			}
		} else {
			break;
		}
	}

	cout << sol << '\n';
}