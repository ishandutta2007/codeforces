#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 
#define NMAX 
#define MMAX 

#define st first
#define nd second

#define EPS 1e-9
const double PI = acos(-1);

using namespace std;

int n, k;

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << '\n';
	return out;
}

struct point{
	long double x, y;
	
	point() {	}
	point(const point &a) {x = a.x, y = a.y;}
	point(long double _x, long double _y) { x = _x; y = _y; }

	point operator-(point a) {return point(x - a.x, y - a.y);}
	point operator+(point a) {return point(x + a.x, y + a.y);}
	point operator*(long double val) {return point(x * val, y * val);}
	point operator/(long double val) {return point(x / val, y / val);}

  bool operator<(const point &a) const { if(fabs(x - a.x) < EPS) {if(fabs(y - a.y) < EPS) return false; return y < a.y;} return x < a.x; }
  bool operator==(const point &a) const { if(fabs(x - a.x) < EPS) if(fabs(y - a.y) < EPS) return true; return false; }

  point rot() {return point(-y, x);}
  double norm() {return x*x + y*y; }
  double len() {return sqrt(norm()); }

	void rot(long double alfa) {
		long double cx = x;
		x = x * cos(alfa) - y * sin(alfa);
		y = y * cos(alfa) + cx * sin(alfa);
	}
};

ostream& operator<<(ostream& out, point p) { return out << p.x << ' ' << p.y; }

struct line
{
	double m, n;

	line(point A, point B) {
		m = (A.y - B.y) / (A.x - B.x) ;
		n = A.y - m * A.x;
	}

	line(point A, double _m) {
		// linia de panta _m care trece prin punctul A
		m = _m;
		n = A.y - m * A.x; 
	}

	line(double _m, double _n) {
		m = _m;
		n = _n;
	}

	point intersect(line l) {
		// returneaza punctul in care se intersecteaza linia this cu linia l
		point O;
		//if(m == l.m)
		// return 
		O.x = (l.n - n) / (m - l.m);
		O.y = m * O.x + n;
		return O;
	}

};


long double dist(point a, point b)
{
	long double X = a.x - b.x;
	long double Y = a.y - b.y;
	return sqrt(X * X + Y * Y);
}

struct circle {
	point o;
	double r;

	circle() {}
	circle(point a, point b, point c) {
		point mab = (a + b) / 2.;
		point mbc = (c + b) / 2.;
		line ab(a, b), bc(b, c);
		line ab1(mab, -1.0/ab.m);
		line bc1(mbc, -1.0/bc.m);
		o = ab1.intersect(bc1);
		r = dist(o, a);
	} 

  bool operator==(circle & c) {
    if(fabs(c.r - r) > EPS) return false;
    if(fabs(c.o.x - o.x) > EPS) return false;
    if(fabs(c.o.y - o.y) > EPS) return false;
    return true;
  }
 
  vector <point> intersect(circle c) {
    long double p, h, a, area, d;
    d = dist(o, c.o); 
    if(d > r + c.r) return {};
    if(d < fabs(r - c.r)) return {};
    a = 0.5 * (d  + (r * r - c.r * c.r) / d );
    h = sqrt(r * r - a * a);
    point B = o + (c.o - o) * a / d;
    point aa = c.o - o;
    point ff(-aa.y, aa.x);//aa.y = -aa.y;
    aa = ff * h / d;
    return {B + aa, B - aa};  
  }

};

struct seg {
	point a, b;

	seg() { };
	seg(point _a, point _b) { a = _a, b = _b; };
};


istream& operator>>(istream& in, point &p) { return in >> p.x >> p.y; }

istream& operator>>(istream& in, circle &c) { return in >> c.o >> c.r; }

istream& operator>>(istream& in, seg &s) { return in >> s.a >> s.b; }

long double area(point a, point b, point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

bool isObtouseAngle(point A, point B, point C) {
	//check if A angle is obtuse
	double a = dist(B, C);
	double b = dist(A, C);
	double c = dist(B, A);
	a *= a;
	b *= b;
	c *= c;
	if(b + c < a)
		return true;
	return false;
}

double dist(point p, seg s) {
	if(isObtouseAngle(s.a, s.b, p) || dist(s.a, s.b) <= EPS || isObtouseAngle(s.b, s.a, p))
		return min(dist(p, s.a), dist(p, s.b));
	return fabs(area(p, s.a, s.b)) / dist(s.a, s.b);
}

bool checkInt(seg a, seg b)
{
	if( area(a.a, a.b, b.a) * area(a.a, a.b, b.b) > 0 )
	  return false;
	if( area(b.a, b.b, a.a) * area(b.a, b.b, a.b) > 0 )
	  return false;

	if( area(b.a, b.b, a.a) * area(b.a, b.b, a.b) == 0  && area(a.a, a.b, b.a) * area(a.a, a.b, b.b) == 0) {
	  if( max(b.a.x, b.b.x) < min(a.a.x, a.b.x) || min(b.a.x, b.b.x) > max(a.a.x, a.b.x))
	      return false;
	  if( max(b.a.y, b.b.y) < min(a.a.y, a.b.y) || min(b.a.y, b.b.y) > max(a.a.y, a.b.y))
	      return false;
	}
	return true;
}

point cmp_point;
bool cmp(point a, point b) {
	return area(cmp_point, a, b) >= 0;
}

vector <point> hull(vector <point> &pts) {

	int ind = 0;
	for(int i = 1; i < pts.size(); i++) 
		if(pts[i] < pts[ind]) 
			ind = i;
	swap(pts[pts.size() - 1], pts[ind]);
	cmp_point = pts.back();
	pts.pop_back();

	sort(pts.begin(), pts.end(), cmp);

	vector <point> hull;
	hull.push_back(cmp_point);
	for(int i = 0; i < pts.size(); i++) {
		 while (hull.size() > 2 && area(hull[hull.size()-2],hull[hull.size() - 1],pts[i]) < 0) {
	      hull.pop_back();
	    }
	    hull.push_back(pts[i]);
	}
	return hull;
}

const int N = 100100;
point pa, pb, pr, p[N];
long double ans;
vector <pair<long double, int> > va, vb;

int main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(9);

	cin >> pa >> pb >> pr;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		ans += 2 * dist(p[i], pr);
		va.push_back({- dist(p[i], pr) + dist(p[i], pa), i});
		vb.push_back({- dist(p[i], pr) + dist(p[i], pb), i});
	}

	va.push_back({0, 0});
	vb.push_back({0, 0});

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	// dbg(va);
	// dbg(vb);
	// dbg(ans);
	long double cans = va[0].st + vb[0].st;
	if(va[0].nd == vb[0].nd) {
		cans = min(va[1].st + vb[0].st, va[0].st + vb[1].st);
	}
	cout << ans + cans << '\n';
}