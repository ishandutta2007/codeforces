#include <bits/stdc++.h>
using namespace std;
#define int long long
int ma[300100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		
		string s;
		cin >> s;
		memset(ma, -10, s.size()*sizeof(long long)+1024);
		int pl = 0;
		int cn = 0;
		int i;
		vector<int>x;
		for (i = 0; i < s.size(); i++)
		{
			if (s[i] == '?')
			{
				cn++;
				x.push_back(i);
			}
			else
			{
				pl += s[i] == '(';
			}
		}
		int rm = s.size() / 2 - pl;
		if (rm == 0 || rm == x.size())
		{
			cout << "YES" << '\n';
		}
		else
		{
			swap(x[rm - 1], x[rm]);
			for (i = 0; i <x.size(); i++)
			{
				if (i < rm)
				{
					s[x[i]] = '(';
				}
				else
				{
					s[x[i]] = ')';
				}
			}
			int pl = 0;
			for (i = 0; i < s.size(); i++)
			{
				if (s[i] == '?')
				{
					cn++;
					x.push_back(i);
				}
				else
				{
					pl += (s[i] == '(')?1:-1;
				}
				if (pl < 0)
				{
					cout << "YES" << '\n';
					break;
				}
			}
			if (i == s.size())
				cout << "NO" << '\n';
		}
		
	}
}