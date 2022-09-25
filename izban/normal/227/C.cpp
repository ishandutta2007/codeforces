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

using namespace std;

#define ll long long


const int maxn = 1 << 17;

int n, m;

int pow(int x, int k) {
	if (k == 0) return 1%m;
	if (k == 1) return x%m;
	int res = pow(x, k/2);
	res = 1LL * res * res % m;
	if (k&1)
		res = 1LL * res * x % m;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	int ans = pow(3, n);
	if (ans == 0) ans += m;
	ans--;
	cout << ans;

	return 0;
}