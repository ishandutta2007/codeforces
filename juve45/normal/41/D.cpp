#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1

using namespace std;


char s[12][120][122];
int dp[12][120][122], st[12][122][122];
int mat[122][122], n, k, m, K;

int main()
{
	string str;
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> k;
	K = k+1;

	for(int j = 1; j <= m; j++)
		for(int l = 0; l <= k; l++)
			dp[l][n][j] = -2;

	for(int i=1;i<=n;i++)
	{
		cin >> str;
		for(int j=0;j<m;j++)
		{
			mat[i][j+1] = str[j] - '0';
			//, dp[mat[i][j+1]%()k+1][i][j+1] = mat[i][j+1];
			if(i == n)
				dp[mat[i][j+1] % K][i][j+1] = mat[i][j+1];
		}
	}
	for(int i = n-1; i > 0; i--)
	{
		for(int j = 1; j <= m; j++)
		{
			for(int l = 0; l <= k; l++)
			{
				int op = l - mat[i][j];
				op %= K;
				if(op < 0)
					op += K;
				dp[l][i][j] = -2;
				if(j > 1 && dp[op][i+1][j-1] != -2)
					if(dp[l][i][j] < dp[op][i+1][j-1] + mat[i][j])
						{
							dp[l][i][j] = dp[op][i+1][j-1] + mat[i][j];
							s[l][i][j] = 'R';//Am venit din dreapta.
						}


				if(j < m && dp[op][i+1][j+1] != -2)
					if(dp[l][i][j] < dp[op][i+1][j+1] + mat[i][j])
						{
							dp[l][i][j] = dp[op][i+1][j+1] + mat[i][j];
							s[l][i][j] = 'L';//Am venit din stanga.
						}
			}
		}
	}

	int col = 1;

	for(int j = 1; j <= m; j++)
	{
		if(dp[0][1][col] < dp[0][1][j])
		 col = j;
	}

	if(dp[0][1][col] < 0) 
	{
		cout << -1;
		return 0;
	}
	cout << dp[0][1][col] << '\n' ;
	//cout << col << '\n' ;
	int lin = 1;
	int r = 0;
	str = "";
	while(lin < n)
	{
		str += s[r][lin][col];
		int r2 = r;
		r -= mat[lin][col];
		r %= K;
		if(r < 0)
			r += K;
		if(s[r2][lin][col] == 'L') col++;
		else col--;
		lin++;
	}
	cout << col << '\n' ;
	reverse(str.begin(), str.end());
	cout << str << '\n';

}