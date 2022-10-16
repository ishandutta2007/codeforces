#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;
pair<int, pair<int, int>>t[100100];
int dp[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> M >> N;
	t[0]={ 0,{1,1} };
	
	int i;
	int curm = 0;
	int fm = -(1LL<<30);
	memset(dp, -2, sizeof(dp));
	dp[0] = 0;
	for (i = 1; i <= N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		t[i]={ a,{b,c} };
		int j;
		int r = 0;
		if (i >= 2 * M)
		{
			fm = max(fm, dp[i - 2 * M]);
		}
		dp[i] = fm+1;
		for (j = max(0, i - 2 * M); j < i; j++)
		{
			if (t[i].first - t[j].first >= abs(t[j].second.first - t[i].second.first) + abs(t[j].second.second - t[i].second.second))
				dp[i] = max(dp[i], dp[j] + 1);
		}
		curm = max(curm, dp[i]);
	}
	cout << curm;
}