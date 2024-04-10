#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, a[105];

int c(int x) {
	int z = 0;
	for (int i=1; i<=n; i++) {
		int d = 2 * a[i] * (i - 2 + x + abs(i - x));
		z += d;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	int y = 1123123123;
	for (int x=0; x<=n; x++)
		y = min(y, c(x));
	cout << y << '\n';
}