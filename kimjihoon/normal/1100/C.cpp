#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	double n, r; cin >> n >> r;
	double c = sin(1 / n * M_PI);
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << r * c / (1 - c) << '\n';
	return 0;
}