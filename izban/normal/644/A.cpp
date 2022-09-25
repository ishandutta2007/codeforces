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
const double PHI = (sqrt(5.0) - 1) / 2.0;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int k, n, m;
	while (cin >> k >> n >> m) {
		if (k > n * m) cout << -1 << endl;
		else {
			int need[2] = { k / 2, (k + 1) / 2 };
			int cnt[2] = { 0, 0 };
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					int x = ((i + j) % 2) ^ 1;
					int y = 0;
					if (cnt[x] != need[x]) y = 2 * ++cnt[x] - x;
					cout << y << " \n"[j + 1 == m];
				}
			}
		}
	}

	return 0;
}