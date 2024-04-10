#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
vector<int> e[100005];
int d[100005];

map<int, int> unutar;
vector<int> dole;

void dfs(int x) {
	for (int y : e[x]) {
		d[y] = d[x] + 1;
		dfs(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		e[x].push_back(i);
	}

	dfs(1);
	int md = *max_element(d+1, d+n+1);

	for (int i=1; i<=n; i++) {
		if (d[i] % 2 != md % 2) {
			unutar[a[i]]++;
		} else {
			dole.push_back(a[i]);
		}
	}

	int xr = 0;
	for (int x : dole) {
		xr ^= x;
		// cerr << "dole: " << x << '\n';
	}

	long long sol = 0;

	if (xr == 0) {
		sol = dole.size() * (dole.size() - 1ll) / 2;
		sol += (n - dole.size()) * (n - dole.size() - 1ll) / 2;
		for (int x : dole) {
			sol += unutar[x];
		}
	} else {
		for (int x : dole) {
			sol += unutar[x ^ xr];
		}
	}

	cout << sol;
}