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

int n, m;
ll h[maxn], p[maxn];

bool g(ll X, ll x, ll l, ll r) {
	return X >= min(abs(l - x), abs(r - x)) + r - l;
}

bool f(ll x) {
	int curl = -1;
	for (int i = 0; i < n; i++) {
		int curr = curl;
		while (curr < m - 1 && g(x, h[i], p[curl + 1], p[curr + 1])) curr++;
		curl = curr;
	}
	return curl == m - 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) cin >> h[i];
		for (int i = 0; i < m; i++) cin >> p[i];
		ll l = 0, r = 1e11;
		while (r - l > 1) {
			ll M = (l + r) >> 1;
			if (f(M)) r = M;
			else l = M;
		}
		if (f(l)) cout << l << endl;
		else if (f(r)) cout << r << endl;
		else cout << -1 << endl;
	}

	return 0;
}