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
#define foreach(it,c) for (__typedef(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

char c[505][505];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int main() {
	int n = read(), m = read();
	rep(i, n) {
		scanf("%s", c[i]);
	}
	vector <pii> can;
	int CNT = 0;
	rep(i, n) rep(j, m) {
		if (c[i][j] == '*') ++ CNT;
		if (i && j && i + 1 < n && j + 1 < m && c[i][j] == '*') {
			bool ok = 1;
			rep(d, 4) {
				int ni = i + dx[d];
				int nj = j + dy[d];
				if (c[ni][nj] != '*') ok = 0;
			}
			if (ok) can.pb(mp(i, j));
		}
	}
	if (can.size() != 1) {
		puts("NO");
		return 0;
	}
	int x = can[0].first;
	int y = can[0].second;
	CNT --;
	int lx = x;
	while (lx && c[lx - 1][y] == '*') -- lx, -- CNT;
	int ly = y;
	while (ly && c[x][ly - 1] == '*') -- ly, -- CNT;
	int rx = x;
	while (rx + 1 < n && c[rx + 1][y] == '*') ++ rx, -- CNT;
	int ry = y;
	while (ry + 1 < m && c[x][ry + 1] == '*') ++ ry, -- CNT;
	if (CNT) {
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}