#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[5010][5010];
#include <vector>
vector<int>arrcolor;
int N;
int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (!arrcolor.size() || arrcolor[arrcolor.size() - 1] != a)
			arrcolor.push_back(a);
	}
	memset(dp, 1, sizeof(dp));
	int diff;
	for (i = 0; i < arrcolor.size(); i++)
	{
		dp[i][i] = 0;
	}
	for (diff = 1; diff < arrcolor.size(); diff++)
	{
		for (i = 0; i < arrcolor.size() - diff; i++)
		{
			dp[i][i + diff] = min(dp[i][i + diff - 1], dp[i + 1][i + diff])+1;
			if (arrcolor[i] == arrcolor[i + diff])
				dp[i][i + diff] = min(dp[i][i + diff], dp[i + 1][i + diff - 1] + 1);
		}
	}
	cout << dp[0][arrcolor.size()- 1];
}