#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int t;
int c[2000005];
int d[2000005];

void probaj(int n, int m, int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m)
		return;
	fill(d, d+n+m+1, 0);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			int z = abs(x-i) + abs(y-j);
			d[z]++;
		}
	for (int i=0; i<n+m+1; i++)
		if (d[i] != c[i])
			return;
	printf("%d %d\n%d %d\n", n, m, x, y);
	exit(0);
}

void nema() {
	printf("-1\n");
	exit(0);
}

int main() {
	scanf("%d", &t);
	for (int i=0; i<t; i++) {
		int x;
		scanf("%d", &x);
		c[x]++;
	}

	int naj = -1;
	for (int i=0; i<t; i++)
		if (c[i] > 0)
			naj = i;

	if (naj == -1)
		nema();

	if (c[0] != 1)
		nema();

	// for (int i=0; i<=naj; i++)
	// 	cerr << i << ' ' << c[i] << '\n';

	{
		int z = -1;
		for (int i=1; i<=t; i++) {
			if (c[i] != 4*i) {
				z = i-1;
				break;
			}
		}
		if (z == -1)
			nema();

		cerr << "zid: " << z << '\n';

		for (int n=1; n<=t; n++) {
			if (t % n)
				continue;
			int m = t / n;

			if (2*z + 1 > n)
				continue;
			if (2*z + 1 > m)
				continue;

			// i+j == naj+2
			for (int i=1; i<=n; i++) {
				int j = naj+2-i;
				if (min({i-1, n-i, j-1, m-j}) == z)
					probaj(n, m, i, j);
			}
		}
	}

	nema();
}