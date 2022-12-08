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
#include <complex>

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

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
	ll x, y, z;
	Point() {}
	Point(ll x, ll y, ll z) : x(x), y(y), z(z) {}
};

ll sq(ll a) { return a * a; }

ll dist(Point A, Point B) {
	return sq(A.x - B.x) + sq(A.y - B.y) + sq(A.z - B.z);
}

void solve() {
	int n; cin >> n;
	vector<bool> deled(n, false);
	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	for (int i = 0; i < n; i++) {
		if (deled[i]) continue;
		ll mini = -1;
		for (int j = i + 1; j < n; j++) {
			if (deled[j]) continue;
			if (mini == -1) {
				mini = j;
				continue;
			}
			if (dist(a[i], a[j]) < dist(a[i], a[mini])) mini = j;
		}
		cout << i + 1 << " " << mini + 1 << endl;
		deled[i] = true;
		deled[mini] = true;
	}
}