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



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		vector<int> p(n);
		for (int i = 0; i < n; i++) p[i] = i;
		function<int(int)> get = [&](int x) {
			if (x == p[x]) return x;
			return p[x] = get(p[x]);
		};
		int comp = n;
		auto uni = [&](int u, int v) {
			u--; v--;
			u = get(u);
			v = get(v);
			if (u == v) return 0;
			comp--;
			p[v] = u;
			return 1;
		};
		int ans = 0;
		for (int cost = 0; cost <= 1; cost++) {
			for (int i = 1; i <= n; i++) {
				int u = i;
				int v = (n + 1) + cost - u;
				if (1 <= v && v <= n) ans += uni(u, v) * cost;
			}
		}
		assert(comp == 1);
		cout << ans << endl;
	}

	return 0;
}