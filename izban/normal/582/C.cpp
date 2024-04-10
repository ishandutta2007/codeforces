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

const int MAXN = 1 << 18;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int n;
int a[MAXN];
int gg[MAXN];
int mx[MAXN];
int c[MAXN];

ll fastsolve() {
	for (int i = 1; i <= n; i++) gg[i] = gcd(n, i);

	bool eq = 1;
	for (int i = 0; i < n; i++) eq &= a[i] == a[0];
	if (eq) {
		//return 1LL * n * (n - 1);
	}

	ll ans = 0;
	int oo = 0;
	for (int d = 1; d <= n; d++) {
		if (n % d != 0) continue;
		oo++;
		memset(mx, -1, sizeof(mx));
		for (int i = 0; i < n; i++) mx[i % d] = max(mx[i % d], a[i]);

		for (int i = 0; i < n; i++) c[i] = a[i] == mx[i % d];

		vector<int> vct;
		
		bool all = 1;
		for (int i = 0; i < n; i++) all &= c[i] == 1;
		if (all) {
			vct.push_back(n);
		}
		else {
			int st = 0;
			while (c[st] == 1) st = (st + 1) % n;
			int ii = (st + 1) % n;
			while (ii != st) {
				if (c[ii] == 0) {
					ii = (ii + 1) % n;
					continue;
				}
				int cnt = 0;
				while (c[ii] == 1) {
					ii = (ii + 1) % n;
					cnt++;
				}
				vct.push_back(cnt);
			}
			sort(vct.begin(), vct.end());
		}

		ll sum = 0;
		int cnt = 0;
		int cur = 0;
		for (int i = 0; i < (int)vct.size(); i++) {
			sum += vct[i];
			cnt += 1;
		}

		for (int o = d; o < n; o += d) {
			if (gg[o] == d) {
				while (cur < (int)vct.size() && vct[cur] < o) {
					sum -= vct[cur];
					cnt--;
					cur++;
				}
				/*if (!(sum >= (o - 1) * 1LL * cnt)) {
					assert(0);
				}*/
				ans += sum - (o - 1) * 1LL * cnt * (vct.empty() || vct[0] != n);
			}
		}
	}

	return ans;
}

void gen() {
	n = rand() % 33 + 1;
	int O = rand() % 20 + 1;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % O + 1;
	}
}

ll slowsolve() {
	ll ans = 0;
	for (int l = 0; l < n; l++) {
		for (int s = 1; s < n; s++) {
			bool ok = 1;
			for (int i = 0; i < n * s; i++) {
				ok &= a[(l + i) % n] <= a[(l + i % s) % n];
			}
			if (ok) {
				ans++;
			}
		}
	}
	return ans;
}

void stress() {
	for (int it = 0;; it++) {
		cerr << it << endl;
		gen();
		ll ans1 = fastsolve();
		ll ans2 = slowsolve();
		if (ans1 != ans2) {
			cout << ans1 << " instead of " << ans2 << endl;
			cout << n << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
			fastsolve();
			slowsolve();
			exit(0);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//stress();

	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	/*n = 166320;
	{
		for (int i = 0; i < n; i++) a[i] = 1; a[n - 1] = 2;*/

		cout << fastsolve() << endl;
	}

	return 0;
}