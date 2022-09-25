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

const int MAXN = 205;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

char can[MAXN][MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		memset(can, 0, sizeof(can));
		string s;
		cin >> s;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B') cnt1++;
			if (s[i] == 'G') cnt2++;
			if (s[i] == 'R') cnt3++;
		}
		can[cnt1][cnt2][cnt3] = 1;
		//for (int sum = 0; sum <= 3 * MAXN; sum++) {
		for (int sum = 3 * MAXN; sum >= 0; sum--) {
			for (int i1 = 0; i1 < MAXN; i1++) {
				for (int i2 = 0; i2 < MAXN; i2++) {
					int i3 = sum - i1 - i2;
					if (i3 < 0 || i3 >= MAXN) continue;
					if (!can[i1][i2][i3]) continue;
					if (i1 > 1) can[i1 - 1][i2][i3] = 1;
					if (i2 > 1) can[i1][i2 - 1][i3] = 1;
					if (i3 > 1) can[i1][i2][i3 - 1] = 1;
					if (i1 && i2 && i3 + 1 < MAXN) can[i1 - 1][i2 - 1][i3 + 1] = 1;
					if (i1 && i3 && i2 + 1 < MAXN) can[i1 - 1][i2 + 1][i3 - 1] = 1;
					if (i2 && i3 && i1 + 1 < MAXN) can[i1 + 1][i2 - 1][i3 - 1] = 1;
				}
			}
		}
		string ans = "";
		if (can[1][0][0]) ans += "B";
		if (can[0][1][0]) ans += "G";
		if (can[0][0][1]) ans += "R";
		cout << ans << endl;
	}

	return 0;
}