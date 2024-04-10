#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5 + 5;
const double eps = 1e-9, pi = acos(-1);

struct point {
	double x, y;
	point() {x = y = 0.0;}
	point(double _x, double _y) {x = _x;y = _y;}
	friend bool operator < (point a, point b) {
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	}
	friend bool operator == (point a, point b) {
		return fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps;
	}
};

double dist(point p1, point p2) { 
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); 
}

struct line {double a, b, c;};

void pointsToLine( point p1, point p2, line &l ) {
	if (fabs(p1.x - p2.x) < eps) 
		l = {1.0, 0.0, -p1.x};
	else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}
bool areParallel( line l1, line l2 ) { 
	return fabs(l1.a - l2.a) < eps && fabs(l1.b - l2.b) < eps; 
}
bool areSame(line l1, line l2) { 
	return areParallel(l1, l2) && fabs(l1.c - l2.c) < eps;
}
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2)) return 0;
	p.x = (l2.b * l1.c - l1.b * l2.c);
	p.x /= (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > eps)
		p.y = -(l1.a * p.x + l1.c);
	else 
		p.y = -(l2.a * p.x + l2.c);
	return 1;
}

int n, H;
double ans = 0;
point O;
vector<point> P;

int main() {
	scanf("%d %d", &n, &H);
	for(int i = 0;i < n;i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		P.pb(point(x, y));
	}
	O = point(P[n - 1].x, P[n - 1].y + H);
	vector<line> L;
	line l1;
	pointsToLine(O, P[n - 1], l1);
	L.pb(l1);
	pointsToLine(O, P[n - 2], l1);
	L.pb(l1);
	ans += dist(P[n - 1], P[n - 2]);
	for(int i = n - 3;i >= 0;i--) {
		line li, l3;
		pointsToLine(O, P[i], li);
		pointsToLine(P[i], P[i + 1], l3);
		if(areSame(L.back(), l3)) {
			ans += dist(P[i], P[i + 1]);
		} else if(L.back().a < li.a) {
			line l2;
			pointsToLine(P[i], P[i + 1], l2);
			point p1;
			areIntersect(L.back(), l2, p1);
			ans += dist(P[i], p1);
			L.pb(li);
		}
	}
	printf("%.9lf\n", ans);
	return 0;
}