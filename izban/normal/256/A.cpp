#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 12, maxk = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int a[maxn];
int len[maxk], last[maxk], cnt[maxk];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		memset(cnt, 0, sizeof(cnt));
		int ans = 0;
		for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) last[a[j]] = -1, len[a[j]] = 0;
			last[a[i]] = -1;
			for (int j = 0; j < n; j++) {
				if (a[i] != a[j]) {
					len[a[j]] += 2 * (last[a[i]] > last[a[j]]);
				}
				last[a[j]] = j;
			}
			for (int j = 0; j < n; j++) if (j != i) ans = max(ans, len[a[j]] + (last[a[i]] > last[a[j]]));
			ans = max(ans, cnt[a[i]]);
		}
		cout << ans << endl;
	}

	return 0;
}