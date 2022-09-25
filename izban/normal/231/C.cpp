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

int n, k, a[maxn], ans = -1, rans = -1;
ll s[maxn];

bool f(int l, int r) {
	ll sum = s[r] - (l ? s[l - 1] : 0);
	return 1LL * a[r] * (r - l + 1) - sum <= k;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	s[0] = a[0];
	for (int i = 1; i < n; i++)
		s[i] = s[i-1] + a[i];

	for (int i = 0; i < n; i++) {
		int l = 0, r = i;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (f(m, i))
				r = m;
			else
				l = m;
		}
		int cans = -1;
		if (f(l, i)) 
			cans = l;
		else
			cans = r;

		if (i - cans + 1 > ans) {
			ans = i - cans + 1;
			rans = a[i];
		}
	}

	cout << ans << " " << rans;

	return 0;
}