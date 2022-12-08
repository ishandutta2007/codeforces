/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		vector<pair<ll, int>> p;
		ll x = n;
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) {
				p.push_back({ i, 0 });
				while (x % i == 0) {
					p.back().second++;
					x /= i;
				}
			}
		}
		if (x > 1)
			p.push_back({ x, 1 });
		vector<ll> ans = { n };
		ll f = 1;
		for (int i = 0; i < p[0].second; i++)
			f *= p[0].first;
		vector<ll> cur;
		while (f > 1) {
			if (f != n) {
				ans.push_back(f);
				cur.push_back(f);
			}
			f /= p[0].first;

		}
		for (int i = 1; i < p.size(); i++) {
			int sz = cur.size();
			if (p[i - 1].first * p[i].first != n) {
				ans.push_back(p[i - 1].first * p[i].first);
				cur.push_back(p[i - 1].first * p[i].first);
			}
			f = 1;
			for (int j = 0; j < p[i].second; j++) {
				f *= p[i].first;
				for (int k = 0; k < sz; k++) {
					if (cur[k] * f != p[i - 1].first * p[i].first && cur[k] * f != n) {
						ans.push_back(cur[k] * f);
						cur.push_back(cur[k] * f);
					}
				}
			}
			while (f > 1) {
				if (f != n) {
					ans.push_back(f);
					cur.push_back(f);
				}
				f /= p[i].first;
			}
		}
		int cnt = 0;
		for (int i = 0; i < ans.size(); i++) {
			if (gcd(ans[i], ans[(i + 1) % (int)(ans.size())]) == 1)
				cnt++;
		}
		for (int i : ans)
			cout << i << " ";
		cout << endl;
		cout << cnt << endl;
	}
	return;
}