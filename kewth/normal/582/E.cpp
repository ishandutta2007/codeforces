#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 505, mod = 1000000007;
char s[maxn];
int np;
int ls[maxn], rs[maxn];
char type[maxn];

int make(int l, int r) {
	if(l == r) {
		type[++ np] = s[l];
		return np;
	}

	int tot = 0, m = l;
	for(int i = r; i >= l; i --) {
		if(s[i] == ')') ++ tot;
		if(s[i] == '(') -- tot;
		if(!tot) {
			m = i;
			break;
		}
	}

	if(m == l) return make(l + 1, r - 1);

	int now = ++ np;
	rs[now] = make(m, r);
	type[now] = s[m - 1];
	ls[now] = make(l, m - 2);

	return now;
}

void FWT_and(ll *a, int n, int t) {
	for(int m = 1; m < n; m <<= 1)
		for(int i = 0; i < n; i += m << 1)
			for(int k = i; k < i + m; k ++)
				a[k] += a[k + m] * t;
	for(int i = 0; i < n; i ++) {
		a[i] %= mod;
		if(a[i] < 0) a[i] += mod;
	}
}

void FWT_or(ll *a, int n, int t) {
	for(int m = 1; m < n; m <<= 1)
		for(int i = 0; i < n; i += m << 1)
			for(int k = i; k < i + m; k ++)
				a[k + m] += a[k] * t;
	for(int i = 0; i < n; i ++) {
		a[i] %= mod;
		if(a[i] < 0) a[i] += mod;
	}
}

ll f[maxn][1 << 16], tmp[1 << 16];
int fuck[16][8];

void dp(int u, int n) {
	if(!ls[u] and !rs[u]) {
		auto update = [&](char c) {
			int S = 0;
			for(int i = 0; i < n; i ++)
				if('A' <= c and c <= 'D')
					S |= fuck[i][c - 'A'] << i;
				else
					S |= (!fuck[i][c - 'a']) << i;
			++ f[u][S];
		};

		if(type[u] == '?') {
			update('a');
			update('b');
			update('c');
			update('d');
			update('A');
			update('B');
			update('C');
			update('D');
		} else
			update(type[u]);
		return;
	}

	dp(ls[u], n);
	dp(rs[u], n);

	if(type[u] == '&' or type[u] == '?') {
		FWT_and(f[ls[u]], 1 << n, 1);
		FWT_and(f[rs[u]], 1 << n, 1);
		for(int S = 0; S < (1 << n); S ++)
			tmp[S] = f[ls[u]][S] * f[rs[u]][S] % mod;
		FWT_and(tmp, 1 << n, -1);
		FWT_and(f[ls[u]], 1 << n, -1);
		FWT_and(f[rs[u]], 1 << n, -1);
		for(int S = 0; S < (1 << n); S ++)
			(f[u][S] += tmp[S]) %= mod;
	}

	if(type[u] == '|' or type[u] == '?') {
		FWT_or(f[ls[u]], 1 << n, 1);
		FWT_or(f[rs[u]], 1 << n, 1);
		for(int S = 0; S < (1 << n); S ++)
			tmp[S] = f[ls[u]][S] * f[rs[u]][S] % mod;
		FWT_or(tmp, 1 << n, -1);
		FWT_or(f[ls[u]], 1 << n, -1);
		FWT_or(f[rs[u]], 1 << n, -1);
		for(int S = 0; S < (1 << n); S ++)
			(f[u][S] += tmp[S]) %= mod;
	}
}

int main() {
	scanf("%s", s + 1);
	int len = int(strlen(s + 1));
	int now = make(1, len);

	int n = read, S = 0;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < 4; j ++)
			fuck[i][j] = read;
		S |= read << i;
	}
	dp(now, n);

	printf("%lld\n", f[now][S]);
}