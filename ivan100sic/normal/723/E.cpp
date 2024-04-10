#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int u[40005], v[40005], d[40005], balance[205];
bool skip[40005];
set<int> e[205];

void rmedge(int i) {
	e[u[i]].erase(i);
	e[v[i]].erase(i);
}

void roam(int x) {
	while (1) {
		if (e[x].size() == 0)
			return;
		int i = *e[x].begin();
		bool dir = u[i] == x;
		rmedge(i);
		int y = dir ? v[i] : u[i];
		d[i] = dir;
		x = y;
	}
}

bool vis[205];

void dfs(int x, basic_string<int>& w) {
	vis[x] = 1;
	w += x;
	for (int y : e[x]) {
		if (!vis[y]) {
			dfs(y, w);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int tcc;
	cin >> tcc;
	while (tcc--) {
		cin >> n >> m;
		for (int i=0; i<205; i++) {
			e[i] = {};
			balance[i] = 0;
		}
		for (int i=0; i<m; i++) {
			cin >> u[i] >> v[i];
			e[u[i]].insert(i);
			e[v[i]].insert(i);
			skip[i] = false;
		}

		basic_string<int> odd;
		for (int i=1; i<=n; i++)
			if (e[i].size() % 2)
				odd += i;

		// dodaj extra grane
		for (int i=0; i<(int)odd.size(); i+=2) {
			int x = odd[i];
			int y = odd[i+1];
			u[m] = x;
			v[m] = y;
			e[x].insert(m);
			e[y].insert(m);
			skip[m] = true;
			m++;
		}

		for (int i=1; i<=n; i++) {
			int x = i;
			int y = i == n ? 1 : i+1;
			u[m] = x;
			v[m] = y;
			e[x].insert(m);
			e[y].insert(m);
			skip[m] = true;
			m++;
		}
		
		roam(1);

		for (int i=0; i<m; i++) {
			if (skip[i])
				continue;
			if (d[i])
				swap(u[i], v[i]);
			balance[u[i]]++;
			balance[v[i]]--;
		}

		cout << count(balance+1, balance+n+1, 0) << '\n';
		for (int i=0; i<m; i++)
			if (!skip[i])
				cout << u[i] << ' ' << v[i] << '\n';
	}

}