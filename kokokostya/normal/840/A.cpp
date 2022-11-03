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
	int m;
	cin >> m;
	vector<int> a(m), b(m);
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	vector< pair<int, int> > c(m);
	for (int i = 0; i < m; i++) {
		c[i] = { b[i], i };
	}
	sort(c.begin(), c.end());
	sort(a.begin(), a.end());
	vector<int> ans(m);
	for (int i = 0; i < m; i++) {
		ans[c[i].second] = a[m - 1 - i];
	}
	for (int i : ans)
		cout << i << ' ';
	return 0;
}