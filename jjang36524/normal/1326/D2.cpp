#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
int sum[2000100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> s;
		string ns;
		string olds;
		olds = s;
		int l = s.length();
		int i;
		for (i = 0; i < l; i++)
		{
			if (i)
				ns.push_back('#');
			ns.push_back(s[i]);
		}
		s = ns;
		l = s.length();
		for (i = 0; i < l / 2; i++)
		{
			if (s[i] != s[l - i - 1])
				break;
		}
		if (i == l / 2)
		{
			cout << olds << '\n';
			continue;
		}
		int t;
		int j;
		pair<int, int>m = { i,-i };

		for (j = i; j < l-i; j++)
		{
			if (j == i)
				continue;
			if (j <= m.first)
				sum[j] = min(m.first - j, sum[2 * m.second - j]);
			else
				sum[j] = 0;
			while ((j - sum[j]-1 >= i) && (j + sum[j]+1 < l-i) && s[j + sum[j] + 1] == s[j - sum[j] - 1])
				sum[j]++;
			m = max(m, { j + sum[j],j });
		}
		pair<int, pair<int, int>>ty = { 0,{0,0} };
		for (j = i; j < l - i; j++)
		{
			if (j - sum[j] <= i)
				ty = max(ty, make_pair( sum[j],make_pair(j,0) ));
			if (j + sum[j] >=l-i-1)
				ty = max(ty, make_pair(sum[j], make_pair(j, 0)));
		}
		for (j = 0; j < l; j++)
		{
			if (j % 2)
				continue;
			if (j < i || j + i >= l)
				cout << s[j];
			else if (j >= -ty.first + ty.second.first && j <= ty.first + ty.second.first)
				cout << s[j];
		}
		for (j = 0; j < l; j++)
			sum[j] = 0;
		cout << '\n';
		s.clear();
	}
}