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

int n, m, x, y, a, b;

int gcd(int a, int b) {
	while (b) b ^= a ^= b ^= a %= b;
	return a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> m >> x >> y >> a >> b) {
		int g = gcd(a, b);
		a /= g; b /= g;
		int k = min(n / a, m / b);
		int dx = k * a, dy = k * b;
		int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

		if (n - x <= dx / 2) {
			x2 = n;
			x1 = n - dx;
		} else if (x <= dx / 2) {
			x1 = 0;
			x2 = dx;
		} else {
			x1 = x - dx / 2 - dx % 2;
			x2 = x + dx / 2;
		}

		if (m - y <= dy / 2) {
			y2 = m;
			y1 = m - dy;
		} else if (y <= dy / 2) {
			y1 = 0;
			y2 = dy;
		} else {
			y1 = y - dy / 2 - dy % 2;
			y2 = y + dy / 2;
		}

		cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	}

	return 0;
}