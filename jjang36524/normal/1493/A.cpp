#include <algorithm>
#include <iostream>
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
		int c = (b + 1) / 2;
		cout << a - c << '\n';
		int i;
		for (i = c; i <= a; i++)
		{
			if (i != b)
				cout << i << ' ';
		}
		cout << '\n';
	}
}