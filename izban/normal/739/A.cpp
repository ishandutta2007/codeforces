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
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		vector<int> l(m), r(m);
		int mn = (int)(1e9);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &l[i], &r[i]);
			--l[i];
			--r[i];
			mn = min(mn, r[i] - l[i] + 1);
		}

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			a[i] = i % mn;
		}
		printf("%d\n", mn);
		for (int i = 0; i < n; i++) printf("%d%c", a[i], " \n"[i + 1 == n]);
	}

	return 0;
}