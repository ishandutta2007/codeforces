#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, l, r, k;
		cin >> n >> l >> r >> k;
		int i;
		vector<int>t;
		for (i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (a >= l && a <= r)
				t.push_back(a);
		}
		sort(t.begin(), t.end());
		int c = 0;
		for (i = 0; i < t.size(); i++)
		{
			if (k >= t[i])
			{
				c++;
				k -= t[i];
			}
		}
		cout << c << '\n';
	}
}