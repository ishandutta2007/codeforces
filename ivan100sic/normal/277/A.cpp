#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[1005];
int v[1005];

void dfs(int x) {
	v[x] = 1;
	for (int y : e[x]) {
		if (!v[y]) {
			dfs(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	int zbir = 0;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		zbir += x;
		while (x--) {
			int y;
			cin >> y;
			y += 505;
			e[i] += y;
			e[y] += i;
		}
	}
	int cc = 0;
	for (int i=1; i<=n; i++)
		if (!v[i]) {
			dfs(i);
			cc++;
		}

	if (zbir == 0) {
		cout << cc << '\n';
	} else {
		cout << cc-1 << '\n';
	}
}