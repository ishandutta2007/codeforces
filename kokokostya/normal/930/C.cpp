




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
#include <cstring>
#include <random>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const int INF = 1e9;

vector<int> get(vector<int> a) {
	int m = a.size();
	vector<int> dp(m + 1, INF);
	vector<int> res(m);
	for (int i = 0; i < m; i++) {
		int l = -1, r = m;
		while (r - l > 1) {
			int md = (l + r) / 2;
			if (dp[md] <= a[i])
				l = md;
			else
				r = md;
		}
		dp[l + 1] = a[i];
		res[i] = l + 2;
	}
	return res;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		a[l]++;
		if(r + 1 < m)
		a[r + 1]--;
	}
	for (int i = 1; i < m; i++) {
		a[i] += a[i - 1];
	}
	vector<int> ll = get(a);
	reverse(a.begin(), a.end());
	vector<int> rr = get(a);
	reverse(rr.begin(), rr.end());
	reverse(a.begin(), a.end());
	int ans = 0;
	for (int i = 1; i < m; i++)
		ll[i] = max(ll[i - 1], ll[i]);

	for (int i = m - 2; i >= 0; i--)
		rr[i] = max(rr[i + 1], rr[i]);

	for (int i = 0; i + 1 < m; i++) {
		ans = max(ans, ll[i] + rr[i + 1]);
	}
	ans = max(ans, rr[0]);
	ans = max(ans, ll[m - 1]);
	cout << ans;
	return 0;
}