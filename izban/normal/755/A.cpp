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
const int MAXN = 1 << 20;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int prime[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	for (int i = 2; i < MAXN; i++) prime[i] = 1;
	
	for (int i = 2; i < MAXN; i++) {
		if (!prime[i]) continue;
		for (int j = i + i; j < MAXN; j += i) {
			prime[j] = 0;
		}
	}

	int n;
	while (cin >> n) {
		bool ok = 0;
		for (int m = 1; m <= 1000; m++) {
			if (!prime[n * m + 1]) {
				cout << m << endl;
				ok = 1;
				break;
			}
		}
		assert(ok);
	}

	return 0;
}