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

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = 1 << 18;
const int inf = 1e9;

int n;
pair<int, int> a[maxn], b[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
			b[i] = make_pair(a[i].first + a[i].second, a[i].first - a[i].second);
		}
		sort(b, b + n);

		int last = -2e9;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (b[i].second >= last) {
				ans++;
				last = b[i].first;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}