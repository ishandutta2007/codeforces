#include <unordered_map>
#include <unordered_set>
#include <functional>
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
const int MAXN = 1 << MAXK;
const int MOD = 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	string s;
	while (cin >> s) {
		int n = s.length();
		int cur = 0;
		int ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == 'a') {
				ans = (ans + cur) % MOD;
				cur = 2LL * cur % MOD;
			}
			else {
				cur = (cur + 1) % MOD;
			}
		}
		cout << ans << endl;
	}

	return 0;
}