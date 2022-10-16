#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int T, a, b, c, d;
int coun[8010];
int psum[8010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> a;
		if (a < 4)
		{
			cout << -1 ;
		}
		else
		{
			int p = (a+1) / 2 * 2-1;
			int i;
			for (i = p; i>0; i -= 2)
			{
				cout << i<< ' ';
			}
			cout << 4 << ' ' << 2 << ' ';
			for (i = 6; i <= a; i += 2)
			{
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}