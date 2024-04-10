// Code by Denverjin.
#include <bits/stdc++.h>
using namespace std;

#define ld double
#define ll long long
#define pii pair <int, int>
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define PI acos(-1)
#define MOD 1000000007
#define MUL 19260817
#define EPS 1e-10
#define INF 1e9
#define LINF 1e18

template <typename T> inline void chkmin(T &x, T y) {if (y < x) x = y;}
template <typename T> inline void chkmax(T &x, T y) {if (y > x) x = y;}
template <typename T> inline T add(T x, T y) {return (x + y) % MOD;}
template <typename T> inline T mul(T x, T y) {return 1LL * x * y % MOD;}
template <typename T> inline T qp(T x, T n) {
	T ans = 1;
	do {if (n & 1) ans = mul(ans, x); x = mul(x, x);} while (n >>= 1);
	return ans;
}

#ifndef DEBUG
const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)
#endif

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

void readStr(char *s) {
	int c;
	while (isspace(c = getchar()));
	while (!isspace(c)) *s = c, ++ s, c = getchar();
}

const int N = 5005;
char s[N], Sbegin[N], Send[N];

namespace SAM {
	int tot, lst, go[N][26], len[N], link[N], tp[N];
	void init() {
		tot = lst = 1;
		memset(go, 0, sizeof go);
	}
	void add(int c) {
		int p = lst, np = ++ tot; lst = tot;
		while (p && !go[p][c]) go[p][c] = np, p = link[p];
		if (!p) link[np] = 1;
		else {
			int q = go[p][c];
			if (len[q] == len[p] + 1) link[np] = q;
			else {
				int nq = ++ tot;
				len[nq] = len[p] + 1;
				memcpy(go[nq], go[q], sizeof go[q]);
				link[nq] = link[q]; link[q] = link[np] = nq;
				while (go[p][c] == q) go[p][c] = nq, p = link[p];
			}
		}
	}
}

set <int> anss[N];
int begp[N], endp[N];

int main() {
	readStr(s); readStr(Sbegin); readStr(Send);
	int n = strlen(s), nbeg = strlen(Sbegin), nend = strlen(Send);
	SAM :: init();
	rep(i, n) SAM :: add(s[i] - 'a');
//	for (int i = 1; i <= SAM :: tot; ++ i) {
//		printf("%d: ", i);
//		rep(j, 26) printf("%d ", SAM :: go[i][j]);
//		printf("Link: %d\n", SAM :: link[i]);
//	}
	int u;
	u = 1;
	rep(i, nbeg) u = SAM :: go[u][Sbegin[i] - 'a'];
	if (u) SAM :: tp[u] |= 1;
	u = 1;
	rep(i, nend) u = SAM :: go[u][Send[i] - 'a'];
	if (u) SAM :: tp[u] |= 2;
	rep(i, n - nbeg + 1) {
		u = 1;
		rep(j, nbeg) u = SAM :: go[u][s[i + j] - 'a'];
		if (SAM :: tp[u] & 1) begp[i] = 1;
	}
	rep(i, n - nend + 1) {
		u = 1;
		rep(j, nend) u = SAM :: go[u][s[i + j] - 'a'];
		if (SAM :: tp[u] & 2) endp[i + nend] = 1;
	}
//	rep(i, n) printf("%d ", begp[i]); puts("");
//	rep(i, n) printf("%d ", endp[i + 1]); puts("");
	rep(i, n) {
		u = 1;
		for (int j = i; j < n; ++ j) {
			u = SAM :: go[u][s[j] - 'a'];
			if (j - i + 1 >= nbeg && j - i + 1 >= nend && 
					begp[i] && endp[j + 1])
				anss[u].insert(j - i + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= SAM :: tot; ++ i) ans += anss[i].size();
	printf("%d\n", ans);
	return 0;
}