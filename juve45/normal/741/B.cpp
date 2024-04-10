#include <bits/stdc++.h>
#define DMAX 1004
using namespace std;

int w[DMAX], b[DMAX], nrc, c[DMAX], dp[DMAX][DMAX], n, m, ww, use[DMAX], x, y, ans, q[DMAX];
vector <int> v[DMAX], h[DMAX];


void dfs(int k)
{
	use[k] = 1;
	c[nrc] += b[k];
	q[nrc] += w[k];
	h[nrc].push_back(k);
	for(int i=0;i<v[k].size();i++)
		if(!use[v[k][i]]) 
			dfs(v[k][i]);
}

int main()
{
	cin >> n >> m >> ww;	

	for(int i=1;i<=n;i++)
		cin >> w[i];
	for(int i=1;i<=n;i++)
		cin >> b[i];

	for(int i=1;i<=m;i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for(int i=1;i<=n;i++)
	{
		if(!use[i])
		{
			dfs(i);
			nrc++;
		}
	}

	/*
	for(int i=0;i<nrc;i++)
		cout << q[i] << ' ' << c[i] << '\n';
*/

	for(int i=0;i<nrc;i++)
		for(int j=0;j<=ww;j++)
		{
			dp[i+1][j] = dp[i][j];
			if(q[i] <= j)
				dp[i+1][j] = max(dp[i+1][j], dp[i][j-q[i]] + c[i]);	
			for(int l=0;l<h[i].size();l++)
			{
				if(w[h[i][l]] <= j)
					dp[i+1][j] = max(dp[i+1][j], dp[i][ j-w[h[i][l]] ] + b[ h[i][l] ]);
			}
		}
	/*
	for(int i=0;i<=nrc;i++)
	{
		for(int j=0;j<=ww;j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	for(int i=1;i<=ww;i++)
		ans = max(ans, dp[nrc][i]);

	cout << ans;

}