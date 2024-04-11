





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

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, u;
	cin >> n >> u;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	double ans = -1;
	
	int pos = 0;
	for (int i = 0; i + 1 < n; i++) {
		while (pos < n && a[pos] - a[i] <= u) { pos++; }
		if (pos - 1 > i + 1)
			ans = max(ans, double(a[pos - 1] - a[i + 1]) / (a[pos - 1] - a[i]));
	}
	if (ans < 0) {
		cout << -1;
		return 0;
	}
	cout << fixed << setprecision(20) << ans;
	return 0;
}