#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
	(x + y / 60) / 12 * 360
	
	x * 30 + y / 2

*/

int main() {
	int x, y;
	scanf("%d:%d", &x, &y);

	double a = x*30 + y*0.5;
	double b = y*6;

	while (a >= 360)
		a -= 360;
	while (b >= 360)
		b -= 360;

	cout << a << ' ' << b << '\n';
}