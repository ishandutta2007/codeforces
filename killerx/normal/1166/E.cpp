#include <bits/stdc++.h>
using namespace std;
int m, n;
bool is[55][10005];
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++ i) {
		int cnt; scanf("%d", &cnt);
		for (; cnt --; ) {
			int x; scanf("%d", &x);
			is[i][x] = 1;
		}
	}
	bool can = 1;
	for (int i = 0; i < m; ++ i) {
		for (int j = i + 1; j < m; ++ j) {
			bool ok = 0;
			for (int k = 0; k < n; ++ k) {
				if (is[i][k] && is[j][k]) {
					ok = 1;
				}
			}
			if (!ok) can = 0;
		}
	}
	if (can) puts("possible");
	else puts("impossible");
	return 0;
}