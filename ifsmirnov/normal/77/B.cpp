#include <iostream>
#include <cmath>
using namespace std;
#define eq(x, y) (abs((x)-(y))<1e-9)

long double p, q; 
int main()
{
	ios :: sync_with_stdio(false);
	cout.precision(30);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> p >> q;
//		cout << (8*q)/(4*q+p/2.) << "\n";
		if (eq(q, 0))
			cout << "1\n";
		else if (eq(p, 0))
			cout << "0.5\n";	
		else if (p<4*q)
			cout << (4*p*q + p*p/2.) / (8*p*q) << "\n";
		else
			cout <<	1 - q/p << "\n";
	}
	return 0;	
};