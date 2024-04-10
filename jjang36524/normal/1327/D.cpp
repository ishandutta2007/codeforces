#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define int long long
using namespace std;
int vis[200100];
int p[200100], c[200100];
int tru[200100];
vector<int>t;
int N,T;
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		for (i = 1; i <= N; i++)
		{
			cin >> p[i];
		}	
		for (i = 1; i <= N; i++)
			cin >> c[i];
		int ans = N;
		for (i = 1; i <= N; i++)
		{
			if (vis[i])
				continue;
			t.clear();
			int n = i;
			while (1)
			{
				vis[n] = 1;
				t.push_back(n);
				n = p[n];
				if (vis[n])
					break;
			}
			int i;
			for (i = 0; i < t.size(); i++)
				if (t[i] == n)
					break;
			if (i == t.size())
				continue;
			int s = i;
			int j;
			for (j = 1; j <= t.size()-s; j++)
			{
				if ((t.size() - s) % j)
					continue;
				int k;
				int tot = 0;
				for (k = s; k < t.size(); k++)
				{
					if (c[t[k]] != c[t[(k + j) % (t.size() - s) + s]] && tru[k % j] == 0)
					{
						tot++;
						tru[k % j] = 1;
					}
				}
				if(tot!=j)
					ans = min(ans, j);
				for (k = 0; k < j; k++)
					tru[k] = 0;
			}
		}
		cout << ans << '\n';
		for (i = 1; i <= N; i++)
		{
			vis[i] = 0;
		}
	}
}