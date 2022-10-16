#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define int long long
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		vector<int>aa, bb;
		int i;
		int N;
		cin >> N;
		double ans=0;
		for (i = 0; i < 2 * N; i++)
		{
			int a, b;
			cin >> a >> b;
			if (a == 0)
			{
				bb.push_back(abs(b));
			}
			else
			{
				aa.push_back(abs(a));
			}
		}
		sort(aa.begin(), aa.end());
		sort(bb.begin(), bb.end());
		for (i = 0; i < N; i++)
		{
			ans += sqrt(aa[i] * aa[i] + bb[i] * bb[i]);
		}
		cout.precision(20);
		cout << ans<<'\n';
	}
}