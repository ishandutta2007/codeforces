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
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int dp[1000001];

int f(int x) {
	if (dp[x] != -1) return dp[x];
	int y = x;
	int res = inf;
	while (y) {
		if (y % 10) res = min(res, f(x - y % 10) + 1);
		y /= 10;
	}
	return dp[x] = res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	cin >> n;
	cout << f(n);

	return 0;
}