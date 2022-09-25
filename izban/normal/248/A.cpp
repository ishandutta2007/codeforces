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
#include <ctime>
#include <cassert>

using namespace std;

#define ll long long
#define double long double

const int maxn = 1 << 7;
const int inf = 1000000007;
const int dx[2] = {1, -1};

int n, a[2], ans = 100000000;

void check(int x, int y) {
	int res = 0;
	if (x == 0)
		res += a[0];
	else
		res += n - a[0];
	if (y == 0)
		res += a[1];
	else
		res += n - a[1];
	ans = min(ans, res);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[0] += x;
		a[1] += y;
	}

	check(0, 0);
	check(0, 1);
	check(1, 0);
	check(1, 1);
	
	cout << ans;

	return 0;
}