#include <bits/stdc++.h>
using namespace std;

#define nc() getchar()

const int maxn = 1e5 + 10;
int n, k;
bool a[2][maxn], vis[2][maxn];

void read(int& x) {
	x = 0;
	char ch = nc();
	for (; ch > 47 && ch < 58; x = (x << 3) + (x << 1) + (ch ^ 48), ch = nc());
}

bool dfs(bool chk, int h, int t) {
	if (h > n) return 1;
	if (vis[chk][h] || a[chk][h] || h < t) return 0;
	return vis[chk][h] = 1, dfs(chk ^ 1, h + k, t + 1) || dfs(chk, h + 1, t + 1) || dfs(chk, h - 1, t + 1);
}

int main() {
	read(n), read(k);
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = nc() == 'X';
		}
		for (; nc() ^ '\n'; );
	}
	puts(dfs(0, 1, 1) ? "YES" : "NO");
	return 0;
}