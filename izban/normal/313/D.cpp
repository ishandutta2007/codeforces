#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 3 * (1 << 7), maxm = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, k;
int l[maxm], r[maxm], c[maxm];
ll e[maxn][maxn];
ll d[maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> m >> k) {
		for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) d[i][j] = e[i][j] = (ll)1e18;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &l[i], &r[i], &c[i]);
			for (int j = l[i] - 1; j <= r[i] - 1; j++) {
				e[j][r[i]] = min(e[j][r[i]], (ll)c[i]);
			}
		}
		d[0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n; j++) {
				for (int o = i + 1; o <= n; o++) {
					d[o][j + o - i] = min(d[o][j + o - i], d[i][j] + e[i][o]);
				}
				d[i + 1][j] = min(d[i + 1][j], d[i][j]);
			}
		}
		ll ans = 2e18;
		for (int i = k; i <= n; i++) ans = min(ans, d[n][i]);
		if (ans > 1e17) ans = -1;
		cout << ans << endl;		
	}

	return 0;
}