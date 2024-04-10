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
#include <unordered_map>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = 100;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

char s[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int T;
	while (scanf("%d\n", &T) == 1) {
		unordered_map<ll, int> mp;
		while (T--) {
			char c;
			scanf("%c %s\n", &c, s);
			int n = strlen(s);
			ll cmask = 0;
			ll ans = 0;
			for (int i = n - 1; i >= 0; i--) {
				//ll oldmask = cmask;
				//if (cmask == -1) cmask = 0;
				cmask += ((ll)((s[i] - '0') % 2 == 1)) << (n - 1 - i);
				//if (cmask == oldmask) continue;
			}
			if (c == '+') {
				mp[cmask]++;
			}
			if (c == '-') {
				mp[cmask]--;
			}
			if (c == '?') {
				ans += mp[cmask];
			}
			if (c == '?') {
				printf("%I64d\n", ans);
			}
		}
	}

	return 0;
}