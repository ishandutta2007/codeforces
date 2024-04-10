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
#include <ctime>

using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, p;
vector<int> d, h, t;

bool reading() {
	if (!(cin >> n >> m >> p)) return 0;
	d.assign(n, 0);
	h.assign(m, 0);
	t.assign(m, 0);
	for (int i = 1; i < n; i++) cin >> d[i];
	for (int i = 0; i < m; i++) cin >> h[i] >> t[i];
	return 1;
}

ll slowsolve() {
	for (int i = 1; i < n; i++) d[i] += d[i - 1];

	vector<int> e;
	for (int i = 0; i < m; i++) e.push_back(t[i] - d[h[i] - 1]);
	sort(e.begin(), e.end());
	
	vector<vector<ll> > dp(m + 1, vector<ll>(p + 1, 1e18));
	dp[0][0] = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			ll cursum = 0;
			for (int k = i; k < m; k++) {
				cursum += (k - i) * (e[k] - e[max(k - 1, 0)]);
				dp[k + 1][j + 1] = min(dp[k + 1][j + 1], dp[i][j] + cursum);
			}
		}
	}
	ll ans = 1e18;
	for (int i = 0; i <= p; i++) ans = min(ans, dp[m][i]);

	for (int i = n - 1; i; i--) d[i] -= d[i - 1];
	return ans;
}

inline ll get(pair<int, ll> v, int x) {
	return (ll)v.first * x + v.second;
}

inline double intersect(pair<int, ll> a1, pair<int, ll> a2) {
	return (double) (a2.second - a1.second) / (a1.first - a2.first);
}

ll fastsolve() {
	for (int i = 1; i < n; i++) d[i] += d[i - 1];

	vector<int> e;
	for (int i = 0; i < m; i++) e.push_back(t[i] - d[h[i] - 1]);
	sort(e.begin(), e.end());
	vector<ll> s(m, 0);
	for (int i = 0; i < m; i++) s[i] = (i ? s[i - 1] : 0) + e[i];

	vector<vector<ll> > dp(m + 1, vector<ll>(p + 1, 1e18));
	dp[0][0] = 0;

	vector<pair<int, ll> > v;
	vector<double> v1;
	for (int j = 1; j <= p; j++) {
		v.clear();
		v1.clear();
		for (int i = 0; i <= m; i++) {
			pair<int, ll> o = make_pair(-i, dp[i][j - 1] + (i ? s[i - 1] : 0));
			while (v.size() > 1) {
				double cx = intersect(v.back(), o);
				if (cx <= v1.back()) {
					v.pop_back();
					v1.pop_back();
				} else {
					v1.push_back(cx);
					break;
				}
			}
			v.push_back(o);
			if (v.size() == 2) v1.push_back(intersect(v[0], v[1]));
		}
		int k = 0;
		for (int i = 1; i <= m; i++) {
			while (k < (int)v.size() - 1 && get(v[k], e[i - 1]) >= get(v[k + 1], e[i - 1])) k++;
			dp[i][j] = get(v[k], e[i - 1]) - s[i - 1] + 1LL * i * e[i - 1];
		}
	}
	ll ans = 1e18;
	for (int i = 0; i <= p; i++) ans = min(ans, dp[m][i]);

	for (int i = n - 1; i; i--) d[i] -= d[i - 1];
	return ans;
}

int Rand(int mx) {
	int res = (rand() << 15) | rand();
	res %= mx;
	return res;
}

void gen() {
	n = 100000; //n = rand() % 4 + 1; //
	m = 100000; //m = rand() % 4 + 1; //
	p = 100; //p = rand() % 4 + 1; //
	d.assign(n, 0);
	h.assign(m, 0);
	t.assign(m, 0);
	for (int i = 1; i < n; i++) d[i] = Rand(10000) + 1;
	for (int i = 0; i < m; i++) h[i] = rand() % n + 1, t[i] = Rand(10001);
}

void stress() {
	for (int it = 0; it < 10; it++) {
		gen();
		//ll ans2 = slowsolve();
		int tm = clock();
		ll ans1 = fastsolve();
		/*if (ans1 != ans2) {
			cout << n << " " << m << " " << p << endl;
			for (int i = 1; i < n; i++) cout << d[i] << " \n"[i + 1 == n];
			for (int i = 0; i < m; i++) cout << h[i] << " " << t[i] << endl;
			cout << endl << ans1 << " instead of " << ans2 << endl << it << endl;
			break;
		}*/
		cerr << it << endl;
		cout << clock() - tm << endl;
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	if (0) stress();

	while (reading()) cout << fastsolve() << endl;

	return 0;
}