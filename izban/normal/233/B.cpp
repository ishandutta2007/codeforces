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
#include <assert.h>

using namespace std;

#define ll long long

ll n;

int s(int x) {
	int res = 0;
	while (x)
		res += x % 10, x /= 10;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int x = max(0.0, sqrt(n*1.0) - 1000); x <= sqrt(n*1.0) + 1000; x++)
		if (1LL * x * x + 1LL * x * s(x) == n) {
			cout << x;
			return 0;
		}

	cout << -1;

	return 0;
}