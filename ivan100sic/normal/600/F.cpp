#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

int a, b, c, n, m;
basic_string<int> e[2005];
int u[100005], v[100005], w[100005];
map<int, set<int>> has[2005];
int cn[1005];

void dfs(int x, int p, int q) {
	if (has[x][p].size()) {
		int i = *has[x][p].begin();
		has[x][p].erase(i);
		int y = u[i] ^ v[i] ^ x;
		dfs(y, q, p);

		has[u[i]][w[i]].erase(i);
		has[v[i]][w[i]].erase(i);
		w[i] = q;
		has[u[i]][w[i]].insert(i);
		has[v[i]][w[i]].insert(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b >> m;
	n = a + b;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--, v += a;
		::u[i] = u;
		::v[i] = v;
		e[u] += i;
		e[v] += i;
	}

	for (int i=0; i<n; i++)
		c = max(c, (int)e[i].size());

	uniform_int_distribution<int> uid(0, c-1);
	for (int i=0; i<m; i++) {
		w[i] = uid(eng);
		has[u[i]][w[i]].insert(i);
		has[v[i]][w[i]].insert(i);
	}

	for (int x=0; x<n; x++) {
		while (1) {
			memset(cn, 0, sizeof cn);
			for (int j : e[x])
				cn[w[j]]++;
			int c2 = -1, c0 = -1;
			for (int j=0; j<c; j++)
				if (cn[j] >= 2)
					c2 = j;
				else if (cn[j] == 0)
					c0 = j;
			if (c2 == -1)
				break;
			dfs(x, c2, c0);
		}
	}

	cout << c << '\n';
	for (int i=0; i<m; i++)
		cout << w[i]+1 << " \n"[i == m-1];
}