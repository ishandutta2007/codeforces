#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#define int long long
using namespace std;
string s, t;
int T;
vector<int>arr[26];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> s >> t;
		int sl = s.length();
		int tl = t.length();
		int i;
		int j;
		for (i = 0; i < sl; i++)
		{
			if (i==0)
			{
				for (j = 0; j < 26; j++)
				{
					arr[j].push_back(s[0] - 'a' == j);
				}
			}
			else
			{
				for (j = 0; j < 26; j++)
				{
					arr[j].push_back(arr[j][i-1]+(s[i] - 'a' == j));
				}
			}
		}
		int ans = 1;
		int pos = -1;
		for (i = 0; i < tl; i++)
		{
			if (pos == -1)
			{
				int k = lower_bound(arr[t[i] - 'a'].begin(), arr[t[i] - 'a'].end(), 1)-arr[t[i]-'a'].begin();
				if (k == arr[t[i] - 'a'].size())
				{
					cout << -1 << '\n';
					goto T;
				}
				else
				{
					pos = k;
				}
			}
			else
			{
				int k = lower_bound(arr[t[i] - 'a'].begin(), arr[t[i] - 'a'].end(),arr[t[i]-'a'][pos]+ 1) - arr[t[i] - 'a'].begin();
				if (k == arr[t[i] - 'a'].size())
				{
					pos = -1;
					i--;
					ans++;
				}
				else
				{
					pos = k;
				}
			}
		}
		cout << ans << '\n';
	T:
		for (i = 0; i < 26; i++)
			arr[i].clear();
	}
}