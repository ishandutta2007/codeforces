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



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			a[i] += i;
		}

		sort(a.begin(), a.end());
		bool fail = 0;
		for (int i = 1; i < n; i++) if (a[i] == a[i - 1]) fail = 1;

		if (fail) {
			printf(":(\n");
			continue;
		}
		for (int i = 0; i < n; i++) {
			printf("%d%c", a[i] - i, " \n"[i + 1 == n]);
		}
	}

	return 0;
}