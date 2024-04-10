#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int v[1005][1005];

void solve(int x) {
	for (int i=x; i<n; i++) {
		v[i][i+1] = 1;
		v[i+1][i] = 1;
	}
}

void flip() {
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (i != j)
				v[i][j] ^= 1;
}

void print() {
	cout << "YES\n";
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++)
			cout << v[i][j];
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// ja sam

	cin >> n >> a >> b;

	if (a > 1 && b > 1)
		return cout << "NO\n", 0;

	if (a == 1 && b == 1) {
		if (n == 1)
			return cout << "YES\n0\n", 0;
			
		if (n <= 3)
			return cout << "NO\n", 0;

		for (int i=1; i<n; i++) {
			v[i][i+1] = 1;
			v[i+1][i] = 1;
		}
		print();

		return 0;
	}

	if (a == 1) {
		solve(b);
		flip();
	} else {
		solve(a);
	}

	print();
}