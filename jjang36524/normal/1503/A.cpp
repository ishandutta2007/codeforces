#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int isb(string s)
{
	int cu = 0;
	int i;
	for (i = 0; i < s.size(); i++)
	{
		cu += (s[i] == '(') ? 1 : -1;
		if (cu < 0)
			return 0;
	}
	return !cu;
}
int main()
{
	using namespace std;
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		string s;
		cin >> s;
		string ab, bb;
		int i;
		int c1 = 0;
		for (i = 0; i < N; i++)
		{
			c1 += s[i] == '1';
		}
		if (c1 % 2)
		{
			cout << "NO" << '\n';
			continue;
		}
		int cc1 = c1 / 2;
		int cc2 = 0;
		for (i = 0; i < N; i++)
		{
			if (s[i] == '1')
			{
				if (cc1)
				{
					cc1--;
					ab.push_back('(');
					bb.push_back('(');
				}
				else
				{
					ab.push_back(')');
					bb.push_back(')');
				}
			}
			else
			{
				if (cc2 % 2)
				{
					ab.push_back(')');
					bb.push_back('(');
				}
				else
				{
					bb.push_back(')');
					ab.push_back('(');
				}
				cc2++;
			}
		}
		if (isb(ab) && isb(bb))
		{
			cout << "YES" << '\n' << ab << '\n' << bb << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}