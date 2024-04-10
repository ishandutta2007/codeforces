#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
string s;
char res[105];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		cin >> s;
		int i;
		memset(res, 0, sizeof(res));
		int l = s.length();
		int d=0, e=0, f=0;
		for (i = 0; i < l; i++)
		{
			if (s[i] == 'R')
				d++;
			else if (s[i] == 'P')
				e++;
			else
				f++;
		}
		int ans = min(a, f) + min(b, d) + min(c, e);
		if (ans >= (n + 1) / 2)
		{
			cout << "YES"<<'\n';
			for (i = 0; i < l; i++)
			{
				if (s[i] == 'R')
				{
					if (b)
					{
						b--;
						res[i] = 'P';
					}
				}
				else if (s[i] == 'P')
				{
					if (c)
					{
						c--;
						res[i] = 'S';
					}
				}
				else
				{
					if (a)
					{
						a--;
						res[i] = 'R';
					}
				}
			}
			for (i = 0; i < l; i++)
			{
				if (!res[i])
				{
					if (a)
					{
						a--;
						res[i] = 'R';
					}
					else if (b)
					{
						b--;
						res[i] = 'P';
					}
					else
					{
						c--;
						res[i] = 'S';
					}
				}
			}
			cout << res << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}