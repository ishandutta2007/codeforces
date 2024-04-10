#include <bits\stdc++.h>
using namespace std;

string s;

int n,m,i,j;

bool dp[1005][2007];
char par[1005][2007];
int par2[1005][2007];

void print(int x,int y)
{
	if (!x) return;
	print(x-1,par2[x][y]);
	cout<<par[x][y];
}
int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m>>s;
	s=" "+s;
	
	dp[0][1002]=1;
	for (i=1;i<=n;i++)
	{
		for (j=1002-m+(i!=n);j<=1002+m-(i!=n);j++)
		{
			if (dp[i-1][j]&&(s[i]=='D'||s[i]=='?'))
			{
				dp[i][j]=1;
				par[i][j]='D';
				par2[i][j]=j;
			}
			if (dp[i-1][j-1]&&(s[i]=='W'||s[i]=='?'))
			{
				dp[i][j]=1;
				par[i][j]='W';
				par2[i][j]=j-1;
			}
			if (dp[i-1][j+1]&&(s[i]=='L'||s[i]=='?'))
			{
				dp[i][j]=1;
				par[i][j]='L';
				par2[i][j]=j+1;
			}
		}
	}
	
	if (dp[n][1002-m]) {print(n,1002-m);return 0;}
	if (dp[n][1002+m]) {print(n,1002+m);return 0;}
	cout<<"NO\n";
	return 0;
}