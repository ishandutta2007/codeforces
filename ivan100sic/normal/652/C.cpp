// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
int a[300005], inv[300005], e[300005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i], inv[a[i]] = i;

	while (m--) {
		int x, y;
		cin >> x >> y;
		x = inv[x], y = inv[y];
		if (x > y)
			swap(x, y);
		e[y] = max(e[y], x);
	}

	ll sol = 0;
	for (int i=1; i<=n; i++)
		e[i] = max(e[i], e[i-1]), sol += i - e[i];
	cout << sol << '\n';
}