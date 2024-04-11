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



#include <cassert>

/** Begin fast allocation */
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new (size_t n){
	assert((mpos += n) <= MAX_MEM);
return (void *)(mem + mpos - n);
}
inline void operator delete (void *) noexcept { } // must have!
												  /** End fast allocation */

const int mod = 1000 * 1000 * 1000 + 7;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> a(n);
	vector<char> c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	vector<int> r, b, g;
	for (int i = 0; i < n; i++) {
		if (c[i] == 'G')
			g.push_back(a[i]);
		if (c[i] == 'R')
			r.push_back(a[i]);
		if (c[i] == 'B')
			b.push_back(a[i]);
	}
	if (g.empty()) {
		long long ans = 0;
		if (!r.empty())
			ans += r.back() - r[0];
		if (!b.empty())
			ans += b.back() - b[0];
		cout << ans;
		return 0;
	}
	long long ans = 0;
	int sz = g.size() - 1;
	vector< vector<int> > ab(sz);
	vector< vector<int> > ar(sz);
		int posg = 0;
	for (int i = 0; i < r.size(); i++) {
		while (posg < g.size() && r[i] > g[posg])
			posg++;
		if (posg == 0) {
			int val = g[posg] - r[i];
			if (i + 1 != r.size())
				val = min(val, r[i + 1] - r[i]);
			ans += val;
			continue;
		}
		if (posg == g.size()) {
			int val = r[i] - g.back();
			if (i)
				val = min(val, r[i] - r[i - 1]);
			ans += val;
			continue;
		}
		ar[posg - 1].push_back(r[i]);
	}
posg = 0;
	for (int i = 0; i < b.size(); i++) {
		while (posg < g.size() && b[i] > g[posg])
			posg++;
		if (posg == 0) {
			int val = g[posg] - b[i];
			if (i + 1 != b.size())
				val = min(val, b[i + 1] - b[i]);
			ans += val;
			continue;
		}
		if (posg == g.size()) {
			int val = b[i] - g.back();
			if (i)
				val = min(val, b[i] - b[i - 1]);
			ans += val;
			continue;
		}
		ab[posg - 1].push_back(b[i]);
	}

	for (int i = 0; i < sz; i++) {
		long long val = 2 * (g[i + 1] - g[i]);
		int x1 = 0, x2 = 0;
		if (ab[i].empty()) {
			x1 = g[i + 1] - g[i];
		}
		else
			x1 = max(ab[i][0] - g[i], g[i + 1] - ab[i].back());


		if (ar[i].empty()) {
			x2 = g[i + 1] - g[i];
		}
		else
			x2 = max(ar[i][0] - g[i], g[i + 1] - ar[i].back());

		for (int j = 0; j + 1 < ab[i].size(); j++)
			x1 = max(x1, ab[i][j + 1] - ab[i][j]);

		for (int j = 0; j + 1 < ar[i].size(); j++)
			x2 = max(x2, ar[i][j + 1] - ar[i][j]);

		val = min(val, 3 * 1ll * (g[i + 1] - g[i]) - x1 - x2);
		ans += val;
	}
	cout << ans;
	return 0;
}