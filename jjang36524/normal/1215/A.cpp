#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[100100];
int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if (e > a * (c - 1) + b * (d - 1))
	{
		cout << e - a * (c - 1) - b * (d - 1) << ' ';
	}
	else
		cout << 0 << ' ';
	if (c == d)
	{
		cout << e / c;
	}
	if (c > d)
	{
		if (e > b * d)
		{
			e -= b * d;
			cout << e / c + b;
		}
		else
		{
			cout << e / d;
		}
	}
	if (c < d)
	{
		if (e > a * c)
		{
			e -= a * c;
			cout << e / d + a;
		}
		else
		{
			cout << e / c;
		}
	}
}