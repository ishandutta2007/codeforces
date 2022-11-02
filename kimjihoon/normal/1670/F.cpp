#include <iostream>
#include <algorithm>
using namespace std;

const long long md = 1000000007;
const int M = 61;

int n;
long long z, cb[1009][1009], ac[1009], d[69][1009], rm[69];

long long ps(long long r)
{
	if (!r) return 0LL;
	d[M + 1][0] = 1; rm[M + 1] = r;
	long long ans = 0;
	for (int l = M; l >= 0; l--) {
		for (int i = 0; i <= n; i++)
			d[l][i] = 0;
		long long tl = (1LL << l);
		int t = 0, pt = 0;
		if (tl & z) t++;
		rm[l] = rm[l + 1];
		if (rm[l] >= tl) {
			rm[l] -= tl;
			pt++;
		}
		for (int i = t; i <= n; i += 2) {
			for (int j = (i - pt + 1) / 2; j <= n; j++) {
				int pi = 2 * j - i + pt;
				long long ss = (d[l + 1][j] * cb[n][i]) % md;
				if (pi > n) {
					if (l) ans = (ans + ss * ac[l - 1]) % md;
					else ans = (ans + ss) % md;
				}
				else
					d[l][pi] = (d[l][pi] + ss) % md;
			}
		}
	}
	for (int i = 0; i <= n; i++)
		ans = (ans + d[0][i]) % md;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	long long lp, r; cin >> lp >> r >> z;
	cb[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= i; j++) {
			cb[i][j] = cb[i - 1][j];
			if (j) cb[i][j] = (cb[i][j] + cb[i - 1][j - 1]) % md;
		}
	for (int l = 0; l <= M; l++) {
		int t = 0;
		if ((1LL << l) & z) t++;
		for (int i = t; i <= n; i += 2)
			ac[l] = (ac[l] + cb[n][i]) % md;
		if (l) ac[l] = (ac[l] * ac[l - 1]) % md;
	}
	cout << (ps(r) - ps(lp - 1) + md) % md << '\n';
	return 0;
}