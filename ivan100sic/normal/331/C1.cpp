#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int d[1000005];

int ms(int x) {
	int z = 0;
	while (x > 0) {
		z |= 1 << (x % 10);
		x /= 10;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int m = ms(i);
		d[i] = 123123123;
		for (int j=1; j<10; j++) {
			if (m & (1 << j))
				d[i] = min(d[i], d[i-j] + 1);
		}
	}
	cout << d[n] << '\n';
}