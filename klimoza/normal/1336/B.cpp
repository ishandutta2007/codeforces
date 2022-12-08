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
#define pb(v) push_back(v)

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const ld eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

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

ll foo(ll a, ll b, ll c) {
	return (a - b) * (a - b) + (b - c) * (b - c) + (a - c) * (a - c);
}

ll get(ll a, ll b, vector<ll>& cc) {
	int l = 0, r = cc.size() - 1;
	while (r - l > 4) {
		int m1 = (2 * l + r) / 3;
		int m2 = (l + 2 * r) / 3;
		ll k1 = foo(a, b, cc[m1]);
		ll k2 = foo(a, b, cc[m2]);
		if (k1 < k2) r = m2;
		else l = m1;
	}
	ll ans = inf;
	//if (cc.size() == 1) cout << l << " " << r << endl;
	for (int i = 0; i < 5; i++) {
		if (i + l >= cc.size()) break;
		ans = min(ans, foo(a, b, cc[i + l]));
	}
	//if (cc.size() == 1) cout << l << " " << r << endl;
	return ans;
}

ll smart(vector<ll> ar, vector<ll> ag, vector<ll> ab) {
	sort(all(ar));
	ar.erase(unique(all(ar)), ar.end());
	sort(all(ag));
	ag.erase(unique(all(ag)), ag.end());
	sort(all(ab));
	ab.erase(unique(all(ab)), ab.end());
	int r = ar.size(); int g = ag.size(); int bb = ab.size();
	ll ans = inf;
	for (ll a : ar) {
		int l = 0, r = g - 1;
		while (r - l > 4) {
			int m1 = (2 * l + r) / 3;
			int m2 = (l + 2 * r) / 3;
			//if (r == 9 && g == 9 && bb == 1)	cout << l << " " << r << " " << m1 << " " << m2 << endl;;
			ll k1 = get(a, ag[m1], ab);
			//if (r == 9 && g == 9 && bb == 1)cout << "kek\n";
			ll k2 = get(a, ag[m2], ab);
			if (k1 < k2) r = m2;
			else l = m1;
		}
		for (int i = 0; i < 5; i++) {
			if (i + l >= ag.size()) break;
			ans = min(ans, get(a, ag[i + l], ab));
		}
	}
	return ans;
}

ll stupid(vector<ll> ar, vector<ll> ag, vector<ll> ab) {
	ll ans = inf;
	for (ll a : ar)
		for (ll b : ag)
			for (ll c : ab) {
				ans = min(ans, foo(a, b, c));
				//if (ans == 488) cout << a << " " << b << " " << c << endl;
			}
	return ans;
}

void stress() {
	int cnt = 0;
	while (true) {
		cnt++;
		int a = rand() % 100 + 1;
		int b = rand() % 100 + 1;
		int c = rand() % 100 + 1;
		vector<ll> a1(a), a2(b), a3(c);
		for (ll& i : a1)
			i = rand() % 1000 + 1;
		for (ll& i : a2)
			i = rand() % 1000+ 1;
		for (ll& i : a3)
			i = rand() % 1000 + 1;
		ll m1 = smart(a1, a2, a3);
		ll m2 = stupid(a1, a2, a3);
		if (m1 == m2) cout << "TEST# " << cnt << " OK\n";
		else {
			cout << "TEST# " << cnt << " FAILED\n";
			cout << a << " " << b << " " << c << endl;
			for (ll i : a1)
				cout << i << " ";
			cout << endl;
			for (ll i : a2)
				cout << i << " ";
			cout << endl;
			for (ll i : a3)
				cout << i << " ";
			cout << endl;
			return;
		}
	}
}

void solve() {
	//stress(); return;
	//cout << foo(40, 30, 22) << endl;
	int tp; cin >> tp;
	while (tp--) {
		int r, g, bb;
		cin >> r >> g >> bb;
		vector<ll> ar(r), ag(g), ab(bb);
		for (ll& i : ar) cin >> i;
		for (ll& i : ag) cin >> i;
		for (ll& i : ab) cin >> i;
		cout << smart(ar, ag, ab) << endl;
		//cout << stupid(ar, ag, ab) << endl;
	}
	return;
}