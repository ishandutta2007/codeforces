#include <iostream>
#include <algorithm>
using namespace std;
int T;
int a, b, c, d;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		if (a * 2 > b)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}