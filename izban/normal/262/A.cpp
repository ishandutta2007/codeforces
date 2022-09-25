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

int n, k;

int f(int x) {
	int res = 0;
	while (x) {
		res += (x % 10 == 4) || (x % 10 == 7);
		x /= 10;
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> k) {
		int x, ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			ans += f(x) <= k;
		}
		cout << ans << endl;
	}

	return 0;
}