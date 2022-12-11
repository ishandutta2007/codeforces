#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 2210;

int n, k, ans[N][N], x[N], y[N], xpre[N], xsuf[N], ypre[N], ysuf[N], xl[N], xr[N], yl[N], yr[N], c[N];
char s[N][N];

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; i ++) {
		x[i] = 1; xl[i] = n + 1; xr[i] = 0;
		for(int j = 1; j <= n; j ++) {
			if(s[i][j] == 'B') {
				x[i] = 0;
				xl[i] = min(xl[i], j);
				xr[i] = max(xr[i], j);
			}
		}
	}
	for(int i = 1; i <= n; i ++) {
		y[i] = 1; yl[i] = n + 1; yr[i] = 0;
		for(int j = 1; j <= n; j ++) {
			if(s[j][i] == 'B') {
				y[i] = 0;
				yl[i] = min(yl[i], j);
				yr[i] = max(yr[i], j);
			}
		}
	}
	for(int i = 1; i <= n; i ++) xpre[i] = xpre[i - 1] + x[i];
	for(int i = 1; i <= n; i ++) ypre[i] = ypre[i - 1] + y[i];
	for(int i = n; i >= 1; i --) xsuf[i] = xsuf[i + 1] + x[i];
	for(int i = n; i >= 1; i --) ysuf[i] = ysuf[i + 1] + y[i];
	for(int i = 1; i <= n - k + 1; i ++) {
		int fx = xpre[i - 1] + xsuf[i + k];
		memset(c, 0, sizeof c);
		for(int u = i; u <= i + k - 1; u ++) {
			int nl = max(1, xr[u] - k + 1), nr = xl[u];
			if(nl <= nr) {
				c[nr + 1] --; c[nl] ++;
			}
		}
		int now = 0;
		for(int j = 1; j <= n - k + 1; j ++) {
			now += c[j];
			ans[i][j] = now + fx;
		}
	}
	for(int i = 1; i <= n - k + 1; i ++) {
		int fx = ypre[i - 1] + ysuf[i + k];
		memset(c, 0, sizeof c);
		for(int u = i; u <= i + k - 1; u ++) {
			int nl = max(1, yr[u] - k + 1), nr = yl[u];
			if(nl <= nr) {
				c[nr + 1] --; c[nl] ++;
			}
		}
		int now = 0;
		for(int j = 1; j <= n - k + 1; j ++) {
			now += c[j];
			ans[j][i] += now + fx;
		}
	}
	int res = 0;
	for(int i = 1; i <= n - k + 1; i ++)
		for(int j = 1; j <= n - k + 1; j ++)
			res = max(res, ans[i][j]);
	printf("%d\n", res);
	return 0;
}