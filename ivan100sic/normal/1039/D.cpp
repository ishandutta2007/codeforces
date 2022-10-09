#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005], n, k, cnt;
vector<int> e[100005];

int dfs(int x, int p) {
	int a = 0, b = 0;
	for (int y : e[x])
		if (y != p) {
			int z = dfs(y, x);
			if (z > a) {
				b = a;
				a = z;
			} else if (z > b) {
				b = z;
			}
		}

	if (a + b >= k - 1) {
		cnt++;
		return 0;
	}

	return a + 1;
}

int f(int x) {
	cnt = 0;
	k = x;
	dfs(1, 1);
	return cnt;
}

void odredi(int l, int r) {
	if (r-l <= 1)
		return;

	int x = (l+r) / 2;
	a[x] = f(x);

	if (a[x] == a[l]) {
		fill(a+l, a+x, a[x]);
	} else {
		odredi(l, x);
	}

	if (a[x] == a[r]) {
		fill(a+x, a+r, a[x]);
	} else {
		odredi(x, r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	a[1] = f(1);
	a[n] = f(n);
	odredi(1, n);

	for (int i=1; i<=n; i++)
		cout << a[i] << '\n';

}