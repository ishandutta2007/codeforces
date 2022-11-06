#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;
typedef long long llong;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

int phi(int x) {
	int ret = 1;
	for (int i = 2; (llong)i * i <= x; ++i) {
		if (x % i != 0) continue;
		x /= i;
		while (x % i == 0) x /= i, ret *= i;
		ret = ret * (i - 1);
	}
	if (x > 1) return ret * (x - 1);
	return ret;
}

int n, m;
int arr[100001];
vector<int> ps;

int pow(int x, int p, int mod) {
	if (p == 0) return 1;
	if (p == 1)	return x % mod;
	int ret = pow(x, p >> 1, mod);
	ret = (llong)ret * ret % mod;
	if (p & 1) ret = (llong)ret * x % mod;
	return ret;
}

int query(int l, int r, int mi) {
	if (l > r) return 1;
	if (ps[mi] == 2) return arr[l] % 2;
	if (r - l + 1 <= 3) {
		int ans = 1;
		if (r - l + 1 == 1) return arr[l] % ps[mi];
		if (r - l + 1 == 2)	return pow(arr[l], arr[r], ps[mi]);
		if (r - l + 1 == 3) {
			int ans = 1;
			for (int i = 0; i < arr[r]; ++i) {
				ans *= arr[r - 1];
				if (ans > 30) {
					int ms = ps[mi + 1];
					while (ms < 30) ms += ps[mi + 1];
					return pow(arr[l], query(l + 1, r, mi + 1) + ms, ps[mi]);
				}
			}
			return pow(arr[l], ans, ps[mi]);
		}
	}
	int ms = ps[mi + 1];
	while (ms < 30) ms += ps[mi + 1];
	return pow(arr[l], query(l + 1, r, mi + 1) + ms, ps[mi]);
}

bool sparse[100001][20];

void init() {
	for (int i = 1; i <= n; ++i) sparse[i][0] = (arr[i] == 1);
	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j <= n; ++j) {
			sparse[j][i] = sparse[j][i - 1];
			int k = j + (1 << (i - 1));
			if (k <= n) sparse[j][i] = sparse[j][i] || sparse[k][i - 1];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	ps.push_back(m);
	while ((m = phi(m)) > 1) {
		ps.push_back(m);
	}
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	init();

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (ps[0] == 1) printf("0\n");
		else {
			int p = l;
			for (int i = 20; i--;) {
				if (!sparse[p][i]) p += (1 << i);
				if (p > r) break;
			}
			printf("%d\n", query(l, min(r, p - 1), 0));
		}
	}

	return 0;
}