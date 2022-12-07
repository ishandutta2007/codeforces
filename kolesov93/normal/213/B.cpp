#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int N = 111;
const int M = 333;
ll f[11][N][2];
ll c[M][M];

ll getF(int n, int m) {
	if (m == 0) return n == 0 ? 1 : 0;
	return c[n + m - 1][m - 1];
}

int main() {
	//freopen("in", "r", stdin);

	c[0][0] = 1;
	for (int i = 1; i < M; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		}
	}
	
	int n;
	vector<int> a(10);	
	
	cin >> n;
	for (int i = 0; i < 10; ++i) {
		cin >> a[i];
	}

	f[0][0][0] = 1;
	for (int i = a[0]; i <= n; ++i)
		f[1][i][0] = 1;

	for (int d = 1; d < 10; ++d)
		for (int l = 0; l <= n; ++l)
			for (int w = 0; w < 2; ++w) {
				//if (f[d][l][w]) cout << d << " " << l << " " << w << ": " << f[d][l][w] << endl;
				for (int al = a[d]; l + al <= n; ++al) {
						if (w == 1) {
							f[d + 1][l + al][w] = (f[d + 1][l + al][w] + f[d][l][w] * getF(al, l + 1)) % MOD;
						} else {
							f[d + 1][l + al][0] = (f[d + 1][l + al][0] + f[d][l][w] * getF(al, l)) % MOD;
							if (al) f[d + 1][l + al][1] = (f[d + 1][l + al][1] + f[d][l][w] * getF(al - 1, l + 1));
						}
				}
			}

	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans = (ans + f[10][i][1]) % MOD;
	}
	cout << ans << endl;

	return 0;
}