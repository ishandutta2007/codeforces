#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cmath>
#include <set>


using namespace std;

typedef long long ll;

const int maxn = -1;

bool isPrime(ll x) {
	for (int i = 2; 1LL * i * i <= x; i++) if (x % i == 0) return 0;
	return 1;
}

ll mul(unsigned long long a, unsigned long long b) {
	unsigned long long c = a * b;
	if (c / a != b || c > 1e18) return -1;
	return c;
}

ll fastsolve(ll a) {
	if (a == 1) {
		return 1;
	}

	vector<ll> d;
	for (int i = 1; 1LL * i * i <= a; i++) {
		if (a % i == 0) {
			d.push_back(i);
			if (1LL * i * i != a) d.push_back(a / i);
		}
	}
	sort(d.begin(), d.end());
	int m = d.size();


	vector<pair<ll, ll> > b;
	for (int i = 0; i < (int)d.size(); i++) {
		ll x = d[i];
		x--;
		if (x <= 1) continue;

		vector<ll> o;
		for (int j = 1; 1LL * j * j <= x; j++) {
			if (x % j == 0) {
				if (j != 1) o.push_back(j);
				if (1LL * j * j != x) o.push_back(x / j);
			}
		}
		sort(o.begin(), o.end());

		x = d[i] - 1;
		while (x % o[0] == 0) x /= o[0];
		if (x == 1) {
			b.push_back(make_pair(o[0], d[i]));
		}
	}

	sort(b.begin(), b.end());
	vector<vector<ll> > dp(b.size() + 1, vector<ll>(m));
	dp[0][0] = 1;
	for (int i = 0; i < (int)b.size(); i++) {
		int k = i;
		while (k < (int)b.size() && b[k].first == b[i].first) k++;
		for (int j = 0; j < m; j++) {
			if (dp[i][j] == 0) continue;
			dp[i + 1][j] += dp[i][j];
			ll x = mul(d[j], b[i].second);
			if (x == -1) continue;
			int id = lower_bound(d.begin(), d.end(), x) - d.begin();
			if (id == d.size() || d[id] != x) continue;
			dp[k][id] += dp[i][j];
		}
	}
	return dp[b.size()][m - 1];
}

ll slowsolve(ll a) {
	ll ans = 0;
	for (ll _x = 1; _x <= a; _x++) {
		vector<ll> d;
		ll x = _x;
		for (int i = 2; 1LL * i * i <= x; i++) {
			if (x % i == 0) {
				ll cur = 1;
				while (x % i == 0) {
					x /= i;
					cur *= i;
				}
				d.push_back(cur);
			}
		}
		if (x > 1) d.push_back(x);

		ll sum = 0;
		for (int mask = 0; mask < 1 << (int)d.size(); mask++) {
			ll prod = 1;
			for (int i = 0; i < (int)d.size(); i++) if (mask & (1 << i)) prod *= d[i];
			sum += prod;
		}
		ans += sum == a;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("task.in", "r", stdin);
#endif

	/*for (int i = 1; i <= 10000; i++) {
		cerr << i << endl;
		if (fastsolve(i) != slowsolve(i)) {
			cout << fastsolve(i);
			cout << " instead of " << slowsolve(i) << endl;
			cout << i << endl;
			return 0;
		}
	}*/

	ll a;
	while (cin >> a) {
		cout << fastsolve(a) << endl;
	}

	return 0;
}