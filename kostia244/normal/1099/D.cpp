#include <bits/stdc++.h>
using namespace std;

long long n, t, total;
vector<vector<long long>> g;
vector<long long> s;

void dfs(long long v = 1, long long p = -1) {
	long long c = 0, minchild = 1000000000000000ll;
	for (auto& u : g[v]) {
		if (u != p) {
			dfs(u, v);
			if (s[u] < minchild) {
				minchild = s[u];
			}
			c++;
		}
	}
	if (c == 0 && s[v] == -1)
		s[v] = s[p];
	if (c > 0 && s[v] == -1) {
		if (minchild < s[p])
			total = -1000000000000000ll;
		s[v] = minchild;
	}
	for (auto& u : g[v]) {
		if (u != p) {
			total += s[u] - s[v];
		}
	}
}

int main() {
	cin >> n;
	g.resize(n + 1);
	s.resize(n + 1);
	for (long long i = 2; i <= n; i++) {
		cin >> t;
		g[i].push_back(t);
		g[t].push_back(i);
	}
	for (long long i = 1; i <= n; i++)
		cin >> s[i];
	total = s[1];
	dfs();

	cout << max(-1ll, total);

	return 0;
}