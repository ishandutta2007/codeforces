



#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const int mod = 1000 * 1000 * 1000 + 7;
const int MX = 1007;
int c[MX][MX];

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	int k;
	cin >> k;
	if (k == 0) {
		cout << 1;
		return 0;
	}
	vector<int> a(MX);
	c[0][0] = 1;
	for (int i = 0; i < MX; i++) {
		c[i][0] = 1;
	}
	for (int i = 1; i < MX; i++)
		for (int j = 0; j <= i; j++) {
			c[i][j] = c[i - 1][j];
			if (j)
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}

	for (int i = 2; i < MX; i++) {
		int d = 0;
		int now = i;
		while (now) {
			if (now & 1)
				d++;
			now >>= 1;
		}
		a[i] = a[d] + 1;
	}
	long long ans = 0;
	for (int i = 1; i < MX; i++) {
		if (a[i] + 1 == k) {
			int cnt = 0;
			for (int j = 0; j <= (int)s.length(); j++) {
				if (j == s.length()) {
					if (i - cnt == 0)
						ans = (ans + 1) % mod;
				}
				else {
					if (s[j] == '1') {
					    if(i - cnt >= 0)
						ans = (ans + c[s.length() - 1 - j][i - cnt]) % mod;
						cnt++;
					}
				}
			}
		}
	}
	if (k == 1)
		ans = (ans - 1 + mod) % mod;
cout << ans;
	
	return 0;
}