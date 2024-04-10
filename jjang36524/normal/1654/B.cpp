#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[26];
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		memset(c, 0, sizeof(c));
		int i;
		for (i = 0; i < s.size(); i++)
		{
			c[s[i]-'a']++;
		}
		int v = 0;
		for (i = 0; i < s.size(); i++)
		{
			c[s[i] - 'a']--;
			if (c[s[i] - 'a'] == 0)
				v = 1;
			if (v)
				cout << s[i];
		}
		cout << '\n';
	}
}