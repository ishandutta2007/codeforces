#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[300005];
basic_string<int> v;
int deg[300005];
int d[300005][26];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s;
	s = string(" ") + s;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		deg[v]++;
	}

	queue<int> q;

	for (int i=1; i<=n; i++)
		if (deg[i] == 0)
			q.push(i);

	while (q.size()) {
		int x = q.front(); q.pop();
		v += x;
		for (int y : e[x]) {
			deg[y]--;
			if (deg[y] == 0)
				q.push(y);
		}
	}

	if (*max_element(deg+1, deg+n+1) != 0) {
		cout << "-1\n";
		return 0;
	}

	int sol = 0;

	for (int x : v) {
		int z = s[x] - 'a';
		d[x][z]++;
		sol = max(sol, d[x][z]);
		for (int z=0; z<26; z++)
			for (int y : e[x])
				d[y][z] = max(d[y][z], d[x][z]); 
	}
	cout << sol << '\n';

}