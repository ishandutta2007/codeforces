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



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	string s;
	while (cin >> n >> s) {
		int cnt = 1;
		char c = s[0];
		for (int i = 1; i < n; i++) {
			if (s[i] != c) {
				c = s[i];
				cnt++;
			}
		}
		cout << min(n, cnt + 2) << endl;
	}

	return 0;
}