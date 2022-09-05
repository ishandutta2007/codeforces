#include <bits/stdc++.h>
using namespace std;

typedef long long s64;
const int N = 2000 * 2 + 5, D = 1e9 + 7;
char s[N], t[N];
s64 C[N][N];
int k[N], b[N];

s64 F(int k, int b, int x) {
	x -= b;
	return C[k][x];
}
s64 check(int pk, int pb, int sk, int sb) {
	s64 ans = 0;
	int l = max(pb, -(sk + sb)), r = min(pk + pb, -sb);
	for (int d = l; d <= r; ++d) {
		s64 x = F(pk, pb, d) * F(sk, sb, -d) % D;
		ans += x * abs(d);
	}
	return ans % D;
}

int main() {
#ifdef kcz
	freopen("1.in", "r", stdin); //freopen("1.out","w",stdout);
#endif
	for (int i = 0; i < N; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % D;
	}
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		scanf("%d%s%s", &n, s + 1, t + 1);
		s64 ans = 0;
		for (int i = 1; i <= n; ++i) {
			k[i] = k[i - 1];
			b[i] = b[i - 1];
			if (s[i] == '?')
				++k[i];
			else if ((s[i] == '1') ^ (i % 2))
				++b[i];
			if (t[i] == '?') {
				--b[i];
				++k[i];
			} else if ((t[i] == '1') ^ (i % 2))
				--b[i];
		}
		for (int i = 1; i < n; ++i) {
			int pk = k[i], pb = b[i], sk = k[n] - pk, sb = b[n] - pb;
			ans += check(pk, pb, sk, sb);
		}
		cout << ans % D << endl;
	}
}