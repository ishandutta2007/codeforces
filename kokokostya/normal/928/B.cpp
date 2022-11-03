
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
const ll md = 1e9 + 7;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	vector<int> a(n), ans(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {
			ans[i] = min(i + k, n - 1) - max(i - k, 0) + 1;
		} else {
			int mr = min(i + k, n - 1), ml = min(max(max(i - k, a[i] + k + 1), 0), n);
			ans[i] = mr - ml + 1 + ans[a[i]];
		}
		cout << ans[i] << ' ';
	}

    return 0;
}