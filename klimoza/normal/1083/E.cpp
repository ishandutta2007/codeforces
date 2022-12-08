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

	Point() {}
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
};

bool operator<(Point A, Point B) {
	return make_pair(A.x, A.y) < make_pair(B.x, B.y);
}

struct Line {
	ll k, b;

	Line() {}
	Line(ll _k, ll _b) {
		k = _k;
		b = _b;
	}

	double value(double x) {
		return k * x + b;
	}
};

Point intersect(Line a, Line b) {
	double x = (double)(a.b - b.b) / (b.k - a.k);
	return { x, a.value(x) };
}

struct CHT {
	vector<Point> p;
	vector<Line> l;
	CHT() {}
	void addline(Line a) {
		if (l.empty()) l.push_back(a);
		else {
			while (p.size() && p.back().y < a.value(p.back().x)) {
				p.pop_back();
				l.pop_back();
			}
			p.push_back(intersect(l.back(), a));
			l.push_back(a);
		}
	}

	ll get(ll x) {
		int le = -1;
		int r = p.size();
		while (r - le > 1) {
			int mid = (r + le) / 2;
			if (p[mid].x <= x) r = mid;
			else le = mid;
		}
		return l[r].value(x);
		//return l[l.size() - 1 - (lower_bound(p.rbegin(), p.rend(), Point(x, -1e18)) - p.rbegin())].value(x);
	}
};


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector < pair<pair<ll, ll>, ll>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first.first >> a[i].first.second >> a[i].second;
	}
	sort(a.begin(), a.end());
	CHT ch = CHT();
	vector<ll> dp(n);
	dp[0] = a[0].first.first * a[0].first.second - a[0].second;
	ch.addline(Line(-a[0].first.first, dp[0]));
	ll maxi = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max((ll)0, ch.get(a[i].first.second)) + a[i].first.first * a[i].first.second - a[i].second;
		maxi = max(maxi, dp[i]);
		ch.addline(Line(-a[i].first.first, dp[i]));
	}
	cout << maxi << endl;
	//system("pause");
	return 0;
}