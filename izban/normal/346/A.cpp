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
const string ans[2] = {"Bob", "Alice"};

int n, a[maxn];

int gcd(int a, int b) {
	while (b) b ^= a ^= b ^= a %= b;
	return a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		int g = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			g = gcd(g, a[i]);
		}
		for (int i = 0; i < n; i++) a[i] /= g;
		sort(a, a + n);
		cout << ans[(a[n - 1] - n) % 2] << endl;
	}

	return 0;
}