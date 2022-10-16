#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		if ((a+b)%2)
			cout << -1 << ' ' << -1 << '\n';
		else
		{
			if (a > b)
			{
				cout << (a+b) / 2 << ' ' << 0 << '\n';
			}
			else
			{
				cout << 0 << ' ' << (a + b) / 2 << '\n';
			}
		}
			
	}
}