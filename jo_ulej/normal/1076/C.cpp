#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

int main(int argc, char** argv)
{
	const double eps = 1e-6;
	int t;
	cin >> t;

	for(; t > 0; --t)
	{
		double d;
		cin >> d;

		double D = sqrt(d * d - 4.0 * d);

		double x1 = 0.5 * (d + D);
		double x2 = 0.5 * (d - D);

		if(fabs(x1 * x2 - x1 - x2) < eps && fabs(d - x1 - x2) < eps)
			cout << "Y " << fixed << setprecision(9) << x1 << " " << x2 << endl;
		else
			cout << "N" << endl;
	}

    return 0;
}