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

const int MAXN = 1024;
const int MOD = 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int a[6];
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5]) {
		int ans = 0;
		int cur = a[0];
		ans += cur;
		for (int i = 0; i < min(a[1], a[5]); i++) {
			ans += ++cur;
		}
		for (int i = 0; i < max(a[1], a[5]) - min(a[1], a[5]); i++) {
			ans += cur;
		}
		for (int i = 0; i < min(a[2], a[4]); i++) {
			ans += --cur;
		}
		assert(cur == a[3]);
		ans = 2 * ans - a[0] - a[3];
		cout << ans << endl;
	}

	return 0;
}