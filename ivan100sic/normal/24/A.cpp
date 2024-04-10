#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int amt = 1123123123;
int n;
basic_string<pair<int, int>> e[105];

void dfs(int x, int p, int d, int z) {
	if (d == n) {
		amt = min(amt, z);
		return;
	}
	for (auto [y, w] : e[x]) {
		if (y != p) {
			dfs(y, x, d+1, z+w);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		e[x] += {y, 0};
		e[y] += {x, w};
	}
	dfs(1, 1, 0, 0);
	cout << amt << '\n';
}