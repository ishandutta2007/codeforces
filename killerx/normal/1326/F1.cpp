#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

int n;
char know[20][20];
int lft[1 << 7][20];
int rgt[1 << 7][20];
ll ans[1 << 14];

int main() {
	ios :: sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++ i)
		cin >> know[i];
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < n; ++ j)
			know[i][j] -= '0';
	for (int mask = 0; mask < (1 << n); ++ mask) {
		if (__builtin_popcount(mask) == n / 2) {
			vector <int> pre, suf;
			for (int i = 0; i < n; ++ i) {
				if (mask >> i & 1) pre.pb(i);
				else suf.pb(i);
			}
			memset(lft, 0, sizeof(lft));
			memset(rgt, 0, sizeof(rgt));
			int n0 = n / 2 - 1, n1 = n - n / 2 - 1;
			do {
				int ans = 0;
				for (int i = 0; i + 1 < pre.size(); ++ i)
					ans = ans << 1 | know[pre[i]][pre[i + 1]];
				lft[ans][pre.back()] ++;
			} while (next_permutation(pre.begin(), pre.end()));
			do {
				int ans = 0;
				for (int i = 0; i + 1 < suf.size(); ++ i)
					ans = ans << 1 | know[suf[i]][suf[i + 1]];
				rgt[ans][suf[0]] ++;
			} while (next_permutation(suf.begin(), suf.end()));
			for (int i = 0; i < n; ++ i) if (mask >> i & 1)
				for (int j = 0; j < n; ++ j) if (!(mask >> j & 1)) {
					for (int m0 = 0; m0 < (1 << n0); ++ m0) {
						for (int m1 = 0; m1 < (1 << n1); ++ m1) {
							ans[m0 << n1 + 1 | m1 | know[i][j] << n1] += 1LL * lft[m0][i] * rgt[m1][j];
						}
					}
				}
		}
	}
	for (int i = 0; i < (1 << n - 1); ++ i)
		cout << ans[i] << " \n"[i + 1 == (1 << n - 1)];
	return 0;
}