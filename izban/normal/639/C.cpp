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
const int INF = (int)(1e9);

int sign(ll x) {
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

vector<int> getB(vector<int> a, int n, int &s) {
	vector<int> b(a.size() + 40);
	for (int i = 0; i < (int)a.size(); i++) {
		int x = a[i];
		int j = i;
		while (x) {
			b[j] += x % 2;
			x /= 2;
			j++;
		}
	}

	for (int j = 0; j < (int)b.size(); j++) {
		if (b[j]) {
			b[j + 1] += b[j] / 2;
			b[j] %= 2;
		}
	}
	int mx = -1;
	for (int j = 0; j < (int)b.size(); j++) if (b[j] != 0) mx = j;

	if (mx == -1) {
		s = 0;
		return vector<int>(a.size(), 0);
	}

	s = 1;
	if (b[mx] == -1) {
		s = -1;
		for (int i = 0; i < (int)b.size(); i++) b[i] *= -1;
	}

	for (int i = 0; i < (int)b.size(); i++) {
		b[i + 1] += b[i] / 2;
		b[i] %= 2;
		if (b[i] == -1) {
			b[i] = 1;
			b[i + 1] += -1;
		}
	}

	return b;
}

int fastsolve(vector<int> a, int n, int k) {
	for (int i = 0; i < 40; i++) a.push_back(0);

	ll cur = 0;
	int mn = INF, mx = -INF;
	
	int s;
	vector<int> b = getB(a, n, s);
	for (int i = 0; i < (int)b.size(); i++) {
		if (b[i] == 1) {
			mn = min(mn, i);
			mx = max(mx, i);
		}
	}

	if (mx - mn > 35) {
		return 0;
	}

	cur = 0;
	for (int i = mx; i >= mn; i--) {
		cur *= 2;
		if (i != mn) cur += b[i];
	}
	cur *= s;

	int ans = 0;
	for (int i = mn; i >= 0; i--) {
		cur += b[i] * s;
		if (abs(cur) > 2LL * k) {
			break;
		}
		ans += i <= n && abs(cur - a[i]) <= k && (i != n || abs(cur - a[i]) != 0);
		cur *= 2;
	}

	return ans;
}

int slowsolve(vector<int> a, int n, int k) {
	for (int i = 0; i < 40; i++) a.push_back(0);

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		vector<int> na = a;
		for (int j = -k; j <= k; j++) {
			na[i] = j;
			if (i == n && j == 0) continue;
			int s;
			getB(na, n, s);
			if (s == 0) {
				ans++;
				getB(na, n, s);
			}
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	/*
	for (int it = 0;; it++) {
		int n = rand() % 10 + 1;
		int k = rand() % 30 + 1;
		vector<int> a;
		for (int i = 0; i <= n; i++) {
			a.push_back(rand() % (2 * k + 1) - k);
		}
		while (a.back() == 0) {
			a.back() = rand() % (2 * k + 1) - k;
		}
		int s;
		getB(a, n, s);
		if (s == 0) continue;
		cerr << it << endl;
		int ans1 = fastsolve(a, n, k);
		int ans2 = slowsolve(a, n, k);
		if (ans1 != ans2) {
			cout << ans1 << " instead of " << ans2 << endl;
			cout << n << " " << k << endl;
			for (int i = 0; i <= n; i++) cout << a[i] << " \n"[i == n];


			getB(a, n, s);
			fastsolve(a, n, k);
			slowsolve(a, n, k);
			exit(0);
		}
	}
	*/
	int n, k;
	while (scanf("%d%d", &n, &k) == 2) {
		vector<int> a(n + 1);
		for (int i = 0; i <= n; i++) scanf("%d", &a[i]);

		printf("%d\n", fastsolve(a, n, k));
	}

	return 0;
}