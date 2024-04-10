#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
const long double EPS = 1e-9;
int n, k;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}


struct point{
	long double x, y;
	
	point() {	}
	point(const point &a) {x = a.x, y = a.y;}
	point(long double _x, long double _y) { x = _x; y = _y; }
};


long double dist(point a, point b)
{
	long double X = a.x - b.x;
	long double Y = a.y - b.y;
	return sqrt(X * X + Y * Y);
}

istream& operator>>(istream& in, point &p) { return in >> p.x >> p.y; }
ostream& operator<<(ostream& out, point p) { return out << p.x << ' ' << p.y; }

point p[N];

long double get_radius(long double x) {

	p[0].x = x;
	p[0].y = 0;

	long double rad = 0;
	for(int i = 1; i <= n; i++) {
		long double d = dist(p[0], p[i]);
		long double dx = fabs(p[0].x - p[i].x);

		if(dx <= EPS) {
			rad = max(rad, p[i].y / 2);
			continue;
		}

		long double a = p[i].y;
		long double b = dx * dx / a;

		rad = max(rad, (a + b) / 2);
	}
	return rad;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	cout << fixed << setprecision(9);
	int neg = 0, poz = 0;
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		if(p[i].y < 0) neg++;
		else poz++;
	}


	if(neg && poz) return cout << "-1\n", 0;

	if(neg > 0) {
		for(int i = 1; i <= n; i++)
			p[i].y = -p[i].y;
	}
	long double l = -2e8, r = 2e8;

	// dbg(get_radius(0.5));
	// return 0;
	// dbg(get_radius(0 	));
	// return 0;

	for(int i = 1; i <= 300; i++) {
		long double mid1 = (2 * l + r) / 3;
		long double mid2 = (l + r * 2) / 3;

		long double radmid1 = get_radius(mid1);
		long double radmid2 = get_radius(mid2);

		if(radmid1 < radmid2)
			r = mid2;
		else 
			l = mid1;
	}

	long double mid = (l + r) / 2;
	dbg(mid);
	cout << get_radius(mid) << '\n';
}