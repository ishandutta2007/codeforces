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

int n, k;
int d[maxn], s[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> k) {
		for (int i = 0; i < n; i++) cin >> d[i];
		for (int i = 0; i < n; i++) cin >> s[i];

		int curCity = 0, curFuel = s[0], ans = 0, bestFuel = s[0];

		while (curCity < n) {
			if (d[curCity] <= curFuel) {
				ans += d[curCity];
				curFuel -= d[curCity];
				bestFuel = max(bestFuel, s[++curCity]);
				curFuel += s[curCity];
			} else {
				int o = (d[curCity] - curFuel) / bestFuel + ((d[curCity] - curFuel) % bestFuel > 0);
				curFuel += bestFuel * o;
				ans += k * o;
			}
		}
		cout << ans << endl;
	}

	return 0;
}