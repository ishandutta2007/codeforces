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
const int MAXN = 1 << 18;
const int MOD = 1000 * 1000 * 1000 + 7;

int fct[MAXN];
int ofct[MAXN];

int bin(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1) res = 1LL * res * a % MOD;
		a = 1LL * a * a % MOD;
		n >>= 1;
	}
	return res;
}

int inv(int x) {
	return bin(x, MOD - 2);
}

int getC(int n, int k) {
	return 1LL * fct[n] * ofct[k] % MOD * ofct[n - k] % MOD;
}

int partitions(ll n, int k) {
	if (n == 0 && k == 0) return 1;
	if (k <= 0) return 0;
	if (n < 0) return 0;
	return getC(n + k - 1, n);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	fct[0] = 1;
	for (int i = 1; i < MAXN; i++) fct[i] = 1LL * fct[i - 1] * i % MOD;
	ofct[MAXN - 1] = inv(fct[MAXN - 1]);
	for (int i = MAXN - 2; i >= 0; i--) ofct[i] = 1LL * ofct[i + 1] * (i + 1) % MOD;

	int f, w, h;
	while (cin >> f >> w >> h) {
		vector<int> f1(f + 1);
		for (int i = 0; i <= f; i++) {
			f1[i] = partitions(f - i, i);
		}
		vector<int> w1(w + 1);
		for (int i = 0; i <= w; i++) {
			w1[i] = partitions(w - i, i);
		}
		vector<int> w2(w + 1);
		for (int i = 0; i <= w; i++) {
			w2[i] = partitions(w - 1LL * (h + 1) * i, i);
		}

		auto ways = [&](vector<int> a, vector<int> b) {
			int ans = 0;
			for (int i = 0; i < (int)a.size(); i++) {
				for (int j = i - 1; j <= i + 1; j++) {
					if (j >= 0 && j < (int)b.size()) {
						ans = (ans + 1LL * a[i] * b[j] * (i == j ? 2 : 1)) % MOD;
					}
				}
			}
			return ans;
		};

		int a1 = ways(f1, w1);
		int a2 = ways(f1, w2);

		cout << 1LL * a2 * inv(a1) % MOD << endl;
	}


	return 0;
}