#pragma GCC optimize(2)
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
char c[1005][1005];
int sum[26][1005][1005];
int count(int x1, int y1, int x2, int y2, int cc) {
	return sum[cc][x2 + 1][y2 + 1] - sum[cc][x1][y2 + 1] - sum[cc][x2 + 1][y1] + sum[cc][x1][y1];
}
int main() {
	n = read(), m = read();
	rep(i, n) scanf("%s", c[i]);
	rep(i, n) rep(j, m) rep(cc, 26) {
		sum[cc][i + 1][j + 1] = - sum[cc][i][j] + sum[cc][i][j + 1] + sum[cc][i + 1][j];
		if (c[i][j] == cc + 'a') ++ sum[cc][i + 1][j + 1];
	}
	ll ans = 0;
	rep(x, n) rep(y, m) {
		int lb = x, rb = n - 1;
		while (lb < rb) {
			int md = (lb + rb + 1) >> 1;
			if (count(x, y, md, y, c[x][y] - 'a') == md - x + 1) lb = md;
			else rb = md - 1;
		}
		int len = lb - x + 1;
		if (x + len * 3 > n) continue;
		if (c[x][y] == c[x + len][y] || c[x + len][y] == c[x + len * 2][y]) continue;
		if (count(x + len, y, x + len * 2 - 1, y, c[x + len][y] - 'a') != len) continue;
		if (count(x + len * 2, y, x + len * 3 - 1, y, c[x + len * 2][y] - 'a') != len) continue;
		lb = y, rb = m - 1;
		while (lb < rb) {
			int md = (lb + rb + 1) >> 1;
			bool ok = 1;
			ok &= count(x, y, x + len - 1, md, c[x][y] - 'a') == len * (md - y + 1);
			ok &= count(x + len, y, x + len * 2 - 1, md, c[x + len][y] - 'a') == len * (md - y + 1);
			ok &= count(x + len * 2, y, x + len * 3 - 1, md, c[x + len * 2][y] - 'a') == len * (md - y + 1);
			if (ok) lb = md;
			else rb = md - 1;
		}
//		cerr << x << " " << y << " " << len << " " << lb << endl;
		ans += lb - y + 1;
	}
	printf("%lld\n", ans);
	return 0;
}