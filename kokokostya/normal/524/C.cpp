



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

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const int INF = 1e9;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	map<int, int> cost;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (cost.find(a[i] * j) == cost.end())
				cost[a[i] * j] = j;
			else
				cost[a[i] * j] = min(j, cost[a[i] * j]);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		int ans = INF;
		for (auto j : cost) {
			if (cost.find(x - j.first) != cost.end())
				ans = min(ans, j.second + cost[x - j.first]);
		}
		if (ans > k)
			ans = -1;
		cout << ans << '\n';
	}
	return 0;
}