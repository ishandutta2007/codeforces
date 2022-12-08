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
	vector<pair<Point, int>> a(n);
	vector<Point> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first.x >> a[i].first.y >> a[i].first.z;
		b[i] = a[i].first;
		a[i].second = i;
	}
	sort(all(a), [](pair<Point, int> A, pair<Point, int> B) {return make_pair(make_pair(A.first.x, A.first.y), A.first.z) < make_pair(make_pair(B.first.x, B.first.y), B.first.z); });
	vector<pair<int, vector<int>>> f;
	for (auto u : a) {
		if (f.empty()) {
			f.push_back({u.second, vector<int>() });
			f.back().second.push_back(u.second);
		}
		else {
			if (make_pair(u.first.x, u.first.y) == make_pair(b[f.back().first].x, b[f.back().first].y)) f.back().second.push_back(u.second);
			else {
				f.push_back({ u.second, vector<int>() });
				f.back().second.push_back(u.second);
			}
		}
	}
	vector < pair<int, vector<int>>> tmp;
	for (auto t : f) {
		while (t.second.size() >= 2) {
			cout << t.second.back() + 1 << " ";
			t.second.pop_back();
			cout << t.second.back() + 1 << " ";
			t.second.pop_back();
			cout << endl;
		}
		if (t.second.size() == 1) {
			if (tmp.empty()) {
				tmp.push_back({ t.first, vector<int>() });
				tmp.back().second.push_back(t.first);
			}
			else {
				if (b[t.first].x == b[tmp.back().first].x) tmp.back().second.push_back(t.first);
				else {
					tmp.push_back({ t.first, vector<int>() });
					tmp.back().second.push_back(t.first);
				}
			}
		}
	}
	vector<int> ed;
	for (auto t : tmp) {
		while (t.second.size() >= 2) {
			cout << t.second.back() + 1 << " ";
			t.second.pop_back();
			cout << t.second.back() + 1 << " ";
			t.second.pop_back();
			cout << endl;
		}
		if (t.second.size() == 1) ed.push_back(t.first);
	}
	for (int i = 1; i < ed.size(); i += 2) cout << ed[i] + 1 << " " << ed[i - 1] + 1 << endl;
}