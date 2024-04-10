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

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };
int ok[256];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ok['R'] = 0;
	ok['L'] = 1;
	ok['U'] = 2;
	ok['D'] = 3;

	int n;
	while (cin >> n) {
		string s;
		cin >> s;
		int cx = 0, cy = 0;
		map<pair<int, int>, int> mp;
		mp[make_pair(cx, cy)]++;
		for (int i = 0; i < n; i++) {
			int k = ok[s[i]];
			cx += dx[k];
			cy += dy[k];
			mp[make_pair(cx, cy)]++;
		}

		int ans = 0;
		for (map<pair<int, int>, int> ::iterator it = mp.begin(); it != mp.end(); it++) {
			ans += it->second * (it->second - 1) / 2;
		}
		cout << ans << endl;
	}

	return 0;
}