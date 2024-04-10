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

const int N = 10000;
int ans[N];

namespace SAM {
	int go[N][2], len[N], dp[N], link[N], tot, lst;
	int occ[N];
	void init() {
		lst = tot = 1;
		memset(go, 0, sizeof go);
		rep(i, N) occ[i] = INF;
	}
	void expand(int c) {
		int p = lst, np = ++ tot; lst = tot;
		len[np] = len[p] + 1;
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
	int vv[N];
	string patt[N];
	int cnt;
	bool chk(string s) {
		if (s == "0011") return 0;
		if (s == "0101") return 0;
		if (s == "1110") return 0;
		if (s == "1111") return 0;
		return 1;
	}
	void gen(string s) {
		if (s.size() && chk(s))
			patt[cnt ++] = s;
		if (s.size() == 4) return;
		gen(s + '0');
		gen(s + '1');
	}
	void calc() {
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= tot; ++ i) vv[i - 1] = i;
		sort(vv, vv + tot, [&](int a, int b) {
			return len[a] < len[b];
		});
		dp[1] = 1;
		gen("");
		for (int i = tot - 1; i; -- i) {
			int p = vv[i];
			chkmin(occ[link[p]], occ[p]);
		}
		rep(i, tot) {
//			printf("%d %d\n", vv[i], dp[vv[i]]);
			rep(j, cnt) {
				int to = vv[i];
				rep(k, patt[j].size()) to = go[to][patt[j][k] - '0'];
				if (!to) continue;
				dp[to] = add(dp[to], dp[vv[i]]);
			}
		}
		for (int i = 2; i <= tot; ++ i) {
			ans[occ[i]] = add(ans[occ[i]], dp[i]);
		}
	}
}

int main() {
	SAM :: init();
	int n = read();
	rep(i, n) {
		int c = getchar(); getchar();
		SAM :: expand(c - '0');
		SAM :: occ[SAM :: lst] = i;
	}
//	for (int i = 1; i <= SAM :: tot; ++ i) {
//		printf("%d: ", i);
//		rep(j, 2) printf("%d ", SAM :: go[i][j]);
//		printf("link: %d\n", SAM :: link[i]);
//	}
	SAM :: calc();
	rep(i, n) {
		printf("%d\n", ans[i]);
		ans[i + 1] = add(ans[i + 1], ans[i]);
	}
	return 0;
}