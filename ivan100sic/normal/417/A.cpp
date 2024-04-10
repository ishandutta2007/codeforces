#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int c, d, n, m, k, z = 1123123123;
	cin >> c >> d >> n >> m >> k;
	for (int i=0; i<=10000; i++) {
		for (int j=0; j<=10000; j++) {
			int p = i*c + j*d;
			if (i*n + j + k >= n*m) {
				z = min(z, p);
			}
		}
	}
	cout << z << '\n';
}