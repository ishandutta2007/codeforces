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

int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	if (n <= 2) {
		cout << -1;
	} else if (n == 3) {
		cout << 210;
	} else {
		int o = 1;
		for (int i = 1; i < n; i++)
			o = o * 10 % 210;
		cout << 1;
		for (int i = 0; i < n - 4; i++)
			cout << 0;
		printf("%03d", 210 - o);
	}

	return 0;
}