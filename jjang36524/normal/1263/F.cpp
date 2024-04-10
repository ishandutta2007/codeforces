#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int dp[2002][2][2002];
int dpmax[2002][2];
vector<int>toprem[2002];
vector<int>botrem[2002];
int topmin[2002];
int topmax[2002];
int botmin[2002];
int botmax[2002];
int toppar[2002];
int botpar[2002];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int a;
	cin >> a;
	int i;
	for (i = 2; i <= a; i++)
	{
		int x;
		cin >> x;
		toppar[i] = x;
		topmin[i] = 2000;
		topmax[i] = 0;
	}
	for (i = 1; i <= N; i++)
	{
		int nowpos;
		cin >> nowpos;
		while (nowpos != 1)
		{
			topmin[nowpos] = min(i, topmin[nowpos]);
			topmax[nowpos] = max(i, topmax[nowpos]);
			nowpos = toppar[nowpos];
		}
	}
	int b;
	cin >> b;
	for (i = 2; i <= b; i++)
	{
		int x;
		cin >> x;
		botpar[i] = x;
		botmin[i] = 2000;
		botmax[i] = 0;
	}
	for (i = 1; i <= N; i++)
	{
		int nowpos;
		cin >> nowpos;
		while (nowpos != 1)
		{
			botmin[nowpos] = min(i, botmin[nowpos]);
			botmax[nowpos] = max(i, botmax[nowpos]);
			nowpos = botpar[nowpos];
		}
	}
	for (i = 2; i <= a; i++)
	{
		toprem[topmax[i]].push_back(topmin[i]);
	}
	for (i = 2; i <= b; i++)
	{
		botrem[botmax[i]].push_back(botmin[i]);
	}
	for (i = 1; i <= N; i++)
	{
		sort(toprem[i].begin(), toprem[i].end());
		sort(botrem[i].begin(), botrem[i].end());
	}
	for (i = 1; i <= N; i++)
	{
		int j;
		int rem = toprem[i].size();
		for (j = 1; j <= i; j++)
		{
			if(i==j)
				dp[i][0][j] = max(dp[i][0][j], dpmax[j - 1][1] + rem);
			else
				dp[i][0][j] = max(dp[i][0][j], dp[i-1][0][j] + rem);
			dpmax[i][0] = max(dpmax[i][0], dp[i][0][j]);
			while (rem&&toprem[i][toprem[i].size() - rem] == j)
				rem--;
		}
		rem = botrem[i].size();
		for (j = 1; j <= i; j++)
		{
			if (i == j)
				dp[i][1][j] = max(dp[i][1][j], dpmax[j - 1][0] + rem);
			else
				dp[i][1][j] = max(dp[i][1][j], dp[i - 1][1][j] + rem);
			dpmax[i][1] = max(dpmax[i][1], dp[i][1][j]);
			while (rem&&botrem[i][botrem[i].size() - rem] == j)
				rem--;
		}
	}
	cout << max(dpmax[N][0], dpmax[N][1]);
}