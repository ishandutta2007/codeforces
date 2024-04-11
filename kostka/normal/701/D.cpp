#include "bits/stdc++.h"

using namespace std;

int n, l, v1, v2, k, groups;

long double check(double t)
{
	long double poz = l - t * v1;
	return groups * (poz / (v2 - v1)) + (groups - 1) * (poz / (v2 + v1));
}

int main()
{
	cin >> n >> l >> v1 >> v2 >> k;
	groups = (n+k-1)/k;
	long double a = 0.0, b = 1.0*l/v1;
	while(b - a > 1e-6)
	{
		cerr << fixed << a << " " << b << "\n";
		double m = (a+b)/2;
		if(check(m) >= m)
			a = m;
		else
			b = m;
	}
	cout << fixed << setprecision(50) << a << "\n";
}