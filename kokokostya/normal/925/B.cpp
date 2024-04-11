



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
#include <cassert>

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
	int n, x1, x2;
	cin >> n >> x1 >> x2;
	vector< pair<int, int> > c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i].first;
		c[i].second = i + 1;
	}
	sort(c.rbegin(), c.rend());
	int l = 0;
	while (l < n && c[l].first * 1ll * (l + 1) < x1) l++;

	int r = l + 1;
	while (r < n && c[r].first * 1ll * (r - l) < x2) r++;
	
	if (r < n) {
		cout << "Yes\n";
		cout << l + 1 << ' ' << r - l << '\n';
		for (int i = 0; i <= l; i++)
			cout << c[i].second << ' ';
		cout << '\n';
		for (int i = l + 1; i <= r; i++)
			cout << c[i].second << ' ';
		return 0;
	}

	swap(x1, x2);

	l = 0;
	while (l < n && c[l].first * 1ll * (l + 1) < x1) l++;

	r = l + 1;
	while (r < n && c[r].first * 1ll * (r - l) < x2) r++;

	if (r < n) {
		cout << "Yes\n";
		cout << r - l << ' ' << l + 1 << '\n';
		for (int i = l + 1; i <= r; i++)
			cout << c[i].second << ' ';
		cout << '\n';
		for (int i = 0; i <= l; i++)
			cout << c[i].second << ' ';
		return 0;
	}

	cout << "No";
	return 0;
}