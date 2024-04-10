#include <iostream>
#include <algorithm>
using namespace std;

const long long md = 998244353;
const int M = 100009;

long long ft[100009], rt[100009];
long long a[100009], sl[100009], sr[100009];

long long fp(long long n, long long k)
{
	long long s = 1;
	while (k) {
		if (k & 1) s = (s * n) % md;
		n = (n * n) % md; k /= 2;
	}
	return s;
}

long long cb(long long n, long long k)
{
	if (n < k) return 0;
	return (((ft[n] * rt[n - k]) % md) * rt[k]) % md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ft[0] = rt[0] = 1;
	for (int i = 1; i <= M; i++) ft[i] = (ft[i - 1] * i) % md;
	rt[M] = fp(ft[M], md - 2);
	for (int i = M - 1; i >= 1; i--) rt[i] = (rt[i + 1] * (i + 1)) % md;
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		sl[0] = 0; sr[n + 1] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sl[i] = sl[i - 1] + a[i];
		}
		for (int i = n; i >= 1; i--)
			sr[i] = sr[i + 1] + a[i];
		int pi = n + 1;
		long long ans = 1;
		for (int i = 0; i <= n; i++) {
			while (pi > 0 && sr[pi] < sl[i]) pi--;
			if (pi <= i) break;
			if (sl[i] == sr[pi]) {
				int c0 = 1, c1 = 1, ri = n;
				if (!i) {
					c0--; c1--;
				}
				for (int j = i + 1; j <= n; j++) {
					if (!a[j]) c0++;
					else {
						ri = j - 1;
						break;
					}
				}
				if (ri + 1 == pi) {
					if (!i) c0--;
					long long ss = 0;
					for (int j = 0; j <= c0; j++)
						ss = (ss + cb(c0, j)) % md;
					ans = (ans * ss) % md;
					break;
				}
				for (int j = pi - 1; j >= 1; j--) {
					if (!a[j]) c1++;
					else break;
				}
				long long ss = 0;
				for (int j = 0; j <= min(c0, c1); j++)
					ss = (ss + cb(c0, j) * cb(c1, j)) % md;
				ans = (ans * ss) % md;
				i = ri;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}