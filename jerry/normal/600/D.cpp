#include <bits/stdc++.h>
using namespace std;

inline long double f(long double r, long double a) { return r*r/2*(a-sin(a)); }

int main()
{
	long double x1, y1, r1, x, y, r, p(acos(-1));
	cin >> x1 >> y1 >> r1 >> x >> y >> r;
	if (x1 == x && y1 == y && r1 == r)
	{ cout << setprecision(10) << p*r*r << endl; return 0; }
	if (r > r1) { swap(x1, x); swap(y1, y); swap(r, r1); }
	x -= x1; y -= y1; x = sqrt(x*x+y*y);
	long double t = (r1*r1-r*r-x*x)/(2*r*x);
	if (abs(t) >= 1)
	{
		if (x > r1) cout << 0 << endl;
		else cout << setprecision(10) << p*min(r*r, r1*r1) << endl;
		return 0;
	}
	long double a2 = p-acos(t), a1 = acos(x/r1+t/r1*r);
	if (a2 < p/2)
		cout << setprecision(10) << f(r1, 2*a1)+f(r, 2*a2) << endl;
	else
		cout << setprecision(10) << f(r1, 2*a1)+p*r*r-f(r, 2*(p-a2)) << endl;
	return 0;
}