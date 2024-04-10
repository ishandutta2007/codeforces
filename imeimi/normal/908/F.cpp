#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

int n;
vector<pi> arr;
char input[100];
const int inf = 1e9 + 5;
vector<int> rs[256], gs[256];

llong getAns(char c) {
	llong ret = 0;
	int mn = inf, mx = -1;
	int lastC = -1;
	int lastG = -1;
	int mxseg;
	for (pi i : arr) {
		if (i.second == 'G') {
			if (lastG == -1 && mn != inf) {
				ret += i.first - mn;
			}
			if (lastG != -1) {
				mxseg = max(mxseg, i.first - lastC);
				rs[c].push_back(i.first - lastG - mxseg);
				gs[c].push_back(i.first - lastG);
			}
			mxseg = -1;
			lastG = i.first;
			lastC = i.first;
		}
		else if (i.second == c) {
			mx = max(mx, i.first);
			mn = min(mn, i.first);
			if (lastC != -1) {
				mxseg = max(mxseg, i.first - lastC);
			}
			lastC = i.first;
		}
	}
	if (lastG == -1 && mn != inf) {
		return mx - mn;
	}
	ret += lastC - lastG;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x >> input;
		arr.push_back(pi(x, *input));
	}
	llong ans = getAns('R') + getAns('B');
	for (int i = 0; i < rs['R'].size(); ++i) {
		ans += min(rs['R'][i] + rs['B'][i], gs['R'][i]) + gs['R'][i];
	}
	printf("%lld\n", ans);
	return 0;
}