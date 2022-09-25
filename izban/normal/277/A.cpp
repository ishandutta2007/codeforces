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

const int maxn = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
int k[maxn], a[maxn][maxn];
bool vis[maxn];

void dfs(int v) {
	vis[v] = 1;
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		for (int j = 1; j <= m; j++) {
			if (a[v][j] && a[i][j]) {
				dfs(i);
				break;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> m) {
		bool f = 1;
		memset(vis, 0, sizeof(vis));
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			cin >> k[i];
			f &= k[i] == 0;
			for (int j = 0; j < k[i]; j++) {
				int x;
				cin >> x;
				a[i][x] = 1;
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dfs(i);
				ans++;
			}
		}

		cout << ans - 1 + f << endl;
	}

	return 0;
}