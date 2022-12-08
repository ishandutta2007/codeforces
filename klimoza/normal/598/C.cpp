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

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
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

struct Point {
	ll x, y;
	Point(ll x, ll y) : x(x), y(y) {}
};

struct Vector {
	ll x, y;
	Vector() {}
	Vector(ll x, ll y) : x(x), y(y) {}
};

ll cross(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}

ll dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

bool top(Vector a) {
	return a.y > 0 || (a.y == 0 && a.x > 0);
}

void solve() {
	int n; cin >> n;
	vector<pair<Vector, int>> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first.x >> p[i].first.y;
		p[i].second = i;
	}
	sort(all(p), [](pair<Vector, int> a, pair<Vector, int> b) {
		if(top(a.first) == top(b.first))
		return cross(a.first, b.first) > 0;
		return top(b.first);
	});
	Vector ans = Vector(dot(p[0].first, p[1].first), abs(cross(p[0].first, p[1].first)));
	int f1 = 0, f2 = 1;
	for (int i = 1; i < n; i++) {
		Vector cur = Vector(dot(p[i].first, p[(i + 1) % n].first), abs(cross(p[i].first, p[(i + 1) % n].first)));
		if (cross(cur, ans) > 0) {
			ans = cur;
			f1 = i, f2 = (i + 1) % n;
		}
	}
	cout << p[f1].second + 1 << " " << p[f2].second + 1 << endl;
}