#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int maxp[200100];
int arr[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N,K;
		cin >> N>>K;
		int i;
		vector<int>a, b;
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			if (x > 0)
			{
				b.push_back(x);
			}
			if (x < 0)
				a.push_back(-x);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int ma = 0;
		int ans = 0;
		for (i = (int)a.size()-1; i>=0; i-=K)
		{
			ma = max(ma, a[i]);
			ans += a[i] * 2;
		}
		for (i = (int)b.size() - 1; i >= 0; i -= K)
		{
			ma = max(ma, b[i]);
			ans += b[i] * 2;
		}
		cout << ans - ma<<'\n';
	}
}