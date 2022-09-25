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
const int MOD = 1000 * 1000 * 1000 + 7;

int bin(int n, int k) {
	if (k == 0) return 1 % MOD;
	int res = bin(n, k / 2);
	res = 1LL * res * res % MOD;
	if (k % 2 == 1) res = 1LL * res * n % MOD;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int p, k;
	while (cin >> p >> k) {
		if (k == 0) {
			cout << bin(p, p - 1) << endl;
		}
		else {
			int cnt = 0;
			vector<char> was(p, 0);
			for (int i = 1; i < p; i++) {
				if (was[i]) continue;
				int x = i;
				cnt++;
				while (!was[x]) {
					was[x] = 1;
					x = 1LL * x * k % p;
				}
			}
			cnt += k == 1;
			cout << bin(p, cnt) << endl;
		}
	}

	return 0;
}