#include <cstring>
#include <cstdio>

typedef long long LL;

int n, k, MOD, len;
LL pw[1010];

LL f[1002][1002][2][2][2];

LL dfs(int l, int yu, bool lst, bool z, bool ok) {
	if(l == len + 1) return ok && lst;
	if(~ f[l][yu][lst][z][ok]) return f[l][yu][lst][z][ok];
	LL ans = 0;
	bool ok2, z2;
	int yu2;
	for(int i = 0; i < 10; i ++) {
		yu2 = (yu + i * pw[l - 1] % k) % k;
		z2 = z && (i == 0);
		ok2 = ok || (!z2 && yu2 == 0);
		(ans += dfs(l + 1, yu2, i > 0, z2, ok2) % MOD) %= MOD;
	}
	return f[l][yu][lst][z][ok] = ans;
}

int main() {
	scanf("%d%d%d", &n, &k, &MOD);
	for(int i = pw[0] = 1ll; i <= n; i ++)
		pw[i] = pw[i - 1] * 10 % k;
	len = n;
	memset(f, -1, sizeof f);
	printf("%lld\n", dfs(1, 0, false, true, false));
	return 0;
}