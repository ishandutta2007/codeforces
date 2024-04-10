#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>bes;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		bes.clear();
		int A, B;
		cin >> A >> B;
		string s;
		cin >> s;
		int i;
		int bef = 0;
		int gr = 0;
		for (i = 0; i < s.size(); i++)
		{
			if (s[i] == '.')
				bef++;
			else
			{
				if(bef>=B)
					bes.push_back(bef);
				bef = 0;
			}
		}
		if (bef >= B)
			bes.push_back(bef);
		int ans = 1;
		int c = -1;
		int cnt = 0;
		for (i = 0; i < bes.size(); i++)
		{
			if (bes[i] < A)
				ans = 0;
			if (bes[i] >= 2 * B)
			{
				if (c == -1)
					c = bes[i];
				else
					ans = 0;
			}
			else
				cnt++;
		}
		if (ans == 0)
			cout << "NO"<<'\n';
		else
		{
			ans = 0;

			if (c == -1)
			{
				ans = cnt % 2;
			}
			for (i = A; i <= c; i++)
			{
				int f = i - A;
				int b = c - i;
				if ((f >= B && f < A) || (b >= B && b< A)||(f>=2*B)||(b>=2*B))
					continue;
				if ((cnt + (f >= A) + (b >= A)) % 2 == 0)
				{
					ans = 1;
				}
			}
			if (ans)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
}