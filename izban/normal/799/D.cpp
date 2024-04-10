#include <unordered_map>
#include <unordered_set>
#include <functional>
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

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = 1 << MAXK;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;
const ll INF = 1e13;

int fastsolve(int a, int b, int w, int h, vector<int> x) {
	int n = x.size();
	sort(x.begin(), x.end());
	reverse(x.begin(), x.end());

	// 2^17 > 10^5
	n = min(n, 34);
	x.resize(n);

	const int INF9 = 1e9;
	int ans = INF9;
	for (int it = 0; it < 2; it++) {
		if (w >= a) {
			ll cur = h;
			int cres = 0;
			while (cres < n && cur < b) {
				cur *= x[cres++];
			}
			if (cur >= b) ans = min(ans, cres);
		}

		const int MX = 1 << 17;
		vector<char> dp(MX);
		dp[w] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = MX - 1; j >= 1; j--) if (dp[j]) {
				if (j * 1LL * x[i] >= a) {
					ll prod = 1;
					for (int l = 0; l < i; l++) prod = min(INF, prod * x[l]);
					prod /= j / w;
					int cres = i + 1;
					while (1LL * prod * h < b && cres < n) prod *= x[cres++];
					if (1LL * prod * h >= b) ans = min(ans, cres);
				}
				if (1LL * j * x[i] < MX) dp[j * x[i]] = 1;
			}
		}
		swap(w, h);
	}
	if (ans == INF9) ans = -1;
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	//cerr << fastsolve(1e5, 1e5, 1, 1, vector<int>(1e5, 2)) << endl;
	//return 0;

	int a, b, w, h, n;
	while (scanf("%d%d%d%d%d", &a, &b, &w, &h, &n) == 5) {
		vector<int> x(n);
		for (int i = 0; i < n; i++) scanf("%d", &x[i]);

		printf("%d\n", fastsolve(a, b, w, h, x));
	}

	return 0;
}