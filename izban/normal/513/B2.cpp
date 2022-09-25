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

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = 64;
const int inf = 1e9;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	ll m;
	while (cin >> n >> m) {
		m--;
		vector<int> ans(n);
		int l = 0, r = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			if (m & (1LL << i)) {
				ans[r--] = n - i - 1;
			} else {
				ans[l++] = n - i - 1;
			}
		}
		ans[l] = n;
		for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
	}

	return 0;
}