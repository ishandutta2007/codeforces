#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[2][10002];
ll x[5002][2];
ll wot[10002];
int _, n;

void compress()
{
	map<int, int> use;
	for (int i = 0;i < n;i++)
		use[x[i][0]], use[x[i][1]];
	for (auto it = use.begin();it != use.end();it++)
		wot[it->second=_++] = it->first;
	for (int i = 0;i < n;i++)
		x[i][0] = use[x[i][0]], x[i][1] = use[x[i][1]];
}

int main()
{
	cin.sync_with_stdio(false);
	cin >> n >> x[0][0];
	x[0][1] = x[0][0];
	for (int i = 1;i <= n;i++)
		cin >> x[i][0] >> x[i][1];
	n++;
	compress();
	for (int at = n-1;at >= 1;at--)
	{
		int me = at&1, ot = me^1;
		for (int wh = x[at][0];wh <= x[at][1];wh++)
			dp[me][wh] = dp[ot][wh];
		ll best = dp[ot][x[at][0]];
		for (int wh = x[at][0]-1;wh >= 0;wh--)
		{
			best = min(best, dp[ot][wh]);
			dp[me][wh] = wot[x[at][0]] - wot[wh] + best;
		}
		best = dp[ot][x[at][1]];
		for (int wh = x[at][1]+1;wh < _;wh++)
		{
			best = min(best, dp[ot][wh]);
			dp[me][wh] = wot[wh] - wot[x[at][1]] + best;
		}
	}
	cout << dp[1][x[0][0]] << endl;
	return 0;
}