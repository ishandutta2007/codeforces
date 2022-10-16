#include <iostream>
#include <algorithm>
using namespace std;
int t, a, b, c,d,e;
int ans;
int main()
{
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> a >> b >> c>>d>>e;
		int i,j;
		for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 100; j++)
			{
				if (i > b || j > c)
					continue;
				if ((i + j) * 2 > a)
					continue;
				ans = max(ans, i*d + j * e);
			}
		}
		cout << ans << endl;
	}
}