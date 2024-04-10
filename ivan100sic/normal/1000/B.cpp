#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100005];
int p[100005], q[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	a[0] = 0;
	a[n+1] = m;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int sol = 0;
	for (int i=1; i<=n; i++) {
		if (i % 2 == 1)
			sol += a[i] - a[i-1];
	}

	if (n % 2 == 0) {
		sol += m - a[n];
		p[n] = m - a[n];
	} else {
		q[n] = m - a[n];
	}

	for (int i=n-1; i>=0; i--) {
		if (i % 2 == 0) {
			p[i] = p[i+1] + (a[i+1] - a[i]);
			q[i] = q[i+1];
		} else {
			p[i] = p[i+1];
			q[i] = q[i+1] + (a[i+1] - a[i]);
		}
	}

	int run = 0;
	for (int i=0; i<=n+1; i++) {
		if (i % 2 == 1)
			run += a[i] - a[i-1];

		if (i > 0 && a[i]-1 != a[i-1]) {
			int tmp = run;
			if (i % 2 == 1)
				tmp -= 1;
			sol = max(sol, tmp + q[i]);
		}

		if (i <= n && a[i]+1 != a[i+1]) {
			int tmp = run;
			tmp += q[i];
			if (i % 2 == 1)
				tmp -= 1;
			sol = max(sol, tmp);
		}
	}

	cout << sol << '\n';
}