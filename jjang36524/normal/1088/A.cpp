#include <iostream>
using namespace std;

int main()
{
	int x, a, b;
	cin >> x;
	for (a = 1; a <= x; a++)
	{
		for (b = 1; b <= x; b++)
		{
			if (!(a %b) && a * b > x && a / b < x)
			{
				cout << a << ' ' << b;
				return 0;
			}
				
		}
	}
	cout<<-1;
}