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
#include <unordered_map>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k;
	while (scanf("%d%d", &n, &k) == 2) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);

		ll sum = 0;
		for (int i = 0; i < n; i++) sum += abs(a[i]);
		ll ans = 0;
		for (ll cur = 1; abs(cur) <= sum; cur *= k) {
			unordered_map<ll, int> mp;
			ll s = 0;
			mp[0] = 1;
			for (int i = 0; i < n; i++) {
				s += a[i];
				// s - x == cur
				// x = s - cur
				if (mp.count(s - cur)) ans += mp[s - cur];
				mp[s]++;
			}
			if (k == 1 && cur == 1 || k == -1 && cur == -1) break;
		}
		cout << ans << endl;
	}

	return 0;
}