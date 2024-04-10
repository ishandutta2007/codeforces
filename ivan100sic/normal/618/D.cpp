#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x, y;
basic_string<int> e[200005];

int d[200005][3];

void dfs(int x, int p) {
	vector<int> pad;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);

		int vy = *max_element(d[y]+0, d[y]+3);
		d[x][0] += vy;

		pad.push_back(vy - max(d[y][0], d[y][1]));
	}

	sort(pad.begin(), pad.end());

	if (pad.size() >= 1)
		d[x][1] = d[x][0] - pad[0] + 1;
	else
		d[x][1] = -1e9;

	if (pad.size() >= 2)
		d[x][2] = d[x][0] - pad[0] - pad[1] + 2;
	else
		d[x][2] = -1e9;
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
		e[u] += v;
		e[v] += u;
	}

	if (x >= y) {
		// mozes uvek da izbegnes sve grane osim ako je zvezda
		// onda mozes sve osim jedne
		bool zvezda = false;
		for (int i=1; i<=n; i++)
			if ((int)e[i].size() == n-1)
				zvezda = true;
		if (zvezda)
			cout << (n-2ll)*y + x << '\n';
		else
			cout << (n-1ll)*y << '\n';
		return 0;
	}

	dfs(1, 1);
	ll s = *max_element(d[1]+0, d[1]+3);
	cout << x*s + y*(n-1-s) << '\n';
}