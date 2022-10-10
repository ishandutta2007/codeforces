#include <bits/stdc++.h>
using namespace std;

int n, m, t, s;
int low[5005], idx[5005];
bool instack[5005];
vector<int> sccstack;
vector<int> e[5005];

struct grana {
	int u, v;
};

vector<grana> grane;

int brkom;
int vrsta[5005];
int neki[5005], us[5005];

bool v[5005];
void dfs(int x) {
	v[x] = 1;
	for (int y : e[x]) {
		if (!v[y])
			dfs(y);
	}
}

void scc(int x) {
	instack[x] = true;
	sccstack.push_back(x);
	low[x] = idx[x] = t++;
	for (int y : e[x]) {
		if (instack[y]) {
			low[x] = min(low[x], idx[y]);
		} else if (idx[y] == -1) {
			scc(y);
			low[x] = min(low[x], low[y]);
		}
	}
	if (low[x] == idx[x]) {
		vector<int> komp;
		while (1) {
			int z = sccstack.back();
			komp.push_back(z);
			sccstack.pop_back();
			instack[z] = false;
			if (z == x)
				break;
		}
		// uradi nesto
		brkom++;
		for (int c : komp)
			vrsta[c] = brkom;

		neki[brkom] = komp.back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		grane.push_back({u, v});
		e[u].push_back(v);
	}

	dfs(s);
	fill(idx+1, idx+n+1, -1);
	fill(low+1, low+n+1, -1);
	for (int i=1; i<=n; i++)
		if (idx[i] == -1)
			scc(i);

	// ulazni stepeni
	for (grana g : grane) {
		if (vrsta[g.u] != vrsta[g.v])
			us[vrsta[g.v]]++;
	}

	int sol = 0;

	for (int i=1; i<=brkom; i++) {
		int c = neki[i];
		if (!v[c] && us[i] == 0)
			sol++;
	}

	cout << sol << '\n';


}