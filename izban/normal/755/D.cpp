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

struct fenwick {
	int n;
	vector<int> f;

	fenwick(int n) {
		this->n = n;
		f.assign(n, 0);
	}

	void add(int x, int y) {
		for (; x < n; x |= x + 1) f[x] += y;
	}

	int get(int x) {
		int res = 0;
		for (; x >= 0; x = (x & (x + 1)) - 1) res += f[x];
		return res;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(0);

	int n, k;
	while (cin >> n >> k) {
		if (k * 2 >= n) k = n - k;
		fenwick f(n);
		
		ll ans = 1;

		int v = 0;
		for (int i = 0; i < n; i++) {
			int u = (v + k) % n;

			// v -> u
			int l = min(u, v);
			int r = max(u, v);

			ans += 1;
			ans += f.get(max(0, l - k + 1), l - 1);
			if (l + 1 + n - (n - 1) <= k) {
				ans += f.get(l + 1 + n - k, n - 1);
			}
			ans += f.get(r - k + 1, r - 1);
			f.add(v, 1);

			v = u;
			cout << ans << " \n"[i == n - 1];
		}
	}

	return 0;
}