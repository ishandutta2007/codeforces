


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

const int MX = 1e6 + 1;
int val[MX];

int f(int v) {
	int res = 1;
	while (v) {
		if(v % 10)
			res *= v % 10;
		v /= 10;
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
	int q;
	cin >> q;
	for (int i = 0; i < 10; i++)
		val[i] = i;
	for (int i = 10; i < MX; i++) {
		val[i] = val[f(i)];
	}
	vector<int> a[10];
	for (int i = 0; i < 10; i++)
		a[i].push_back(-1);
	for (int i = 0; i < MX; i++)
		a[val[i]].push_back(i);
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		auto ll = lower_bound(a[k].begin(), a[k].end(), l);
		auto rr = upper_bound(a[k].begin(), a[k].end(), r);
		cout << rr - ll << '\n';
	}
	
	return 0;
}