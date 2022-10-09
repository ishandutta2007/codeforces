#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[2005], b[2005], c[2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	sort(b, b+n);
	int sol = m;

	for (int i=0; i<n; i++) {
		int x = (b[i] - a[0] + m) % m;
		for (int j=0; j<n; j++)
			c[j] = (a[j] + x) % m;
		sort(c, c+n);
		if (equal(c, c+n, b))
			sol = min(sol, x);
	}
	cout << sol << '\n';
}