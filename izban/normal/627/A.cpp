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

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ll s, x;
	while (cin >> s >> x) {
		ll ans = 0;
		if (s == x) ans = -2;
		const int K = 50;
		vector<vector<ll> > dp(K + 1, vector<ll>(2));

		dp[0][0] = 1;
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < 2; j++) {
				for (int a = 0; a < 2; a++) {
					for (int b = 0; b < 2; b++) {
						if ((a ^ b) == x % 2 && (a + b + j) % 2 == s % 2) {
							dp[i + 1][(a + b + j) / 2] += dp[i][j];
						}
					}
				}
			}
			s /= 2;
			x /= 2;
		}
		ans += dp[K][0];
		cout << ans << endl;
	}

	return 0;
}