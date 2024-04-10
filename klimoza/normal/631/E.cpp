#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;


struct Point {
	double x, y;
	Point(){}
	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

bool operator<(Point A, Point B) {
	return A.x < B.x;
}

struct Line {
	ll k, b;
	Line() {}
	Line(ll _k = -INF, ll _b = -INF) : k(_k), b(_b) {}
	
	double get(double x) {
		return k * x + b;
	}
};

Point intersect(Line a, Line b) {
	double x = (double)(a.b - b.b) / (double)(b.k - a.k);
	return { x, a.get(x) };
}

struct CHT {
	vector<Point> p;
	vector<Line> l;
	
	CHT(Line a) {
		l = { a };
		p = {};
	}
	
	void addLine(Line a) {
		while (p.size() && p.back().y < a.get(p.back().x)) {
			p.pop_back();
			l.pop_back();
		}
		p.push_back(intersect(a, l.back()));
		l.push_back(a);
	}
	
	ll get(ll x) {
		return l[lower_bound(p.begin(), p.end(), Point(x, -INF)) - p.begin()].get(x);
	}
};

struct CHT2 {
	vector<Point> p;
	vector<Line> l;

	CHT2(Line a) {
		l = { a };
		p = {};
	}

	void addLine(Line a) {
		while (p.size() && p.back().y < a.get(p.back().x)) {
			p.pop_back();
			l.pop_back();
		}
		p.push_back(intersect(a, l.back()));
		l.push_back(a);
	}

	ll get(ll x) {
		int le = -1;
		int r = p.size();
		while (r - le > 1) {
			int mid = (r + le) / 2;
			if (p[mid].x <= x) r = mid;
			else le = mid;
		}
		return l[r].get(x);
	}
};

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<ll> a(n);
	ll ans = 0;
	vector<ll> s(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i] * ((ll)i + 1);
		if (i) s[i] = s[i - 1] + a[i];
		else s[i] = a[i];
	}
	CHT ch = CHT({ 1, 0 });
	ll max1 = -INF;
	for (int i = 1; i < n; i++) {
		ll t = ans + s[i - 1] - a[i] * (i + 1) + ch.get(a[i]);
		ch.addLine({ i + 1, -s[i - 1] });
		max1 = max(t, max1);
	}
	CHT2 ch2 = CHT2({ n, -s[n - 1] });
	ll max2 = -INF;
	for (int i = n - 2; i >= 0; i--) {
		ll t = ans + s[i] - a[i] * (i + 1) + ch2.get(a[i]);
		ch2.addLine({ i + 1, -s[i] });
		max2 = max(t, max2);
	}
	cout << max(ans, max(max1, max2)) << endl;
	return 0;
}