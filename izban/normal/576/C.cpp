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
const int K = 1000;

bool cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
	if (a.first.first / K != b.first.first / K) return a.first.first / K < b.first.first / K;
	if (a.first.first / K % 2 == 0) {
		return a.first.second < b.first.second;
	}
	else {
		return a.first.second > b.first.second;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<pair<pair<int, int>, int> > a(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].first.first, &a[i].first.second);
			a[i].second = i;
		}

		sort(a.begin(), a.end(), cmp);
		ll sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(a[i].first.first - a[i + 1].first.first) + abs(a[i].first.second - a[i + 1].first.second);
		}
		assert(sum <= 2500000000LL);
		for (int i = 0; i < n; i++) printf("%d%c", a[i].second + 1, " \n"[i + 1 == n]);
	}

	return 0;
}