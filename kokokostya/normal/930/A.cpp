




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
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> h(n);
	vector<int> cnt(n);
	cnt[0] = 1;
	for (int i = 1; i < n; i++) {
		cin >> p[i];
		p[i]--;
		h[i] = h[p[i]] + 1;
		cnt[h[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[i] & 1)
			ans++;
	}
	cout << ans;
	return 0;
}