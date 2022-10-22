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

#define vec vector <int>
#define mat vector <vec>

mat mul(mat x, mat y) {
	mat t(x.size(), vec(y[0].size(), 0));
	rep(i, x.size()) rep(j, y[0].size()) {
		ll oo = 0;
		rep(k, y.size()) {
			oo += 1LL * x[i][k] * y[k][j];
			if (oo >= 1000000000000000LL) oo %= mod;
		}
		t[i][j] = oo % mod;
	}
	return t;
}

mat qp(mat x, int n) {
	mat ans(x.size(), vec(x[0].size(), 0));
	rep(i, x.size()) ans[i][i] = 1;
	while (n) {
		if (n & 1) ans = mul(ans, x);
		x = mul(x, x);
		n >>= 1;
	}
	return ans;
}

int a[7];

int main() {
	rep(i, 7) a[i] = read();
	mat pre(128, vec(1, 0));
	pre[1][0] = 1;
	rep(i, 7) {
		mat trans(128, vec(128, 0));
		rep(msk, 1 << (i + 1)) rep(msk1, 1 << (i + 1)) rep(msk2, 1 << i) {
			bool ok = 1;
			rep(j, i + 1) {
				if ((msk >> j & 1) && (msk1 >> j & 1) && (!j || (msk2 >> (j - 1) & 1)) && (j == i || (msk2 >> j & 1))) {
					ok = 0;
				}
			}
			if (ok) trans[msk][msk1] ++;
		}
		pre = mul(qp(trans, a[i]), pre);
		if (i + 1 < 7) {
			mat npre(128, vec(1, 0));
			rep(j, 1 << (i + 1)) npre[j | 1 << (i + 1)] = pre[j];
			pre = npre;
		}
	}
	printf("%d\n", pre[127][0]);
	return 0;
}