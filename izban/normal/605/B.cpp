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

int n, m;
vector<pair<pair<int, int>, int> > a(m);

vector<pair<int, int> > solve() {
	sort(a.begin(), a.end());

	vector<pair<int, int> > canUse;
	int last = 1;
	vector<pair<int, int> > ans(m);
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i].first.second == 0) {
			if (last == n) {
				return vector<pair<int, int> >();
			}
			ans[a[i].second] = make_pair(1, ++last);
			for (int j = 2; j < last; j++) {
				if (canUse.size() > m) break;
				canUse.push_back(make_pair(j, last));
			}
		}
		else {
			if (canUse.empty()) {
				return vector<pair<int, int> >();
			}
			ans[a[i].second] = canUse.back();
			canUse.pop_back();
		}
	}
	return ans;
}

void print(vector<pair<int, int> > a) {
	if (a.empty()) printf("%d\n", -1);
	else for (int i = 0; i < (int)a.size(); i++) printf("%d %d\n", a[i].first, a[i].second);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d", &n, &m) == 2) {
		a.resize(m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a[i].first.first, &a[i].first.second);
			a[i].first.second = 1 - a[i].first.second;
			a[i].second = i;
		}

		print(solve());
	}

	return 0;
}