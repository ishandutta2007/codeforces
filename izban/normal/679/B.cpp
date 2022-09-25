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

int f(ll x, bool print = 0) {
	int ans = 0;
	while (x) {
		ll y = 0;
		while ((y + 1) * (y + 1) * (y + 1) <= x) y++;
		x -= y * y * y;
		ans++;
		//if (print) cout << y << " ";
	}
	//if (ans == 1) cout << endl;
	return ans;
}

ll slowsolve(ll n) {
	int last = -1;
	ll plast = -1;
	for (ll i = 1; i <= n; i++) {
		ll x = f(i);
		if (x >= last) {
			last = x;
			plast = i;
		}
	}
	return plast;
}

ll pow3(ll x) {
	return x * x * x;
}

pair<int, ll> rec(ll x) {
	if (x <= 7) {
		return make_pair(x, x);
	}
	ll y = pow(x, 1.0 / 3);
	while (pow3(y) > x) y--;
	while (pow3(y + 1) <= x) y++;

	pair<int, ll> res1 = rec(x - pow3(y));
	res1.second += pow3(y);
	res1.first++;
	pair<int, ll> res2 = rec(min(x, pow3(y) - 1) - pow3(y - 1));
	res2.second += pow3(y - 1);
	res2.first++;
	return max(res1, res2);
}

ll fastsolve(ll x) {
	pair<int, ll> ans = rec(x);
	return ans.second;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	/*
	for (int i = 1; i <= 1e6; i++) {
		if (i % 1000 == 0) cerr << i << endl;
		if (slowsolve(i) != fastsolve(i)) {
			cout << i << endl;
			cout << fastsolve(i) << " " << f(fastsolve(i));
			cout << " instead of ";
			cout << slowsolve(i) << " " << f(slowsolve(i)) << endl;
			cout << "ERROR" << endl;
			return 0;
		}
	}
	*/
	ll n;
	while (cin >> n) {
		ll ans = fastsolve(n);
		cout << f(ans) << " " << ans << endl;
	}
	return 0;
	/*
	int plast = -1, last = -1;
	int mx = -1;
	for (int i = 1; i <= 1000000; i++) {
		ll x = f(i);
		if (x >= last) {
			f(i, 1);
			cout << endl;
			//cout << i << " " << f(i) << " " << i - plast << endl;
			mx = max(mx, i - plast);
			last = x;
			plast = i;
		}
	}
	cout << mx << endl;
	*/
	return 0;
}