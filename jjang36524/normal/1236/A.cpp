#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		int i, j;
		for (i = 0; i <= b; i++)
		{
			for (j = 0; j <= b; j++)
			{
				if (i <= a && (2 * i + j) <= b && 2 * j <= c)
				{
					ans = max(ans, 3 * (i + j));
				}
			}
		}
		cout << ans << '\n';
	}
}