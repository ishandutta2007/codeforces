#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
//#define FILENAME "1dembedding"
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
#else
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cin >> t;
    while (t--)
        solve();
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

#define int li

struct Point {
	int x, y;
	Point() {}
	Point (int x, int y):x(x), y(y) {}
	Point operator + (Point b) { return Point(x + b.x, y + b.y); }
	Point operator - (Point b) { return Point(x - b.x, y - b.y); }
	Point operator / (int c) { 
		assert(x % c == 0 && y % c == 0);
		return Point(x / c, y / c); 
	}
	void scan() { cin >> x >> y; x *= 2; y *= 2; }
	void print() { cout << x << ' ' << y << endl; }
	bool operator < (const Point& b) const { return mp(x, y) < mp(b.x, b.y); }
	bool operator == (const Point& b) const { return mp(x, y) == mp(b.x, b.y); }
	int sqrDist() { return x * x + y * y; }
	Point rotate () { return Point(y, -x); }

};

int gcd (int q, int w) {
	q = abs(q);
	w = abs(w);
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

struct Line {
	int a, b, c;
	Line() {}
	Line (int a, int b, int c):a(a), b(b), c(c) {}
	void norm() {
		int g = gcd(a,gcd(b,c));
		a /= g; b /= g; c /= g;
		if (a < 0)
			a = -a, b = -b, c = -c;
		if (a == 0) {
			if (b < 0)
				b = -b, c = -c;
			if (b == 0) {
				assert(false);
				c = abs(c);
			}
		}
	}
	bool operator < (const Line& other) const { return mp(a, mp(b,c)) < mp(other.a, mp(other.b, other.c)); }

};

int n, m;
Point segments[300500][2];

map <Line, vector<pair<Point, Point>>> mapa;

typedef map <Line, vector<pair<Point, Point>>>::iterator iter;

Point circles[2000];
int r[2000];

map <Line, vector<Point>> need;

void solve() {
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		segments[i][0].scan();
		segments[i][1].scan();
		if (segments[i][1] < segments[i][0])
			swap(segments[i][0], segments[i][1]);
		int x1 = segments[i][0].x;
		int y1 = segments[i][0].y;
		int x2 = segments[i][1].x;
		int y2 = segments[i][1].y;
		Line cur = Line(y1 - y2, x2 - x1, x1 * y2 - x2 * y1);
		cur.norm();
		mapa[cur].push_back(mp(segments[i][0], segments[i][1]));
	}
	for (int i = 0; i < m; ++i) {
		circles[i].scan();
		cin >> r[i];
		r[i] *= 2;
	}

	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j < m; ++j) {
			if (r[i] != r[j])
				continue;
			if ((circles[i] - circles[j]).sqrDist() <= (r[i] + r[j]) * (r[i] + r[j]))
				continue;

			Point half = (circles[i] + circles[j]) / 2;
			Point vec = circles[i] - half;
			vec = vec.rotate();

			int x1 = half.x;
			int y1 = half.y;
			int x2 = (half + vec).x;
			int y2 = (half + vec).y;

			Line cur = Line(y1 - y2, x2 - x1, x1 * y2 - x2 * y1);
			cur.norm();
			if (mapa.find(cur) == mapa.end())
				continue;
			need[cur].push_back(half);
		}
	
	long long ans = 0;
	for (iter it = mapa.begin(); it != mapa.end(); ++it) {
		map <Line, vector<Point>>::iterator pointsIt = need.find(it->first);
		if (pointsIt == need.end())
			continue;
		vector<pair<Point, Point>> segs = it->second;
		vector<Point> points = pointsIt->second;

		vector<Point> allPoints;
		for (int i = 0; i < segs.size(); ++i) {
			allPoints.push_back(segs[i].first);
			allPoints.push_back(segs[i].second);
		}
		for (int i = 0; i < points.size(); ++i)
			allPoints.push_back(points[i]);
		sort(all(allPoints));
		allPoints.resize(unique(all(allPoints)) - allPoints.begin());
		
		vector<pair<int, int>> events;

		for (int i = 0; i < segs.size(); ++i) {
			events.push_back(mp(lower_bound(all(allPoints), segs[i].first) - allPoints.begin(), 1));
			events.push_back(mp(lower_bound(all(allPoints), segs[i].second) - allPoints.begin(), 3));
		}

		for (int i = 0; i < points.size(); ++i)
			events.push_back(mp(lower_bound(all(allPoints), points[i]) - allPoints.begin(), 2));
		sort(all(events));
		int numSeg = 0;
		for (int i = 0; i < events.size(); ++i) {
			if (events[i].second == 1)
				++numSeg;
			if (events[i].second == 3)
				--numSeg;
			if (events[i].second == 2)
				ans += numSeg;
		}

	}

	cout << ans;

}