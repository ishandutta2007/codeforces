
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <random>
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;
const ll md = 1e9 + 7;
mt19937 gen;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	int cl, ce, v;
	cin >> cl >> ce >> v;
	set <int> le, lf;
	while (cl--) {
		int x;
		cin >> x;
		le.insert(x - 1);
	}
	while (ce--) {
		int x;
		cin >> x;
		lf.insert(x - 1);
	}
	int q;
	cin >> q;
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;
		if (x1 < x2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		if (x1 == x2) {
			cout << abs(y1 - y2) << '\n';
		} else {
			int ans = 1e9;
			auto j = le.lower_bound(y1);
			if (j != le.end()) {
				ans = min(ans, abs(*j - y1) + abs(*j - y2) + x1 - x2);
			}
			if (j != le.begin()) {
				j--;
				ans = min(ans, abs(*j - y1) + abs(*j - y2) + x1 - x2);
			}

			j = lf.lower_bound(y1);
			if (j != lf.end()) {
				ans = min(ans, abs(*j - y1) + abs(*j - y2) + (x1 - x2 - 1) / v + 1);
			}
			if (j != lf.begin()) {
				j--;
				ans = min(ans, abs(*j - y1) + abs(*j - y2) + (x1 - x2 - 1) / v + 1);
			}
			cout << ans << '\n';
		}
	}
	

    return 0;
}