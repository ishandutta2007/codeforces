#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
int dp[110][2];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string S;
		cin>>S;
		for(int i=0;i<=S.length();i++)
			dp[i][0]=dp[i][1]=1e9;
		dp[0][1]='0';
		for(int i=0;i<S.length();i++)
		{
			if(min(dp[i][0],dp[i][1])<=S[i])
				dp[i+1][1]=S[i];
			dp[i+1][0]=dp[i][1];
		}
		int ans=min(dp[S.length()][0],dp[S.length()][1]);
		if(ans==1e9)
			puts("NO");
		else	puts("YES");
	}
	return 0;
}