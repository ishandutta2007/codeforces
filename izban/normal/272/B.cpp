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

int n, a[maxn], b[maxn];

int f(int x) {
	int ans = 0;
	while (x) {
		ans += x % 2;
		x /= 2;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n) {
		memset(b, 0, sizeof(b));
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[f(a[i])]++;
		}
		ll ans = 0;
		for (int i = 0; i < 40; i++)
			ans += 1LL * b[i] * (b[i] - 1) / 2;
		cout << ans << endl;
	}

	return 0;
}