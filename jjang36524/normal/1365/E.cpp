#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
vector<pair<int, int>>x;
vector<pair<int, int>>y;
int a[501][2];
int t[1001];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int i;
	int ans = 0;
	int r = 0;
	for (i = 0; i < T; i++)
	{
		cin >> t[i];
		r |= t[i];
		int j, k;
		for (j = 0; j < i; j++)
		{
			for (k = 0; k < j; k++)
			{
				ans = max(ans, t[i] | t[j] | t[k]);
			}
		}
	}
	if (T < 3)
		ans = r;
	cout << ans;
}