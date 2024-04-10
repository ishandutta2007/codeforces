#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

static const int M = 1000000007;
static int a, b;
static int dp[2][200005];

static inline int nadji(int x) {
	int z = 0;
	for (int y=1; y<=1000; y++)
		if (y*(y+1) / 2 <= x)
			z = y;
	return z;
}

static inline int ad(int& x, int y) {
	x += y;
	if (x >= M)
		x -= M;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b;
	dp[0][0] = 1;
	int c = nadji(a+b);
	int ol_h = 1;
	int ol2_h = 0;
	for (int i=1; i<=c; i++) {
		auto nu = dp[i%2];
		auto ol = dp[1-i%2];
		memset(nu, 0, (ol2_h + 1) * sizeof(int));
		int w = i*(i+1) / 2, nu_h = 0;
		for (int j=max(0, w-b); j<=min(a, i+ol_h); j++) {
			if (ad(nu[j], ol[j]))
				nu_h = j;
			if (j >= i)
				if (ad(nu[j], ol[j-i]))
					nu_h = j;
		}

		// for (int j=0; j<=nu_h; j++)
		// 	cerr << nu[j] << ' ';
		// cerr << '\n';

		ol2_h = ol_h;
		ol_h = nu_h;
	}
	int z = 0;
	for (int j=0; j<=ol_h; j++)
		ad(z, dp[c%2][j]);
	cout << z << '\n';
}