#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> solpre[5] = {
	{},
	{1},
	{1, 2},
	{1, 2, 3},
	{1, 3, 2, 4},
};

void psol(basic_string<int> a) {
	cout << "YES\n";
	for (int x : a)
		cout << x << '\n';
	exit(0);
}

bool gen(int x, int n) {
	vector<int> cnt(n, 0);
	int y = 1;
	for (int i=1; i<n; i++) {
		if (cnt[y]++)
			return false;
		y = y * 1ll * x % n;
	}
	return true;
}

int pw(int x, int y, int n) {
	if (y == 1)
		return x;
	if (y == 0)
		return 1;
	int z = pw(x, y >> 1, n);
	z = z * 1ll * z % n;
	if (y & 1)
		z = z * 1ll * x % n;
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	if (n <= 4)
		psol(solpre[n]);
	
	for (int x=2; x*x<=n; x++)
		if (n%x == 0) {
			cout << "NO\n";
			return 0;
		}

	int g = 0;
	for (int x=2;; x++)
		if (gen(x, n)) {
			g = x;
			break;
		}

	basic_string<int> a;
	for (int i=0; i<n-1; i++) {
		int x = i;
		if (i % 2)
			x = n-1-x;
		a += pw(g, x, n);
	}
	a += n;

	psol(a);
}