#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
const int maxn = 10010;
const double eps = 1e-11;
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define sqr(x) ((x)*(x))

struct point 
{
	double x, y, z;
	point (double X=0., double Y=0., double Z=0.): x(X),y(Y),z(Z){};
};
point operator+ (point p1, point p2)
{
	return point(p1.x+p2.x, p1.y+p2.y, p1.z+p2.z);
};
point operator- (point p1, point p2)
{
	return point(p1.x-p2.x, p1.y-p2.y, p1.z-p2.z);
};
point operator* (point p1, double k)
{
	return point(p1.x*k, p1.y*k, p1.z*k);
};
double len (point p1)
{
	return sqrt(sqr(p1.x) + sqr(p1.y) + sqr(p1.z));
};
double dist(point p1, point p2)
{
	return len(p1-p2);
};

int n;
point a[maxn];

point p;
double tb[maxn], th[maxn];
double vp, vs;
double xres, yres, zres, tres;

void scan();
bool solve();


int main()
{
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cout<<"FILES!!!\n";
	cerr<<"FILES!!!\n";*/

		
	scan();
	if (!solve())
		printf("NO");
	else
		printf("YES\n%.8lf\n%.8lf %.8lf %.8lf", tres, xres, yres, zres);

	return 0;
};
void scan()
{	
	cin >> n;
	n++;
	forn(i, n) cin >> a[i].x >> a[i].y >> a[i].z;
	cin >> vp >> vs;
	cin >> p.x >> p.y >> p.z;
};	
bool solve()
{
	tb[0] = 0;
/*	cout << "s1 = " << len(a[0] - a[1]) << endl;
	cout << "p1 = " << len(p - a[1]) << endl;*/

	forn(i, n-1)
		tb[i+1] = tb[i] + (len(a[i] - a[i+1]) / vs);

	forn(i, n)
		th[i] = len(a[i] - p) / vp;

/*	forn(i, n)
	{
		cout << tb[i] << " " << th[i] << endl;
	}
	cout<<endl;*/
	          
	if (lt(tb[n-1], th[n-1]))
		return false;

	if (eq(th[n-1], tb[n-1]))
	{
		tres = th[n-1];
		xres = a[n-1].x, yres = a[n-1].y, zres = a[n-1].z;
		return true;
	}

	point cur, nxt; //cur is reachable, nxt is not
	double curt, nxtt;
	forn(i, n)
	{
		if (lt(th[i], tb[i]))
		{
			cur = a[i-1];
			nxt = a[i];
			curt = tb[i-1];
			nxtt = tb[i];
			break;
		}	
	}	

	double l = 0, r = 1, m;
	point mid;
	double TH, TB;
	while (r - l > eps)
	{
		m = (r+l) / 2;
		mid = cur + ((nxt - cur) * m);
		TH = len(p - mid) / vp;
		TB = curt + ((nxtt - curt) * m);
		if (lt(TH, TB)) 
			r = m;
		else
			l = m;
/*		cout << m << ": " << TB << " " << TH << endl;	
		cout << mid.x << " " << mid.y << " " << mid.z << endl;*/
	}

	tres = 	curt + ((nxtt - curt) * r);
	mid = cur + ((nxt - cur) * m);
	xres = mid.x, yres = mid.y, zres = mid.z;
	return true;
};