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

	int n;
	while (scanf("%d", &n) == 1) {
		vector<pair<int, int> > a(n);
		for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
		map<int, int> mpx, mpy;
		map<pair<int, int>, int> mp;
		for (int i = 0; i < n; i++) {
			mpx[a[i].first]++;
			mpy[a[i].second]++;
			mp[a[i]]++;
		}
		ll ans = 0;
		for (map<int, int> ::iterator it = mpx.begin(); it != mpx.end(); it++) {
			ans += it->second * 1LL * (it->second - 1) / 2;
		}
		for (map<int, int> ::iterator it = mpy.begin(); it != mpy.end(); it++) {
			ans += it->second * 1LL * (it->second - 1) / 2;
		}
		for (map<pair<int, int>, int> ::iterator it = mp.begin(); it != mp.end(); it++) {
			ans -= it->second * 1LL * (it->second - 1) / 2;
		}
		cout << ans << endl;
	}

	return 0;
}