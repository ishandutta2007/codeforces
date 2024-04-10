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
const int MAXN = -1;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

int solve(int k, int a, int b) {
	if (a < b) swap(a, b);
	if (b < k) {
		if (a % k == 0 && a > 0) {
			return a / k;
		}
		return -1;
	}
	return a / k + b / k;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int k, a, b;
	while (cin >> k >> a >> b) {
		cout << solve(k, a, b) << endl;
	}

	return 0;
}