// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, g;
basic_string<int> e[100005];
int d[100005], p[100005];
bool v[100005], t[100005];

void dfs(int x) {
	v[x] = true;
	bool taken = false;
	for (int y : e[x]) {
		if (!v[y]) {
			p[y] = x;
			d[y] = d[x] + 1;
			dfs(y);
		} else {
			if (d[x] - d[y] + 1 >= g) {
				cout << "2\n";
				cout << d[x] - d[y] + 1 << '\n';
				for (int i=x; i!=y; i=p[i])
					cout << i << ' ';
				cout << y << '\n';
				exit(0);
			}
		}
		taken |= t[y];
	}
	if (!taken)
		t[x] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	g = ceil(sqrt(ld(n)) - 1e-7);
	dfs(1);

	cout << "1\n";
	for (int i=1, r=g; i<=n && r>0; i++) {
		if (t[i]) {
			cout << i << ' ';
			r--;
		}
	}
	cout << '\n';
}

// I will still practice daily...