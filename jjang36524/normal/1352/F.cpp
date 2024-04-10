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
		cin >> a >> b >> c;
		if (b == 0)
		{
			if (c)
			{
				int i;
				for (i = 0; i <= c; i++)
					cout << 1;
			}
			else
			{
				int i;
				for (i = 0; i <= a; i++)
					cout << 0;
			}
		}
		else
		{
			int i;
			for (i = 0; i <= b; i++)
			{
				cout << i % 2;
				if (i == 0)
				{
					int j;
					for (j = 0; j < a; j++)
					{
						cout << 0;
					}
				}
				if (i == 1)
				{
					int j;
					for (j = 0; j < c; j++)
					{
						cout << 1;
					}
				}
			}
		}
		cout << '\n';
	}
}