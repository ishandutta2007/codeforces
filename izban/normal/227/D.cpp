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

int n, m, x, a[maxn];
ll sum[maxn], ans[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	sum[0] = a[0];
	for (int i = 1; i < n; i++)
		sum[i] = sum[i-1] + a[i];

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (!ans[x]) {
			int l = 1, k = 1;
			ll cur = x;
			while (l < n) {
				ans[x] += (sum[min(n-1LL, l+cur-1)] - sum[l-1]) * k;
				if (l + cur >= n) break;
				l += cur;
				cur *= x;
				k++;
			}
		} 
		cout << ans[x] << endl;
	}

	return 0;
}