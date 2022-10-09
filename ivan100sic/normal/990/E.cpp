#include <bits/stdc++.h>
using namespace std;

bool s[1000005];
int l[1000005];
int n, m, k;
int a[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// ja sam

	cin >> n >> m >> k;

	fill(s, s+n, true);

	for (int i=0; i<m; i++) {
		int x;
		cin >> x;
		s[x] = false;
	}

	for (int i=0; i<n; i++) {
		if (s[i])
			l[i] = i;
		else
			l[i] = l[i-1];
	}


	for (int i=1; i<=k; i++)
		cin >> a[i];

	if (!s[0])
		return cout << -1, 0;

	long long sol = 123123123123123123ll;

	for (int i=1; i<=k; i++) {

		int c = 1;
		int x = 0;

		while (x+i < n) {
			int y = l[x+i];
			if (y == x) {
				c = -1;
				break;
			}
			x = y;
			c++;
		}

		if (c != -1)
			sol = min(sol, c*1ll*a[i]);
	}

	if (sol == 123123123123123123ll)
		sol = -1;

	cout << sol << '\n';
}