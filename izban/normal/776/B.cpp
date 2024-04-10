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
const int MAXN = 1 << 17;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

int a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		memset(a, 0, sizeof(a));
		int c = 0;
		vector<vector<int> > b(n + 2);
		vector<char> prime(n + 2, 1);
		for (int i = 2; i <= n + 1; i++) {
			for (int j = i + i; j <= n + 1; j += i) {
				prime[j] = 0;
			}
		}
		for (int i = 2; i <= n + 1; i++) {
			/*sort(b[i].begin(), b[i].end());
			if (b[i].empty()) a[i] = 1;
			else a[i] = b[i].back() + 1;
			c = max(c, a[i]);
			if (prime[i]) for (int j = i + i; j <= n + 1; j += i) b[j].push_back(a[i]);*/
			if (prime[i]) a[i] = 1;
			else a[i] = 2;
			c = max(c, a[i]);
		}
		printf("%d\n", c);
		for (int i = 2; i <= n + 1; i++) printf("%d%c", a[i], " \n"[i == n + 1]);
	}

	return 0;
}