#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <assert.h>
#include <memory.h>

using namespace std;

#define ll long long


#pragma comment(linker, "/STACK:64000000")
const int maxn = 1 << 17, maxk = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
map<int, int> mp;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	while (cin >> n) {
		mp.clear();
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}

		int ans = 0;
		for (map<int, int> :: iterator it = mp.begin(); it != mp.end(); it++) if (it->first) {
			if (it->second > 2) {
				ans = -inf;
			}
			ans += it->second / 2;
		}
		cout << max(ans, -1) << endl;
	}

	return 0;
}