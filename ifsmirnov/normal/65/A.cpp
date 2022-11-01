#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)

long long a, b, c, d, e, f;

bool solve();

int main()
{
	cin >> a >> b >> c >> d >> e >> f;
	if (solve())
		cout<< "Ron";
	else
		cout<<"Hermione";
			
	return 0;
};

bool solve()
{
	if (!d) return false;
	else if (!c) return true;
	else if (!b) return false;
	else if (!a) return true;

	return b*d*f > a*c*e;
};