




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



pair<int, int> rt(pair<int, int> a) {
	return make_pair(a.first - a.second, a.first + a.second);
}

const int MX = 5e5;

long long solve(vector< pair<int, int> > a, int val) {
	int n = (int)a.size();
	for (int i = 0; i < n; i++) {
		a[i] = rt(a[i]);
		a[i].first += MX / 2;
		a[i].second += MX / 2;
	}
	long long res = 0;
	vector<int> l(MX, MX), r(MX, -MX);
	for (int i = 0; i < n; i++) {
		l[a[i].first + 1] = min(l[a[i].first + 1], a[i].second + 1);
		r[a[i].first - 1] = max(r[a[i].first - 1], a[i].second - 1);
	}
	for (int i = 1; i < MX; i++)
		l[i] = min(l[i], l[i - 1]);
	for (int i = MX - 2; i >= 0; i--)
		r[i] = max(r[i], r[i + 1]);


	vector<int> ll(MX, MX), rr(MX, -MX);
	for (int i = 0; i < n; i++) {
		ll[a[i].first - 1] = min(ll[a[i].first - 1], a[i].second + 1);
		rr[a[i].first + 1] = max(rr[a[i].first + 1], a[i].second - 1);
	}
	for (int i = 1; i < MX; i++)
		rr[i] = max(rr[i], rr[i - 1]);
	for (int i = MX - 2; i >= 0; i--)
		ll[i] = min(ll[i], ll[i + 1]);

	long long ans = 0;
	for (int i = 0; i < MX; i++) {
		if (i % 2 == val) {
			int l1 = max(l[i], ll[i]);
			int r1 = min(r[i], rr[i]);
			if (l1 <= r1)
				ans += (r1 - l1 + 2) / 2;
		}
	}
	return ans;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector< pair<int, int> > a(n);

	vector< pair<int, int> > b, c;
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	for (int i = 0; i < n; i++) {
		if ((a[i].first + a[i].second) % 2 == 0) {
			b.push_back(a[i]);
		}
		else
			c.push_back(a[i]);
	}
	long long ans = solve(b, 1) + solve(c, 0);
	cout << ans;
	return 0;
}