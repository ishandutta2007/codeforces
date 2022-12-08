#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
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

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;

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

ll mul(ll a, ll b) {
	if (b == 0) return 0;
	if (mod / b <= a) {
		a = (a * b) % mod;
	}
	else {
		a = a * b;
	}
	return a;
}

ll add(ll a, ll b) {
	if (a + b < 0) return a + b + mod;
	else if (a + b >= mod) return a + b - mod;
	return a + b;
}

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		k >>= 1;
	}
	return res;
}

void solve() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<pair<int, pair<int, int>>> p(n * m);
	vector<int> f(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			p[m * i + j] = { a[i][j], {i, j} };
		}
	}
	int r, c; cin >> r >> c; r--; c--;
	int g = n * m;
	sort(all(p));
	vector<int> l(g);
	l[0] = -1;
	f[g - 1] = g;
	for (int i = g - 2; i >= 0; i--) {
		if (p[i].first == p[i + 1].first) f[i] = f[i + 1];
		else f[i] = i + 1;
	}
	for (int i = 1; i < g; i++) {
		if (p[i].first == p[i - 1].first) l[i] = l[i - 1];
		else l[i] = i - 1;
	}
	vector<ll> t1(g), t2(g), t3(g), t4(g), t5(g);
	vector<ll> ans(n * m);
	ll c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
	ll gl = 0;
	for (int i = 0; i < g; i++) {
		c1 = add(c1, t1[i]);
		c2 = add(c2, t2[i]);
		c3 = add(c3, t3[i]); 
		c4 = add(c4, t4[i]);
		c5 = add(c5, t5[i]);
		ll t = bp(l[i] + 1, mod - 2);
		ans[i] = add(ans[i], mul(c1, t));
		ans[i] = add(ans[i], mul(mul(c2, p[i].second.first), t));
		ans[i] = add(ans[i], mul(mul(c3, p[i].second.first * p[i].second.first),t ));
		ans[i] = add(ans[i], mul(mul(c4, p[i].second.second), t));
		ans[i] = add(ans[i], mul(mul(c5, p[i].second.second * p[i].second.second), t));
		if (f[i] != g) {
			ll t = 1;
			//cout << i << " " << f[i] << " LOL\n";
			t1[f[i]] = add(t1[f[i]], mul(add(ans[i], add(p[i].second.first * p[i].second.first, p[i].second.second * p[i].second.second)), t));
			t2[f[i]] = add(t2[f[i]], mul(add(0, -2 * p[i].second.first), t));
			t3[f[i]] = add(t3[f[i]], t);
			t4[f[i]] = add(t4[f[i]], mul(add(0, -2 * p[i].second.second), t));
			t5[f[i]] = add(t5[f[i]], t);
		}
		if (p[i].second == mp(r, c))
			gl = ans[i];
	}
	gl %= mod;
	cout << gl << endl;
	return;
}