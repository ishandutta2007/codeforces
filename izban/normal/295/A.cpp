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
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, k;
vector<int> a, l, r, d, x, y;
vector<int> cnt;
vector<ll> add;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//scanf("%d%d%d", &n, &m, &k);
	while (cin >> n >> m >> k) {
		a.resize(n);
		l.resize(m); r.resize(m); d.resize(m);
		x.resize(k); y.resize(k);
		cnt.assign(m + 1, 0);
		add.assign(n + 1, 0);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < m; i++) scanf("%d%d%d", &l[i], &r[i], &d[i]);
		for (int i = 0; i < k; i++) scanf("%d%d", &x[i], &y[i]);

		for (int i = 0; i < k; i++) {
			cnt[--x[i]]++;
			cnt[y[i]]--;
		}
		for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];

		for (int i = 0; i < m; i++) {
			add[--l[i]] += 1LL * d[i] * cnt[i];
			add[r[i]] -= 1LL * d[i] * cnt[i];
		}
		for (int i = 1; i <= n; i++) add[i] += add[i - 1];

		for (int i = 0; i < n; i++) cout << a[i] + add[i] << " \n"[i + 1 == n];
	}
	return 0;
}