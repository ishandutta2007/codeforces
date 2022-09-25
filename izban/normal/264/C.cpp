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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, a, b, v[maxn], c[maxn];
ll d[maxn];
bool vis[maxn];
pair<ll, int> mx1, mx2;

ll getbestres(int x) {
	if (mx1.second != x) return mx1.first;
	if (mx2.second != x) return mx2.first;
	return -1e17;
}

void updmx(ll x, int y) {
	if (x > mx1.first) {
		if (y != mx1.second) mx2 = mx1;
		mx1 = make_pair(x, y);
	} else if (x > mx2.first && y != mx1.second) {
		mx2 = make_pair(x, y);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int tests;
	scanf("%d%d", &n, &tests);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	
	for (int test = 1; test <= tests; test++) {
		scanf("%d%d", &a, &b);
		mx1 = make_pair(0, 1), mx2 = make_pair(0, 2);
		memset(d, 0, sizeof(d));
		memset(vis, 0, sizeof(vis));
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[c[i]] && 1LL * a * v[i] > 0) {
				d[c[i]] += 1LL * a * v[i];
			}
			if (!vis[c[i]]) {
				vis[c[i]] = 1;
				d[c[i]] = 1LL * b * v[i];
			}
			ll lastres = getbestres(c[i]);
			d[c[i]] = max(d[c[i]], lastres + 1LL * b * v[i]);
			updmx(d[c[i]], c[i]);
			ans = max(ans, d[c[i]]);
		}
		cout << ans << endl;
	}

	return 0;
}