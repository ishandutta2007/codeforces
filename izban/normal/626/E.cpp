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

int n;
int a[MAXN];
ll sum[MAXN];


pair<ll, ll> ans;
pair<ll, ll> medans;
int ians, lans;

ll get(int l, int r) {
	if (l > r) return 0;

	ll ans = sum[r];
	if (l) ans -= sum[l - 1];
	return ans;
}

pair<ll, ll> f(int i, int len, const pair<ll, ll> &med) {
	ll sum = med.first;
	sum += get(i - len + 1, i);
	sum += get(n - len, n - 1);
	pair<ll, ll> o = make_pair(sum, len * 2 + med.second);
	if (o.second % 2 == 1 && med.second == 2) {
		o.first *= 2;
		o.second *= 2;
	}
	o.first -= med.first * (o.second / med.second);
	return o;
}

bool better(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	return a.first * b.second > b.first * a.second;
}

void solve(int i, int r, pair<ll, ll> med) {
	int l = 0;
	while (r - l >= 6) {
		pair<ll, ll> ans1 = f(i, (l + l + r) / 3, med);
		pair<ll, ll> ans2 = f(i, (l + r + r) / 3, med);
		if (better(ans1, ans2)) r = (l + r + r) / 3;
		else l = (l + l + r) / 3;
	}
	for (int x = l; x <= r; x++) {
		pair<ll, ll> ans1 = f(i, x, med);
		if (better(ans1, ans)) {
			ans = ans1;
			medans = med;
			ians = i;
			lans = x;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		
		sort(a, a + n);
		sum[0] = a[0];
		for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i];
		
		ans = make_pair(0, 1);
		ians = -1;
		lans = 0;
		medans = make_pair(a[0], 1);
		
		for (int i = 0; i < n; i++) {
			solve(i - 1, min(i, n - i - 1), make_pair(a[i], 1));
			if (i + 1 < n) solve(i - 1, min(i, n - i - 2), make_pair(a[i] + a[i + 1], 2));
		}
		
		vector<int> res;
		for (int j = 0; j < medans.second; j++) res.push_back(a[ians + 1 + j]);
		for (int j = 0; j < lans; j++) {
			res.push_back(a[ians - j]);
			res.push_back(a[n - 1 - j]);
		}
		sort(res.begin(), res.end());
		printf("%d\n", res.size());
		for (int i = 0; i < (int)res.size(); i++) printf("%d%c", res[i], " \n"[i + 1 == (int)res.size()]);
	}

	return 0;
}