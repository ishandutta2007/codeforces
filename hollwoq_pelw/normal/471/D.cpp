#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, res, p[N], a[N], b[N];

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	cin >> n >> m;

	if (m == 1)
		return cout << n, 0;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	for (int i = n - 1; i; i--)
		a[i] -= a[i - 1];
	for (int i = m - 1; i; i--)
		b[i] -= b[i - 1];

	-- n, -- m;

	for (int i = 2; i <= m; i++) {
		int j = p[i - 1];
		while (j && b[j + 1] != b[i])
			j = p[j];
		p[i] = j + (b[j + 1] == b[i]);
	}

	for (int i = 1, j = 0; i <= n; i++) {
		while (j && (j >= m || b[j + 1] != a[i]))
			j = p[j];
		j += b[j + 1] == a[i];
		if (j >= m)
			res ++;
	}

	cout << res;
}