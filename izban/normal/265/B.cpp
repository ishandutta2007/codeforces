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

int n, a[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i) {
				ans += a[i - 1] - min(a[i - 1], a[i]);
				ans += 1;
				ans += a[i] - min(a[i - 1], a[i]);
				ans += 1;
			} else {
				ans += a[i];
				ans += 1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}