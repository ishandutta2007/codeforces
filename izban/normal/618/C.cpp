#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const double PHI = (sqrt(5.0) - 1) / 2.0;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		vector<pair<pair<int, int>, int> > a(n);
		for (int i = 0; i < n; i++) cin >> a[i].first.first >> a[i].first.second, a[i].second = i + 1;
		sort(a.begin(), a.end());

		ll curs = 8e18;
		int best = -1;
		for (int i = 2; i < n; i++) {
			ll x1 = a[0].first.first - a[i].first.first;
			ll y1 = a[0].first.second - a[i].first.second;
			ll x2 = a[1].first.first - a[i].first.first;
			ll y2 = a[1].first.second - a[i].first.second;
			ll news = abs(x1 * y2 - x2 * y1);
			if (news < curs && news != 0) {
				best = i;
				curs = news;
			}
		}
		cout << a[0].second << " " << a[1].second << " " << a[best].second << endl;
	}

	return 0;
}