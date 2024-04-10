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



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			a[i]--;
			b[a[i]] = i;
		}

		int ans = n;
		for (int i = 0; i < n; i++) {
			int cur = b[i];
			int j = i;
			while (j + 1 < n && b[j + 1] > cur) {
				cur = b[j + 1];
				j++;
			}
			ans = min(ans, n - (j - i + 1));
			i = j;
		}
		cout << ans << endl;
	}

	return 0;
}