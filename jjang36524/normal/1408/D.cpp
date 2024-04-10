#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int r[2010][2];
int s[2010][2];
signed main()
{
	int N, M,T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> r[i][0]>>r[i][1];
	}
	for (i = 0; i < M; i++)
	{
		cin >> s[i][0] >> s[i][1];
	}
	vector<pair<int, int>>t;
	vector<pair<int, int>>re;
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < M; j++)
		{
			t.push_back({ max(0LL,s[j][0] - r[i][0] + 1),max(0LL,s[j][1] - r[i][1] + 1) });
		}
	}
	sort(t.begin(), t.end());
	re.push_back({ 0,(1LL << 50) });
	for (i = 0; i < N * M; i++)
	{
		while (re.size() && re[re.size() - 1].second <= t[i].second)
		{
			re.pop_back();
		}
		re.push_back(t[i]);
	}
	re.push_back({ (1LL << 50),0 });
	int ans = (1LL << 50);
	for (i = 1; i < re.size(); i++)
	{
		ans = min(ans, re[i - 1].first + re[i].second);
	}
	cout << ans;
}