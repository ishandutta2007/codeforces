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

int n;
ll a[maxn];
vector<int> e[maxn];
ll LCM[maxn];

ll gcd(ll a, ll b) {
	while (b) b ^= a ^= b ^= a %= b;
	return max(a, 1LL);
}

ll lcm(ll a, ll b) {
	return 1LL * a * b / gcd(a, b);
}

void dfs1(int v, int p = -1) {
	LCM[v] = 1;
	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) {
		dfs1(e[v][i], v);
		ll oldLCM = LCM[v];
		LCM[v] = lcm(oldLCM, LCM[e[v][i]]);
		if (oldLCM && LCM[v] % oldLCM || LCM[e[v][i]] && LCM[v] % LCM[e[v][i]]) LCM[v] = 0;
		a[v] += a[e[v][i]];
	}
	if (e[v].size() > 1) {
		ll oldLCM = LCM[v];
		LCM[v] *= e[v].size() - (v != 1);
		if (oldLCM && LCM[v] % oldLCM || LCM[v] % (e[v].size() - (v != 1))) LCM[v] = 0;
	}
}

ll x[maxn];

void dfs3(int v, int p = -1, ll cur = 1) {
	if (e[v].size() == 1 && v != 1) {
		x[v] = cur;
		return;
	}
	ll curlcm = LCM[v] / (e[v].size() - (v != 1));
	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) {
		dfs3(e[v][i], v, cur * (curlcm / LCM[e[v][i]]));
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		ll csum = 0;
		for (int i = 1; i <= n; i++) cin >> a[i], csum += a[i];
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1);
		if (!LCM[1]) {
			cout << a[1] << endl;
			continue;
		}
		dfs3(1);
		ll ans = 1e18;
		for (int i = 1; i <= n; i++) 
			if (x[i] != 0) 
				ans = min(ans, a[i] / x[i]);
		ll res = a[1] - ans * LCM[1];
		cout << res << endl;
	}

	return 0;
}