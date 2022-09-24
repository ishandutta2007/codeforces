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

void add1(string &s, int n) {
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '.') continue;
		if (s[i] < '9') {
			s[i]++;
			break;
		}
		s[i] = '0';
		if (i == 0) {
			s = "1" + s;
			break;
		}
		else continue;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k;
	string s;
	while (cin >> n >> k >> s) {
		string a = "", b = "";
		bool was = 0;
		string ans = "";
		for (int i = 0; i < n; i++) {
			if (s[i] == '.') {
				was = 1;
				ans += s[i];
				continue;
			}
			if (!was) {
				ans += s[i];
			}
			else {
				if (s[i] >= '5') {
					add1(ans, ans.length());
					k--;
					break;
				}
				else {
					ans += s[i];
				}
			}
		}

		int len = ans.length();
		while (k && ans[len - 1] == '5') {
			k--;
			len--;
			add1(ans, len);
		}
		if (ans[len - 1] == '.') len--;

		ans = ans.substr(0, len);
		cout << ans << endl;
	}

	return 0;
}