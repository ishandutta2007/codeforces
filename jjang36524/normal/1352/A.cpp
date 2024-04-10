#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int T, a, b, c, d;
int main()
{
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		int l = s.length();
		int i;
		int a = 0;
		for (i = 0; i < l; i++)
		{
			if (s[i] == '0')
				continue;
			a++;
		}
		cout << a << '\n';
		for (i = 0; i < l; i++)
		{
			if (s[i] == '0')
				continue;
			cout << s[i];
			int j;
			for (j = i + 1; j < l; j++)
			{
				cout << '0';
			}
			cout << ' ';
		}
		cout << '\n';
	}
}