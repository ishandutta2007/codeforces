#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int t;
long long n, a, b;
char str[200200];
vector<int>se0;
long long ans;
int is1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		ans = 0;
		is1 = 0;
		memset(str, 0, 200200);
		cin >> n >> a >> b;
		cin >> str;
		int i;
		int l = strlen(str);
		se0.clear();
		for (i = 0; i < n; i++)
		{
			if (i&&str[i] == '0'&&str[i - 1] == '1')
			{
				se0.push_back(i);
			}
			if (i&&str[i] == '1'&&str[i - 1] == '0')
			{
				se0.push_back(i);
			}
			if (str[i] == '1')
				is1 = 1;
		}
		ans += (a + b)*n;
		if (is1)
		{
			ans += a * 2;
		}
		
		ans += b;
		for (i = 0; se0.size()&&i < se0.size()-1; i++)
		{
			if (!(i % 2))
			{
				ans += b * (se0[i+1] - se0[i]+1);
			}
			else
			{
				long long plan1 = b * (se0[i + 1] - se0[i]-1);
				if (se0[i + 1] - se0[i] == 1)
				{
					ans += plan1;
				}
				else
				{
					ans += min(plan1, 2 * a);
				}
			}
		}
		cout << ans << '\n';
	}
}