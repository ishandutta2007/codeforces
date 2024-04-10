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

const int maxn = 1 << 21;
const int inf = 1000000007;
const int mod = 1000000007;

int n, l, t, a[maxn];

int f(int x) {
	if (x < 0) x += l;
	return x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> l >> t) {
		l *= 2; t *= 2;
		for (int i = 0; i < n; i++) cin >> a[i], a[i] *= 2, a[i + n] = a[i];
	
		double ans = (t / (l / 2)) * (1LL * n * (n - 1) / 4.0);
		t -= (l / 2) * (t / (l / 2));
		if (t / (l / 2) % 2 == 1) {
			for (int i = 0; i < n; i++) a[i] = (a[i] + l / 2) % l;
		}
		sort(a, a + n);

		int cur = 1;
		for (int i = 0; i < n; i++) {
			while (f(a[cur] - a[i]) <= t * 2 && f(a[cur] - a[i]) > 0 || f(a[cur] - a[i]) == 0 && cur == i) cur++;
			ans += (cur - i - 1) / 4.0;
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}