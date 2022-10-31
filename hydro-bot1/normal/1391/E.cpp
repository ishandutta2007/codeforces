// Hydro submission #61891e031edf93b3ad658aab@1636376067573
#include <bits/stdc++.h>
using namespace std;

inline int read();
#define N 500010
#define pb push_back

int n, m, dep[N], f[N], vis[N];
vector<int> e[N], vec[N];

void dfs(int x, int fa) {
	vis[x] = 1;
	dep[x] = dep[fa] + 1, f[x] = fa;
	for (auto y : e[x]) {
		if (!vis[y]) dfs(y, x);
	}
}

int main() {
	for (int T = read(); T --; ) {
		n = read(), m = read();

		for (int i = 1; i <= m; i ++) {
			int x = read(), y = read();
			e[x].pb(y), e[y].pb(x);
		}

		dfs(1, 0);
		int flag = 0, sum = 0, x = 0;
		for (int i = 1; i <= n; i ++) {
			if (dep[i] * 2 >= n) flag = 1, x = i;
		}

		if (flag) {
			printf("PATH\n%d\n", dep[x]);
			for (; x; x = f[x]) printf("%d ", x);
			puts("");
		} else {
			for (int i = 1; i <= n; i ++) {
				vec[dep[i]].pb(i);
			}
			for (int i = 1; i <= n; i ++) {
				if (vec[i].size() % 2 == 1) sum ++;
			}
			printf("PAIRING\n%d\n", (n - sum) / 2);
			for (int i = 1; i <= n; i ++) {
				for (int j = 0; j < vec[i].size() / 2; j ++) {
					printf("%d %d\n", vec[i][j * 2], vec[i][j * 2 + 1]);
				}
			}
		}

		for (int i = 1; i <= n; i ++) {
			vec[i].clear(), e[i].clear();
			f[i] = dep[i] = vis[i] = 0;
		}
	}
	return 0;
}

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return f ? -x : x;
}