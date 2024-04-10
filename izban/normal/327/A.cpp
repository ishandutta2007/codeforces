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


int n, a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> a[i];

		int ans = 0;
		for (int l = 0; l < n; l++) {
			for (int r = l; r < n; r++) {
				for (int k = l; k <= r; k++) {
					a[k] ^= 1;
				}
				int res = 0;
				for (int k = 0; k < n; k++) res += a[k] == 1;
				for (int k = l; k <= r; k++) {
					a[k] ^= 1;
				}
				ans = max(ans, res);
			}
		}
		cout << ans << endl;
	}
	return 0;
}