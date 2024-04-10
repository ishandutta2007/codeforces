#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int T, N, M, a, b, c, d;
int t[100100];
int ans[100100];
vector<int>p;
int tr = 1000000;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	int po = 0;
	for (i = 0; i < N; i++)
	{
		cin >> t[i];
		ans[i] = tr;
		tr--;
		if ((!i&&t[i])||(i&&(t[i]!=t[i-1])))
		{
			if (!i)
				ans[0] = 0;
			else
			{
				ans[i] = t[i - 1];
				int j;
				for (j = 1; j < t[i]-t[i-1]; j++)
				{
					ans[p[po]] = j + t[i - 1];
					po++;
				}
			}
		}
		else
			p.push_back(i);
	}
	for (i = 0; i < N; i++)
		cout << ans[i] << ' ';
}