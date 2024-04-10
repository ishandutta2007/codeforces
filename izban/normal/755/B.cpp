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
	while (cin >> n >> m) {
		vector<string> a(n), b(m);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		map<string, char> mp;
		for (string s : b) mp[s] = 1;

		int cnt1 = n, cnt2 = m;
		int cnt0 = 0;
		for (int i = 0; i < n; i++) {
			if (mp[a[i]]) {
				cnt1--;
				cnt2--;
				cnt0++;
			}
		}

		const string YES = "YES";
		const string NO = "NO";

		string winner = "";
		if (cnt1 > cnt2) {
			winner = YES;
		}
		else {
			if (cnt1 < cnt2) {
				winner = NO;
			}
			else {
				if (cnt0 % 2 == 0) winner = NO;
				else winner = YES;
			}
		}
		cout << winner << endl;
	}

	return 0;
}