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
#include <functional>

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

	int n;
	while (cin >> n) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
		}

		vector<int> p(n);
		for (int i = 0; i < n; i++) p[i] = i;

		function<int(int)> get = [&](int x) {
			if (x == p[x]) return x;
			return p[x] = get(p[x]);
		};
		auto uni = [&](int u, int v) {
			u = get(u);
			v = get(v);
			if (u == v) return;
			p[v] = u;
		};

		for (int i = 0; i < n; i++) {
			uni(i, a[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++) ans += p[i] == i;

		cout << ans << endl;
	}

	return 0;
}