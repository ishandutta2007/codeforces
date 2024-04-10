#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int pw(int x, int y, int m) {
	if (y == 0)
		return 1 % m;
	if (y == 1)
		return x % m;

	int z = pw(x, y >> 1, m);
	z = z * 1ll * z % m;
	if (y & 1)
		z = z * 1ll * x % m;
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int z = pw(3, n, m);
	z = (z + m - 1) % m;
	cout << z << '\n';
}