#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int anns[200100];
vector<int>x[200100];
int cur[30];
int tot[30];
int mul[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n>>k;
		int i;
		mul[0] = 1;
		for (i = 0; i < n; i++)
		{
			x[i].clear();
			mul[i + 1] = mul[i] * 2 % 1000000007;
		}
		for (i = 0; i < 30; i++)
		{
			cur[i] = 0;
			tot[i] = 0;
		}
		for (i = 0; i < k; i++)
		{
			int a, b,c;
			cin >> a >> b>>c;
			x[a-1].push_back(c);
			x[b].push_back(-c-1);
		}
		for (i = 0; i < n; i++)
		{
			int j;
			for (j = 0; j < x[i].size(); j++)
			{
				if (x[i][j] < 0)
				{
					x[i][j] = -x[i][j];
					x[i][j]--;
					int k;
					for (k = 0; k < 30; k++)
					{
						cur[k] -= (!(x[i][j] & (1 << k)));
					}
				}
				else
				{
					int k;
					for (k = 0; k < 30; k++)
					{
						cur[k] += (!(x[i][j] & (1 << k)));
					}
				}
			}
			for (j = 0; j < 30; j++)
			{
				if (!cur[j])
				{
					tot[j]++;
				}
			}
		}
		int ans = 0;
		for (i = 0; i < 30; i++)
		{
			if (tot[i])
			{
				int cu = mul[tot[i]-1] * mul[n - tot[i]];
				cu %= 1000000007;
				ans += cu*(1<<i);
				ans %= 1000000007;
			}
			
		}
		cout << ans << '\n';
	}
}