// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, r1, r2;
basic_string<int> e[50005];
int p[50005];

void dfs(int x, int par) {
	for (int y : e[x]) {
		if (y == par) continue;
		dfs(y, x);
		p[y] = x;
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> r1 >> r2;
	for (int i=1; i<=n; i++) {
		if (i != r1) {
			int x;
			cin >> x;
			e[x] += i;
			e[i] += x;
		}
	}

	dfs(r2, r2);
	for (int i=1; i<=n; i++) {
		if (i != r2) {
			cout << p[i] << ' ';
		}
	}
	cout << '\n';
}