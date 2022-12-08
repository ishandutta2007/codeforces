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

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

struct pt {
	ll x, y;
	pt() {}
	pt(ll x, ll y) : x(x), y(y) {}
};

bool operator<(pt A, pt B) {
	return mp(A.x, A.y) < mp(B.x, B.y);
}

istream& operator>>(istream& in, pt& A) {
	return in >> A.x >> A.y;
}

void norm(ll& a, ll& b, ll& c) {
	ll g = gcd(gcd(a, b), c);
	a /= g; b /= g; c /= g;
	if (a < 0) {
		a *= -1;
		b *= -1;
		c *= -1;
	}
	else if (a == 0 && b < 0) {
		b *= -1;
		c *= -1;
	}
}

struct line {
	ll a, b, c;
	line() {}
	line(ll a, ll b, ll c) : a(a), b(b), c(c) {}
	line(pt A, pt B, bool bl) {
		a = 2 * (A.x - B.x);
		b = 2 * (A.y - B.y);
		c = -((A.x - B.x) * (A.x + B.x) + (A.y - B.y) * (A.y + B.y));
		norm(a, b, c);
	}
	line(pt A, pt B) {
		a = -(A.y - B.y);
		b = (A.x - B.x);
		c = -a * A.x - b * A.y;
		norm(a, b, c);
	}
};

bool operator<(line a, line b) {
	if (a.a < b.a) return true;
	if (a.a > b.a) return false;
	if (a.b < b.b) return true;
	if (a.b > b.b) return false;
	if (a.c < b.c) return true;
	return false;
}
ll dist(pt A, pt B) {
	return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

map<line, vector<pair<ll, ll>>> l;
map<line, vector<pair<ll, ll>>> r;

void solve() {
	int n, m; cin >> n >> m;
	vector<pair<pt, pt>> seg(n);
	vector<line> kek(n);
	for (int i = 0; i < n; i++) {
		cin >> seg[i].first >> seg[i].second;
		if (seg[i].second < seg[i].first)
			swap(seg[i].first, seg[i].second);
		kek[i] = line(seg[i].first, seg[i].second);
		l[kek[i]].push_back({ 2 * seg[i].first.x, 2 * seg[i].first.y });
		r[kek[i]].push_back({ 2 * seg[i].second.x, 2 * seg[i].second.y });
		//cout << kek[i].a << " " << kek[i].b << " " << kek[i].c << endl;
	}
	for (auto& u : l)
		sort(all(u.second));
	for (auto& u : r)
		sort(all(u.second));
	vector<pair<pt, ll>> crc(m);
	for (int i = 0; i < m; i++)
		cin >> crc[i].first >> crc[i].second;
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			if (crc[i].second != crc[j].second) continue;
			if (dist(crc[i].first, crc[j].first) <= (crc[i].second + crc[j].second) * (crc[i].second + crc[j].second)) continue;
			line mem = line(crc[i].first, crc[j].first, true);
			if (l.find(mem) == l.end()) continue;
			//cout << mem.a << " " << mem.b << " " << mem.c << endl;
			pair<ll, ll> c{ crc[i].first.x + crc[j].first.x, crc[i].first.y + crc[j].first.y };
			ll tmp = l[mem].size();
			//cout << tmp << endl;
			//cout << c.first << " " << c.second << endl;
			tmp -= lower_bound(all(r[mem]), c) - r[mem].begin();
			//cout << tmp << endl;
			tmp -= ((int)l[mem].size() - (upper_bound(all(l[mem]), c) - l[mem].begin() - 1)) - 1;
			ans += tmp;
		}
	}
	cout << ans << endl;
	return;
}