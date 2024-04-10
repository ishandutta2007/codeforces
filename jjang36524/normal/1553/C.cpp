#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		int i;
		int ans = 10;
		for (i = 0; i < 1024; i++)
		{
			string ns = s;
			int j;
			for (j = 0; j < 10; j++)
			{
				if (ns[j] == '1' && (!(i & (1 << j))))
				{
					break;
				}
				else if(ns[j] == '0' && ((i & (1 << j))))
				{
					break;
				}
				else if (ns[j] == '?')
				{
					ns[j] = (i & (1 << j)) ? '1' : '0';
				}
			}
			if (j != 10)
				continue;
			int f = 0;
			int s = 0;
			int pf = 5;
			int ps = 5;
			for (j = 0; j < 10; j++)
			{
				if (j % 2)
				{
					if (ns[j] == '1')
					{
						s++;
						
					}
					else
					{
						ps--;
					}
				}
				else
				{
					if (ns[j] == '1')
					{
						f++;
						
					}
					else
					{
						pf--;
					}
				}
				if (pf < s)
					break;
				if (ps < f)
					break;
			}
			ans = min(ans, j + 1);
		}
		cout << ans << '\n';
	}
}