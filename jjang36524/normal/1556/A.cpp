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
		if (a > b)
			swap(a, b);
		if ((b - a) % 2)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << (b&&b) + (a != b) << '\n';
		}
	}
}