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

	int n, a, b, k;
	string s;
	while (cin >> n >> a >> b >> k >> s) {
		s = "1" + s + "1";
		n = s.length();

		vector<int> ans;

		int last = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == '1') last = max(i, last);
			else {
				if (i - last == b) {
					ans.push_back(i);
					//last = i + b - 1;
					last = i;
				}
			}
		}

		assert(ans.size() >= a);
		for (int i = 0; i < a - 1; i++) ans.pop_back();

		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); i++) printf("%d%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
	}

	return 0;
}