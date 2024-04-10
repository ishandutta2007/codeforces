#include <iostream>
#include <algorithm>
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
		string s,t;
		cin >> s>>t;
		sort(s.begin(), s.end());
		if (t == "abc"&& s[0]=='a')
		{
			int i;
			for (i = 0; i < s.size(); i++)
			{
				if (s[i] == 'a' || s[i] == 'c')
					cout << s[i];
			}
			for (i = 0; i < s.size(); i++)
			{
				if (!(s[i] == 'a' || s[i] == 'c'))
					cout << s[i];
			}
			cout << '\n';
		}
		else
			cout << s << '\n';
	}
}