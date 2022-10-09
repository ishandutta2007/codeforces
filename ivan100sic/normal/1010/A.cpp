#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int n, m;
int a[1005], b[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	for (int i=0; i<n; i++) {
		if (a[i] == 1 || b[i] == 1) {
			cout << "-1\n";
			return 0;
		}
	}

	ld sol = m;

	for (int i=0; i<n; i++) {
		sol *= (ld)a[i] / (a[i] - 1);
		sol *= (ld)b[i] / (b[i] - 1);
	}

	cout.precision(20);
	cout << fixed << sol - m << '\n';
}