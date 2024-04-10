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

#define N 1000005

#define mul1 233
#define mod1 1000000007
#define mul2 19260817
#define mod2 998244353

#define fi first
#define se second

int n;
pii pre[N];
char s[N];
int tot;
pii pw[N];

pii gethsh(int l, int r) {
	return mp(
		(pre[r].fi - 1LL * pw[r - l].fi * pre[l].fi % mod1 + mod1) % mod1,
		(pre[r].se - 1LL * pw[r - l].se * pre[l].se % mod2 + mod2) % mod2);
}

int main() {
	n = read();
	pw[0].fi = pw[0].se = 1;
	rep(i, 1000000) pw[i + 1] = mp(1LL * pw[i].fi * mul1 % mod1, 1LL * pw[i].se * mul2 % mod2);
	rep(i, n) {
		scanf("%s", s);
		int lst = 0;
		int len = strlen(s);
		pii hsh;
		rep(i, len + 1) {
			if (tot >= i && gethsh(tot - i, tot) == hsh) lst = i;
			hsh = mp((1LL * hsh.fi * mul1 % mod1 + s[i]) % mod1, (1LL * hsh.se * mul2 % mod2 + s[i]) % mod2);
		}
		for (int i = lst; i < len; ++ i) {
			putchar(s[i]);
			++ tot;
			pre[tot] = mp((1LL * pre[tot - 1].fi * mul1 % mod1 + s[i]) % mod1, (1LL * pre[tot - 1].se * mul2 % mod2 + s[i]) % mod2);
		}
	}
	return 0;
}