#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n, m;
char s[100005], t[100005];
int dp[32][100005];
int mx[32][100005];
int hs[100005], ht[100005], pw[100005];

int geths(int l, int r) {return (hs[r] - 1LL * hs[l] * pw[r - l] % mod + mod) % mod;}
int getht(int l, int r) {return (ht[r] - 1LL * ht[l] * pw[r - l] % mod + mod) % mod;}

struct SEGT {
	int mx[400005], siz;
	void ini() {
		for (siz = 1; siz <= n; siz <<= 1) ;
		rep(i, siz << 1) mx[i] = 0;
	}
	void upd(int l, int r, int v) {
		for (l += siz, r += siz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) mx[l] = max(mx[l], v), ++ l;
			if (r & 1) -- r, mx[r] = max(mx[r], v);
		}
	}
	int qry(int x) {
		int ans = 0;
		for (x += siz; x; x >>= 1) ans = max(ans, mx[x]);
		return ans;
	}
} segt;

int main() {
	n = read();
	pw[0] = 1;
	rep(i, n) pw[i + 1] = pw[i] * 233LL % mod;
	scanf("%s", s);
	rep(i, n) hs[i + 1] = (hs[i] * 233LL + s[i]) % mod;
	m = read();
	scanf("%s", t);
	rep(i, m) ht[i + 1] = (ht[i] * 233LL + t[i]) % mod;
	int x = read();
	segt.ini();
	rep(i, x) {
		rep(j, n) {
			// printf("%d %d %d\n", i, j, dp[i][j]);
			int lb = 0, rb = min(n - j, m - dp[i][j]);
			while (lb < rb) {
				int md = (lb + rb + 1) >> 1;
				if (geths(j, j + md) == getht(dp[i][j], dp[i][j] + md)) lb = md;
				else rb = md - 1;
			}
			int k = lb;
			segt.upd(j + k, n + 1, dp[i][j] + k);
		}
		rep(j, n + 1) dp[i + 1][j] = segt.qry(j);
		segt.ini();
	}
	puts(dp[x][n] == m ? "YES" : "NO");
	return 0;
}