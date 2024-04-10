#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x;
int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int z = 0;

	if (a[x])
		z++;

	for (int i=1; i<=n; i++) {
		int c = 0, d = 0;
		if (x-i >= 1) {
			c++;
			d += a[x-i];
		}
		if (x+i <= n) {
			c++;
			d += a[x+i];
		}
		if (c == d)
			z += c;
	}
	cout << z << '\n';
}