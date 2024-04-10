#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = 111;
const int inf = 1e9;

int n, m;
int u[maxn], v[maxn];
string s[maxn];

int dp[maxn][maxn];
int p[maxn][maxn];

int rec(int l, int r) {
	if (l == r + 1) return 1;
	if (dp[l][r] != -1) return dp[l][r];
	
	if (l == r) {
		bool ok = 1;
		for (int i = 0; i < m; i++) if (u[i] == v[i] && u[i] == l) ok = 0;
		return dp[l][r] = ok;
	}

	dp[l][r] = 0;
	for (int i = l; i <= r; i++) {
		bool ok = 1;
		for (int j = 0; j < m; j++) {
			bool leftU = u[j] > l && u[j] <= i;
			bool rightU = u[j] > i && u[j] <= r;
			bool leftV = v[j] > l && v[j] <= i;
			bool rightV = v[j] > i && v[j] <= r;
			if (u[j] == l) {
				if (s[j] == "RIGHT") ok &= rightV;
				else ok &= leftV;
			} else {
				ok &= !leftU || leftV;
				ok &= !rightU || rightV;
			}
		}
		if (!ok) continue;
		if (rec(l + 1, i) && rec(i + 1, r)) {
			dp[l][r] = 1;
			p[l][r] = i;
			break;
		}
	}
	return dp[l][r];
}

void rec2(int l, int r) {
	if (l == r + 1) return;
	if (l == r) {
		cout << l << " ";
		return;
	}
	rec2(l + 1, p[l][r]);
	cout << l << " ";
	rec2(p[l][r] + 1, r);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (cin >> n >> m) {
		for (int i = 0; i < m; i++) cin >> u[i] >> v[i] >> s[i];

		memset(dp, -1, sizeof(dp));
		rec(1, n);
		if (dp[1][n] == 0) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		rec2(1, n);
		cout << endl;
	}

	return 0;
}