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

const int MAXK = -1;
const int MAXN = 1 << 20;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<pair<pair<int, int>, pair<int, int> > > a(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second.first, &a[i].second.second);
			if (a[i].first.first > a[i].second.first) swap(a[i].first.first, a[i].second.first);
			if (a[i].first.second > a[i].second.second) swap(a[i].first.second, a[i].second.second);
		}
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			int x = (abs(a[i].second.first) % 2) + (abs(a[i].second.second) % 2) * 2;
			printf("%d\n", x + 1);
		}
	}
	
	return 0;
}