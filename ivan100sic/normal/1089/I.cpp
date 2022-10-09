#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int q, p;

int t[405][405], r[405][405];
int f[405];

void popuni(int N) {
	f[0] = 1;
	for (int i=1; i<=N; i++)
		f[i] = f[i-1] * 1ll * i % p;
	for (int n=1; n<=N; n++) {
		for (int k=1; k<=N; k++) {
			if (k == 1)
				t[n][k] = f[n];
			else if (k == n)
				t[n][k] = 1;
			else {
				ll zbir = 0;
				for (int m=0; m<=n-k; m++)
					zbir += f[m+1] * 1ll * t[n-m-1][k-1] % p;
				t[n][k] = zbir % p;
			}
		}
	}
}

int pw(int x, int y) {
	if (!y)
		return 1;
	int z = pw(x, y >> 1);
	z = z * 1ll * z % p;
	if (y & 1)
		z = z * 1ll * x % p;
	return z;
}

int modinv(int x) {
	return pw(x, p-2);
}

void inverz(int N) {
	for (int i=1; i<=N; i++)
		r[i][i] = modinv(t[i][i]);
	for (int d=1; d<N; d++) {
		for (int j=1; j<=N-d; j++) {
			int i = j + d;
			ll ostalo = 0, simbol = 0;
			for (int k=1; k<=N; k++) {
				if (k == j) {
					simbol += t[j][j];
				} else {
					ostalo += r[i][k] * 1ll * t[k][j] % p;
				}
			}
			ostalo %= p;
			ostalo = (p - ostalo) % p;
			r[i][j] = ostalo * modinv(simbol) % p;
		}
	}
}

int g[405];

void resi(int N) {
	g[1] = 1;
	g[2] = 2;
	g[3] = 0;
	for (int i=4; i<=N; i++) {
		g[i] = (-(r[i][1] + (i % 2 ? -2 : 2)) % p + p) % p;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> q >> p;
	popuni(400);
	inverz(400);
	resi(400);

	while (q--) {
		int x;
		cin >> x;
		cout << g[x] << '\n';
	}
}