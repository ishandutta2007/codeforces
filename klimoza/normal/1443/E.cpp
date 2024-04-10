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
//mt19937 mrand(228);

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

ll f(ll n) {
	return n * (n + 1) / 2;
}

vector<int> kek;

ll get(int l, int r) {
	ll s = 0;
	for (; l <= r; l++)
		s += kek[l];
	return s;
}

int s = 15;

ll fac(ll n) {
	if (!n) return 1;
	return n * fac(n - 1);
}

vector<int> perm(ll n) {
	vector<int> kek;
	vector<int> lst;
	for (int i = 1; i <= s; i++)
		lst.push_back(i);
	for (int i = 1; i <= s; i++) {
		ll t = n / fac(s - i);
		kek.push_back(lst[t]);
		n %= fac(s - i);
		vector<int> tmp;
		for (int i : lst)
			if (i != lst[t])
				tmp.push_back(i);
		lst = tmp;
	}
	return kek;
}

void solve() {
	int n, q; cin >> n >> q;
	int l = 0;
	if (n <= 15) {
		for (int i = 1; i <= n; i++)
			kek.push_back(i);
		s = n;
	}
	else {
		l = (n - 15);
		for (int i = l + 1; i <= n; i++)
			kek.push_back(i);
	}
	ll nm = 0;
	while (q--) {
		int t; cin >> t;
		if (t == 2) {
			int x; cin >> x;
			nm += x;
			kek = perm(nm);
			for (int& i : kek)
				i += l;
		}
		else {
			int x, y; cin >> x >> y;
			if (y <= l)
				cout << f(y) - f(x - 1) << endl;
			else if (x <= l)
				cout << f(l) - f(x - 1) + get(0, y - 1 - l) << endl;
			else
				cout << get(x - 1 - l, y - 1 - l) << endl;
		}
	}
	return;
}