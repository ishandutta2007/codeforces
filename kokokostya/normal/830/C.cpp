#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		k += a[i];
		a[i]--;
	}
	set<long long> res;
	for (long long i = 1; i * 1ll * i <= k; i++) {
		res.insert(i);
		res.insert(k / i);
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, a[i]);
	}
	for (int j = 1; j * 1ll * j <= mx; j++) {
		res.insert(j);
		for (int i = 0; i < n; i++) {
			if (j * 1ll * j <= a[i])
				res.insert(a[i] / j + 1);
		}
	}
	long long ans = k / n;
	if (ans < mx + 1)
		ans = 0;
	for (auto i : res) {
		long long val = 0;
		for (int j = 0; j < n; j++)
			val += a[j] / i;
		if (k / i - n >= val)
			ans = max(ans, i);
	}
	cout << ans;
	return 0;
}