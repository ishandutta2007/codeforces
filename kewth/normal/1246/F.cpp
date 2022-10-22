#pragma GCC optimize(3)
#if 0
2020.04.02

 i  i  j 
 j 
 i  k  i  j  [L[k][i], R[k][i]] 
 sum(n - (R - L + 1))  sum(L)  sum(R) 
 L, R  O(n^2) 

 [L, R],  [L, R] 
 nxt  nxt[i]  i  i 
 [L1, R]  [L2, R] 



 t  fr[t][i]  [L, i]  t 
 fl[t][i] 
 [L, R]  t  [fl[t][L], fr[t][R]] 
 [L, R]  26 
 L, R 

 fl, fr  i 
 O(nlognA)  A  log  A 
#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

const int maxn = 100005, maxk = 17, A = 26;
char s[maxn];
//  3  5 
/* int fl[maxn][maxk], fr[maxn][maxk]; */
/* ll sl[maxn][maxk], sr[maxn][maxk]; */
int fl[maxk][maxn], fr[maxk][maxn];
ll sl[maxk][maxn], sr[maxk][maxn];
int tol[maxn], tor[maxn];
int L[maxn], R[maxn];
int pre[maxn][A + 1], nxt[maxn][A + 1];
int st[maxk][maxn];
int hb[maxn];
int tot[maxn];

void stinit (int n) {
	for (int i = n; i; i --)
		for (int k = 1; i + (1 << k) - 1 <= n; k ++)
			st[k][i] = st[k - 1][i] | st[k - 1][i + (1 << k >> 1)];
	for (int i = 2; i <= n; i ++)
		hb[i] = hb[i >> 1] + 1;
}

int stquery (int l, int r) {
	int k = hb[r - l + 1];
	return st[k][l] | st[k][r - (1 << k) + 1];
}

inline int S (int i) { return s[i] - 'a'; }

int main () {
	scanf("%s", s + 1);
	int n = int(strlen(s + 1));

	for (int i = 1; i <= n; i ++)
		st[0][i] = 1 << S(i);
	stinit(n);

	std::fill(pre[1] + 1, pre[1] + A + 1, tol[1] = 1);
	for (int i = 2; i <= n; i ++) {
		std::copy(pre[i - 1], pre[i - 1] + A + 1, pre[i]);
		tol[i] = pre[i][S(i) + 1];
		pre[i][S(i) + 1] = i;
	}

	std::fill(nxt[n] + 1, nxt[n] + A + 1, tor[n] = n);
	for (int i = n - 1; i; i --) {
		std::copy(nxt[i + 1], nxt[i + 1] + A + 1, nxt[i]);
		tor[i] = nxt[i][S(i) + 1];
		nxt[i][S(i) + 1] = i;
	}

	for (int i = 1; i <= n; i ++) {
		std::sort(pre[i] + 1, pre[i] + A + 1, std::greater<int>());
		std::sort(nxt[i] + 1, nxt[i] + A + 1);
	}

	for (int i = 1; i <= n; i ++) fl[0][i] = fr[0][i] = L[i] = R[i] = i;
	std::fill(tot + 1, tot + n + 1, n);

	ll ans = 1ll * n * n * n - n;
	/* debug("%lld\n", ans); */
	for (int t = 1; t <= A; t ++) {
		for (int i = 1; i <= n; i ++) {
			sl[0][i] = fl[0][i] = std::min(fl[0][i], tol[nxt[i][t]]);
			sr[0][i] = fr[0][i] = std::max(fr[0][i], tor[pre[i][t]]);
		}
		for (int k = 1; k < maxk; k ++)
			for (int i = 1; i <= n; i ++) {
				fl[k][i] = fl[k - 1][fl[k - 1][i]];
				fr[k][i] = fr[k - 1][fr[k - 1][i]];
				sl[k][i] = sl[k - 1][i] + sl[k - 1][fl[k - 1][i]];
				sr[k][i] = sr[k - 1][i] + sr[k - 1][fr[k - 1][i]];
			}
		for (int i = 1; i <= n; i ++)
			if (tot[i] and __builtin_popcount(unsigned(stquery(L[i], R[i]))) == t) {
				for (int k = maxk - 1; k >= 0; k --)
					if ((1 << k) <= tot[i]) {
						int nl = fl[k][L[i]], nr = fr[k][R[i]];
						if (__builtin_popcount(unsigned(stquery(nl, nr))) <= t) {
							ans += sl[k][L[i]];
							ans -= sr[k][R[i]];
							L[i] = nl;
							R[i] = nr;
							tot[i] -= 1 << k;
						}
					}
				if (tot[i]) {
					ans += sl[0][L[i]];
					ans -= sr[0][R[i]];
					L[i] = fl[0][L[i]];
					R[i] = fr[0][R[i]];
					-- tot[i];
				}
			}
		/* for (int i = 1; i <= n; i ++) */
		/* 	debug("%d - %d (%d)\n", L[i], R[i], tot[i]); */
		/* debug("%lld\n", ans); */
		/* debug("\n"); */
	}

	printf("%lld\n", ans);
}