#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;
ll dp[2][maxn];
int n, a[maxn];
bool u[2][maxn], v[2][maxn];

ll dfs(int x, int sel) {
	if (x < 1 || x > n) {
		return 0;
	}
	if (x == 1) {
		return (dfs(x + a[x], 1) == -1 ? -1 : dfs(x + a[x], 1) + a[x]);
	} else {
		if (u[sel][x] && !v[sel][x]) {
			return -1;
		}
		if (u[sel][x] && v[sel][x]) {
			return dp[sel][x];
		}
		u[sel][x] = 1;
		int p = x + (sel ^ 1 ? a[x] : -a[x]);
//		if (p == 1) {
//			v[sel][x] = 1;
//			return dp[sel][x] = -1;
//		}
		ll t = dfs(p, sel ^ 1);
		v[sel][x] = 1;
		if (!~t) {
			return dp[sel][x] = -1;
		}
		return dp[sel][x] = t + a[x];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i < n; i++) {
		a[1] = i;
		printf("%I64d\n", dfs(1, 0));
	}
	return 0;
}


/*

#include <bits/stdc++.h>
using namespace std;

#define reg register
#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
const int maxn = 2e5 + 10;
int n, vis[maxn][2];
ll a[maxn], dp[maxn][2];
char buf[maxn << 3], *p1 = buf, *p2 = buf;

extern Finline char nc() {
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, maxn << 3, stdin), p1 == p2) ? EOF : *p1++;
}

template <class T>
extern Finline void read(reg T& x) {
	x = 0;
	reg char ch = nc();
	for (; ch < 48 || ch > 57; ch = nc());
	for (; ch > 47 && ch < 58; x = (x << 3) + (x << 1) + (ch ^ 48), ch = nc());
}

void write(const ll& x) {
	if (x > 9) {
		write(x / 10);
	}
	putchar(x - x / 10 * 10 + 48);
}

ll dfs(const int& x, const bool& sel, const int& now) {
	if (x < 1 || x > n) {
		return 0;
	}
	if (vis[x][sel] == now) {
		return -1;
	}
	if (~dp[x][sel]) {
		return dp[x][sel];
	}
	vis[x][sel] = now;
	const ll t = dfs(x + (sel ? -a[x] : a[x]), sel ^ 1, now);
	return !~t ? t : dp[x][sel] = t + a[x];
}

int main() {
	read(n);
	memset(dp, -1, sizeof dp);
	for (reg int i = 2; i <= n; i++) {
		read(a[i]);
	}
	for (reg int i = 1; i < n; i++) {
		a[1] = i, dp[1][0] = -1;
		if (!~dfs(1, 0, i)) {
			putchar('-'), putchar('1');
		} else {
			write(dp[1][0]);
		}
		putchar('\n');
	}
	return 0;
}

*/