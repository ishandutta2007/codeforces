#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> c;
vector< vector<int> > g;
vector<bool> used;
vector<int> ok;
vector<int> up;

void dfs(int v) {
	used[v] = 1;
	ok[v] = c[v];
	for (int i : g[v]) {
		if (!used[i]) {
			dfs(i);
			if (ok[i] != ok[v])
				ok[v] = -1;
		}
	}
	return;
}

void getup(int v){
	used[v] = 1;
	int clr = c[v];
	int cnt = 0;
	if (v) {
		if (clr != up[v])
			clr = -1;
		cnt++;
	}
	int numb = -1;
	for (int i : g[v]) {
		if (!used[i])
			if (clr != ok[i]) {
				numb = i;
			}
			else
				cnt++;
	}
	if (cnt == g[v].size()) {
		for (int i : g[v]) {
			if (!used[i])
				up[i] = clr;
		}
	}
	if (cnt == int(g[v].size()) - 1)
		up[numb] = clr;
	for (int i : g[v]) {
		if (!used[i])
			getup(i);
	}
	return;
}

int fin(int v) {
	used[v] = 1;
	bool is = 1;
	for (int i : g[v]) {
		if (!used[i])
			is &= (ok[i] != -1);
	}
	if (v)
		is &= (up[v] != -1);
	if (is)
		return v;
	int res = -1;
	for (int i : g[v]) {
		if (!used[i])
			res = max(res, fin(i));
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	c.resize(n);
	g.resize(n);
	up.resize(n, -1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++)
		cin >> c[i];
	used.resize(n);
	ok.resize(n);
	dfs(0);
	used.assign(n, 0);
	getup(0);
	used.assign(n, 0);
	int ans = fin(0);
	if (ans != -1)
		cout << "YES\n" << ans + 1;
	else
		cout << "NO";
	return 0;
}