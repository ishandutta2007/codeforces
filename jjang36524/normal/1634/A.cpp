#include <bits/stdc++.h>
using namespace std;
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >>N>> K;
		string s;
		cin >> s;
		int i;
		int p = 1;
		for (i = 0; i <= s.size() / 2; i++)
		{
			if (s[i] != s[s.size() - 1 - i])
				p = 0;
		}
		if (p == 1 || K == 0)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 2 << '\n';
		}
	}
}