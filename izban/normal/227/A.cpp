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


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    ll x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	ll xa = x2-x1, xb = x3 - x2, ya = y2-y1, yb = y3-y2;
	ll ans = xa*yb - ya*xb;

	if (ans == 0) {
		cout << "TOWARDS";
	}
	if (ans > 0) {
		cout << "LEFT";
	}
	if (ans < 0) {
		cout << "RIGHT";
	}

	return 0;
}