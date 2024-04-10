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
		string l;
		int N,K;
		cin >> N>>K;
		vector<int>t;
		int reqsum = K;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			t.push_back(a);
			reqsum -= a;
		}
		sort(t.begin(), t.end());
		reqsum += t[0];
		int ans = max(0LL,t[0] - reqsum);
		for (i = N - 1; i > 0; i--)
		{
			reqsum += t[i];
			ans = min(ans,max(0LL, max(0LL,t[0] - (reqsum+(1LL<<60)/ (N - i + 1)* (N - i + 1))/(N-i+1)+ ((1LL << 60) / (N - i + 1))) +N-i));
		}
		cout << ans << '\n';
	}
}