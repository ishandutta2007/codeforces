#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int d,l,v,w;
	cin >> d >> l >> v >> w;
	long double x = l-d;
	x = x/(v+w);
	cout << setprecision(10) << x;
	return 0;
}