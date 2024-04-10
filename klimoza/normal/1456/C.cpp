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

//#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
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

const int N = 5e5 + 2;

int n;
vector<ll> a;

pair<ll, ll> get(ll maxC) {
	ll ans = 0;
	ll cnt = 0;
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur < maxC) {
			cnt++;
			cur = 0;
		}
		if (maxC == -7)
			cout << ans << " " << cnt << " " << cur << endl;
		ans += cur;
		cur += a[i];
	}
	return mp(ans, cnt);
}

void solve() {
	int k; cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(rall(a));
	ll l = 0, r = 1;
	ll c = inf0;
	int id = -1;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (l >= 0)
			ans += l;
		l += a[i];
		if (l < 0 && id == -1) {
			c = l;
			id = i;
		}
		//cout << a[i] << " ";
	}
	//cout << endl;
	if (l >= 0) {
		cout << ans << endl;
		return;
	}
	assert(c != inf0);
	vector<ll> p = { c };
	for (int i = id + 1; i < n; i++)
		p.push_back(a[i]);
	sort(rall(p));
	multiset<pair<int, ll>> kek;
	for (int i = 0; i < k + 1; i++)
		kek.insert(mp(0, 0));
	for (ll x : p) {
		auto v = *kek.begin();
		v.second *= -1;
		kek.erase(kek.begin());
		//cout << ans << endl;
		//cout << x << " " << v.first << " " << v.second << endl;
		ans += v.second;
		v.second += x;
		v.first++;
		v.second *= -1;
		kek.insert(v);
	}
	cout << ans << endl;
	/*while (r - l > 1) {
		ll m = l + r >> 1;
		pair<ll, ll> v = get(m);
		if (v.second > k) r = m;
		else l = m;
	}
	cout << l << endl;
	pair<ll, ll> ans1 = get(l);
	cout << ans1.first << endl;*/
	/*int j = -1;
	l = 0, r = 1;
	for (int i = 0; i < n; i++) {
		if (l < 0 && j == -1) {
			j = i;
		}
		l += a[i];
	}
	assert(j != -1);
	sort(a.begin() + j, a.end());
	for (ll i : a)
		cout << i << " ";
	cout << endl;
	while (r - l > 1) {
		ll m = l + r >> 1;
		pair<ll, ll> v = get(m);
		if (v.second > k) r = m;
		else l = m;
	}
	pair<ll, ll> ans2 = get(l);
	cout << max(ans1.first, ans2.first) << endl;*/
	return;
}