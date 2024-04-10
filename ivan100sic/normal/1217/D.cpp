#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int deg[5005];
int n, m;
int u[5005], v[5005];
basic_string<int> e[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> u[i] >> v[i];
		e[u[i]] += v[i];
		deg[v[i]]++;
	}

	vector<int> q;
	for (int i=1; i<=n; i++)
		if (deg[i] == 0)
			q.push_back(i);
	size_t qs = 0;
	while (qs != q.size()) {
		int x = q[qs++];
		for (int y : e[x])
			if (!--deg[y])
				q.push_back(y);
	}
	if ((int)qs == n) {
		// moze 1
		cout << "1\n";
		for (int i=1; i<=m; i++)
			cout << 1 << " \n"[i == m];
	} else {
		cout << "2\n";
		for (int i=1; i<=m; i++)
			cout << (1 + (u[i] < v[i])) << " \n"[i == m];
	}

}