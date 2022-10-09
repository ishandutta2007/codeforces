#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> e[400005];
bool v[400005];
int n, m, q, c;

void dfs(int x) {
	v[x] = 1;
	for (int y : e[x])
		if (!v[y])
			dfs(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=1; i<=q; i++) {
		int x, y;
		cin >> x >> y;
		y += n;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	for (int i=1; i<=n+m; i++)
		if (!v[i]) {
			dfs(i);
			c++;
		}
	cout << c-1 << '\n';
}