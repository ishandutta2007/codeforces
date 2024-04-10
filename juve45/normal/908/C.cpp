#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 1
#define NMAX 1
#define MMAX 1
#define EPS 1e-9

using namespace std;

int n, k, x;
string s;

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	//out << v.size() << '\n';
	for(auto e : v)
		out << e.y << ' ';
	return out;
}



struct point{
	double x, y;
	
	point() {	}

	point(double _x, double _y) {
		x = _x;
		y = _y;
	}

	void rotate(long double alfa) {
		long double cx = x;
		x = x * cos(alfa) - y * sin(alfa);
		y = y * cos(alfa) + cx * sin(alfa);
	}
};

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
	}

};



long double area(point a, point b, point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

long double dist(point a, point b)
{
	long double X = a.x - b.x;
	long double Y = a.y - b.y;
	return sqrt(X * X + Y * Y);
}
/*
bool checkInt(seg a, seg b)
{
	if(area(a.a, a.b, b.a) * area(a.a, a.b, b.b) >= EPS)
		return false;
	if(area(b.a, b.b, a.a) * area(b.a, b.b, a.b) >= EPS)
		return false;
	return true;
}*/

vector <point> c;
int r;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> r;
	cout << fixed << setprecision(9);

	for(int i = 1; i <= n; i++)
	{
		double x;
		cin >> x;	
		double ymax = r;
		//dbg(i);
		for(int j = 0; j < c.size(); j++) {
			if(fabs(c[j].x - x) <= EPS) 
				ymax = max(ymax, c[j].y + 2 * r);
			else if(fabs(c[j].x - x) <= 2 * r + 1e-11) 
				ymax = max(ymax, c[j].y + sqrt(4*r*r - fabs(c[j].x - x) * fabs(c[j].x - x)));
			//dbg(ymax);
		}
		c.push_back(point(x, ymax));
	}
	cout << c << '\n';

}