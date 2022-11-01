#include <bits/stdc++.h>
using namespace std;

const double EPS = 1.e-8;

double _x1, _y1, _x2, _y2, v, t, vx, vy, wx, wy;

bool can(double s)
{
	pair<double, double> w(0, 0);
	if (s < t)
		w = make_pair(vx*s, vy*s);
	else
		w = make_pair(vx*t+wx*(s-t), vy*t+wy*(s-t));
	pair<double, double> init(_x1+w.first, _y1+w.second);
	double far = hypot(_x2-init.first, _y2-init.second);
	if (far/v < s)
		return true;
	return false;
}

int main()
{
	cin.sync_with_stdio(false);
	cin >> _x1 >> _y1 >> _x2 >> _y2 >> v >> t >> vx >> vy >> wx >> wy;
	double lo = 0, hi = 1000000000;
	for (int x = 100;x --> 0;)
	{
		double mid = (lo+hi) / 2;
		if (can(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << setprecision(15) << lo << endl;
	return 0;
}