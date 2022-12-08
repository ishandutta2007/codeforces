#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
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

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


#pragma GCC optimize("O3") //  ,   



using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const ld eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
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

const int N = 1e7 + 7;
const int C = 1e7 + 1;

pair<int, int> p[C];
int a[N];

void relax(int i, int t) {
	pair<int, int> kek = p[i];
	if (kek.first == -1) p[i].first = t;
	else if (a[kek.first] >= a[t]) p[i] = { t, kek.first };
	else if (kek.second == -1) p[i].second = t;
	else if (a[kek.second] > a[t]) p[i].second = t;
}

int pr[N];
int lp[C];
int sz = 0;

void buildSieve() {
	fill(lp, lp + C, 0);
	fill(pr, pr + N, 0);
	for (int i = 2; i < C; i++) {
		if (!lp[i]) {
			pr[sz++] = i;
			lp[i] = i;
		}
		ll f = 0;
		if(sz)
		f = i * 1ll * pr[0];
		for (int j = 0; j < sz && pr[j] <= lp[i] && (f < C); j++, f = i * 1ll * pr[j])
			lp[f] = pr[j];
	}
}

int kek[N];
pair<int, int> fac[N];

int cc = 0;
int cf = 0;

void foo(int id = 0, ll cur = 1) {
	if (id == cf) {
		kek[cc++] = cur;
	}
	else {
		ll t = 1;
		for (int j = 0; j <= fac[id].second; j++) {
			foo(id + 1, cur * t);
			t *= fac[id].first;
		}
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < C; i++)
		p[i] = { -1, -1 };
	buildSieve();
	for (int i = 0; i < n; i++) {
		int x = a[i];
		cf = 0;
		while (x != 1) {
			if (!cf || fac[cf - 1].first != lp[x]) {
				fac[cf++] = { lp[x], 1 };
			}
			else {
				fac[cf - 1].second++;
			}
			x /= lp[x];
		}
		cc = 0;
		foo();
		for (int j = 0; j < cc; j++) {
			relax(kek[j], i);
		}
	}
	ll ans = inf;
	pair<int, int> x;
	for (int i = 1; i < C; i++) {
		if (p[i].second == -1) continue;
		ll c = a[p[i].first] * 1ll * a[p[i].second] / (ll)i;
		if (c < ans) {
			ans = c;
			x = p[i];
		}
	}
	if (x.first > x.second) swap(x.first, x.second);
	cout << x.first + 1 << " " << x.second + 1  << endl;
	return;
}