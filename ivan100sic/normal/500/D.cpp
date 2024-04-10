#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int u[100005], v[100005], l[100005], sz[100005];
ld worth[100005], tw;
basic_string<int> e[100005];

void dfs(int x, int eid) {
	sz[x] = 1;
	for (int i : e[x]) {
		if (i == eid)
			continue;
		int y = u[i] ^ v[i] ^ x;
		dfs(y, i);
		sz[x] += sz[y];
	}
	worth[eid] += (ld)sz[x] * (n - sz[x]) * (n - sz[x] - 1);
	worth[eid] += (ld)(n - sz[x]) * sz[x] * (sz[x] - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		cin >> u[i] >> v[i] >> l[i];
		e[u[i]] += i;
		e[v[i]] += i;
	}

	dfs(1, 0);
	for (int i=1; i<n; i++) {
		tw += worth[i] * l[i];
	}

	ld c = (ld)6 / n / (n-1) / (n-2);
	cout << setprecision(20) << fixed;

	int q;
	cin >> q;
	while (q--) {
		int i, w;
		cin >> i >> w;
		tw -= (worth[i] * (l[i] - w));
		l[i] = w;
		cout << tw*c << '\n';
	}	
}