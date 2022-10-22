#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void solve(int a, int b, int c, int& x, int &y, int &z) {
	if (a == b) {
		x = c; y = -2 * c;
		z = a;
		return;
	}
	if (a + b == 0) {
		x = c; y = 2 * c;
		z = a;
		return;
	}
	if (b + c == 0 || b == c || c + a == 0 || c == a) {
		solve(b, c, a, y, z, x);
		return;
	}
	x = b + c;
	y = -(a + c);
	z = b - a;
}

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> r(n);
		if (n % 2 == 0) {
			for (int i = 0; i < n; i += 2) {
				r[i + 1] = -a[i];
				r[i] = a[i + 1];
			}
		} else {
			solve(a[0], a[1], a[2], r[0], r[1], r[2]);
			for (int i = 3; i < n; i += 2) {
				r[i + 1] = -a[i];
				r[i] = a[i + 1];
			}
		}
		long long s = 0;
		for (int i = 0; i < n; ++i) {
			assert(r[i]);
			s += (long long)a[i] * r[i];
		}
		assert(s == 0);
		for (int i = 0; i < n; ++i) {
			printf("%d ", r[i]);
		}
		printf("\n");
	}
	return 0;
}