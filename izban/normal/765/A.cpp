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
const int MOD = 0; // 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		string h;
		cin >> h;
		map<string, int> mp;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			string c1 = s.substr(0, 3);
			string c2 = s.substr(5, 3);
			mp[c1]++;
			mp[c2]++;
		}

		string ans = "home";
		for (auto it : mp) {
			if (it.first != h && it.second % 2 == 1) {
				ans = "contest";
			}
		}
		cout << ans << endl;
	}

	return 0;
}