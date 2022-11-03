





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

const int MX = 10001;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector<int> gd, bd;
	for (int i = 0; i < n; i++)
		if (b[i] == 1) {
			gd.push_back(a[i]);
		}
		else {
			bd.push_back(a[i]);
		}

	bitset<MX> can;
	can[0] = 1;
	for (int i : bd) {
		can |= (can << i);
	}

	sort(gd.rbegin(), gd.rend());
	int m = gd.size();
	vector< bitset<MX> > knap(m + 1);
	knap[0][0] = 1;
	for (int i = 0; i < m; i++) {
		knap[i + 1] = knap[i] | (knap[i] << gd[i]);
	}

	int sumb = 0;
	for (int i : bd)
		sumb += i;

	vector< pair<int, int> > ask;
	int ans = m;


	int suma = sumb;
	for (int i : gd)
		suma += i;

	for (int i = 0; i < MX; i++) {
		if (can[i]) {
			int zl = i, zr = suma - (sumb - i);

			int nl = max(0, l - zl);
			int nr = max(1, zr - r);
			ask.push_back({ nl, nr });
		
		}
	}
	vector<int> pr(m + 1, 0);
	for (int i = 0; i < m; i++) {
		pr[i + 1] = pr[i] + gd[i];
	}

	int pos = 0;
	while (ans > 0 && pos < ask.size()) {
		int l = ask[pos].first, r = pr[ans] - ask[pos].second;
		if (l > r) {
			pos++;
			continue;
		}

		if (((knap[ans] >> l) << (MX - r - 1 + l)).count()) {
			ans--;
		}
		else {
			pos++;
		}
	}

	ans++;
	cout << m - ans + 1;
	return 0;
}