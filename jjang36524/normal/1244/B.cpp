#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c, d, e, t;
char arr[2019];
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> a;
		int i;
		int has1=0, ans=0;
		cin >> arr;
		for (i = 0; i < a; i++)
		{
			arr[i] -= '0';
			if (arr[i])
			{
				has1 = 1;
				ans = max({ ans,(i + 1) * 2, (a + 1) * 2 - (i + 1) * 2 });
			}
		}
		if (has1)
			cout << ans << '\n';
		else
			cout << a << '\n';
	}
	
}