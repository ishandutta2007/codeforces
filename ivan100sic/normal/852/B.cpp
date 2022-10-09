#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

const int MOD = 1'000'000'007;

int n, l, m;

/*
2 3 13
4 6
2 1
3 4
*/

mat mnozi(mat a, mat b) {
	mat c(m, vec(m, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				c[i][j] = (c[i][j] + 1ll * a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return c;
}

mat ident() {
	mat c(m, vec(m, 0));
	for (int i = 0; i < m; i++) {
		c[i][i] = 1;
	}
	return c;
}

mat digni(const mat& a, int k) {
	if (k == 0) {
		return ident();
	}
	if (k == 1) {
		return a;
	}
	auto b = digni(a, k / 2);
	b = mnozi(b, b);
	if (k % 2) {
		b = mnozi(b, a);
	}
	return b;
}

void stampaj(mat a) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", a[i][j]);
		}
		puts("");
	}
}

mat am, bm, cm;
vector<int> a, b, c, bc, ac;

int main() {
	scanf("%d%d%d", &n, &l, &m);
	a = b = c = vec(n, 0);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}

	bc = ac = vec(m, 0);

	for (int x : b) {
		bc[x]++;
	}

	for (int x : a) {
		ac[x]++;
	}

	am = bm = mat(m, vec(m, 0));

	// prvi sloj
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			am[i][j] = ac[(j + m - i) % m];
		}
	}

	// drugi sloj
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			bm[i][j] = bc[(j + m - i) % m];
		}
	}

	auto solm = mnozi(am, digni(bm, l - 2));

	// stampaj(solm);

	int sol = 0;
	for (int j = 0; j < n; j++) {
		int r = (2 * m - c[j] - b[j]) % m;
		sol = (sol + solm[0][r]) % MOD;
	}

	printf("%d\n", sol);

	{
		int _;
		scanf("%d", &_);
	}
}