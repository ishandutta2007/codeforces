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

	int n, m;
	while (cin >> n >> m) {
		int cnt2 = 0, cnt3 = 0, cnt6 = 0;
		for (int i = 1;; i++) {
			if (i % 6 == 0) {
				cnt6++;
			}
			else if (i % 3 == 0) {
				cnt3++;
			}
			else if (i % 2 == 0) {
				cnt2++;
			}
			if (max(n - cnt2, 0) + max(m - cnt3, 0) <= cnt6) {
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}