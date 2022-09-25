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

ll x, y, m;

ll abs1(ll x) {
	if (x < 0) return -x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> x >> y >> m) {
		if (x >= m || y >= m) {
			cout << 0 << endl;
			continue;
		}
		if (x <= 0 && y <= 0) {
			cout << -1 << endl;
			continue;
		}
		if (x < y) swap(x, y);
		ll ans = 0;
		if (y < 0) {
			ans = abs1(y) / x;
			y += ans * x;
		}
		while (x < m && y < m) {
			ll z = x + y;
			if (x < y) x = z;
			else y = z;
			ans++;
		}
		cout << ans << endl;
	}


	return 0;
}