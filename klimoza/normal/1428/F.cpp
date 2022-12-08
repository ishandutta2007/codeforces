
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

mt19937 mrand(43);

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

struct T {
	vector<ll> t;
	T() {}
	T(int n) {
		t.assign(4 * n, 0);
	}
	int get(int v, int l, int r, int vl, int vr, ll x) {
		if (t[v] <= x)
			return -1;
		if (l >= vr || vl >= r) 
			return -1;
		if (r - l == 1)
			return l;
		int d = get(2 * v + 2, l + r >> 1, r, vl, vr, x);
		if (d == -1)
			return get(2 * v + 1, l, l + r >> 1, vl, vr, x);
		return d;
	}
	void upd(int v, int l, int r, int i, ll x) {
		if (l > i || i >= r) return;
		if (r - l == 1) {
			t[v] = x;
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, i, x);
		upd(2 * v + 2, l + r >> 1, r, i, x);
		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
	}
};

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	T t = T(n);
	vector<ll> ln(n);
	ll ans = 0;
	vector<int> prv(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') ln[i] = 0;
		else {
			if (i)
				ln[i] = 1 + ln[i - 1];
			else
				ln[i] = 1;
		}	
		if (!i) prv[i] = -1;
		else {
			prv[i] = t.get(0, 0, n, 0, i, ln[i]);
		}
		t.upd(0, 0, n, i, ln[i]);
		int cur = i;
		if (ln[i] == 0)
			cur = prv[i];
		ll kek = 0;
		while (cur != -1) {
			//cout << cur << endl;
			ans += ln[cur] * (ln[cur] + 1) / 2 - kek *  (kek + 1) / 2 + kek * kek;
			//cout << ans << " lol\n";
			ans += (cur - prv[cur] - ln[cur]) * 1ll * ln[cur];
			kek = ln[cur];
			cur = prv[cur];
		}
		//cout << i << " " << ans << " " << prv[i] << " " << ln[i] << endl;
	}
	cout << ans << endl;
	return;
}