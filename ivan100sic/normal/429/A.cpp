#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005], sol;
basic_string<int> e[100005], s;
int n;

void dfs(int x, int p, int u, int v) {
	a[x] ^= u;
	if (a[x]) {
		a[x] ^= 1;
		u ^= 1;
		sol++;
		s += x;
	}
	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x, v, u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[i] ^= x;
	}

	dfs(1, 1, 0, 0);
	cout << sol << '\n';
	for (int x : s)
		cout << x << '\n';
}