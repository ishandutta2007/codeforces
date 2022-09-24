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
const int MOD = 0; // 1000 * 1000 * 1000 + 7;
const int INF = 1.01e9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	int n, t, k, d;
	while (cin >> n >> t >> k >> d) {
		int t1, t2;
		vector<int> a;

		int cur = 0;
		while (a.size() < n) {
			cur += t;
			for (int i = 0; i < k; i++) a.push_back(cur);
		}

		vector<int> b;
		cur = d;
		while (b.size() < n) {
			cur += t;
			for (int i = 0; i < k; i++) b.push_back(cur);
		}

		int ans1 = a[n - 1];
		for (int x : b) a.push_back(x);
		sort(a.begin(), a.end());
		int ans2 = a[n - 1];

		string ans = "NO";
		if (ans1 != ans2) {
			assert(ans1 > ans2);
			ans = "YES";
		}
		cout << ans << endl;
	}

	return 0;
}