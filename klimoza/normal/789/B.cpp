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

void solve() {
	int b1, q, l, m;
	cin >> b1 >> q >> l >> m;
	set<int> kek;
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		kek.insert(a[i]);
	}
	if (abs(b1) > l) {
		cout << 0 << endl;
		return;
	}
	if (b1 == 0) {
		if (kek.find(0) != kek.end()) cout << 0 << endl;
		else cout << "inf\n";
	}
	else if (q == 0) {
		if (kek.find(0) == kek.end()) cout << "inf\n";
		else {
			if (abs(b1) <= l && kek.find(b1) == kek.end()) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	else if (q == 1) {
		if (abs(b1) <= l && kek.find(b1) == kek.end()) cout << "inf\n";
		else cout << 0 << endl;
	}
	else if (q == -1) {
		if (abs(b1) > l) cout << 0 << endl;
		else if (kek.find(b1) != kek.end() && kek.find(-b1) != kek.end()) cout << 0 << endl;
		else if (kek.find(b1) != kek.end() || kek.find(-b1) != kek.end()) cout << "inf" << endl;
		else cout << "inf" << endl;
	}
	else {
		vector<ll> a = { b1 };
		while (abs(a.back()) <= l) {
			a.push_back(a.back() * 1ll * q);
		}
		int res = 0;
		for (ll i : a) {
			if (abs(i) <= l && kek.find(i) == kek.end())
				res++;
		}
		cout << res << endl;
	}
	return;
}