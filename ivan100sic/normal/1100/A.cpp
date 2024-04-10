#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];

	int y = -123123;

	for (int b=0; b<k; b++) {
		int z = accumulate(a, a+n, 0);
		for (int i=0; i<n; i++)
			if (i % k == b)
				z -= a[i];
		z = abs(z);
		y = max(y, z);
	}

	cout << y << '\n';
}