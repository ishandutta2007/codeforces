#include <iostream>
using namespace std;
long long a, b, c, d, e, t;
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c >> d >> e;
		int total = (b + d - 1) / d + (a + c - 1) / c;
		if (total > e)
			cout << -1 << '\n';
		else
			cout << (a + c - 1) / c << ' ' << (b + d - 1) / d<<'\n';
	}
	
}