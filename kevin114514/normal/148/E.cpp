#include<bits/stdc++.h>
using namespace std;
vector<int> shelf[105];
int Val[105][105],pre[105][105],suf[105][105];
int dp[105][20005];
int main()
{
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		int sz;
		cin>>sz;
		int PreCnt=0;
		for(int j=0;j<sz;j++)
		{
			int x;
			cin>>x;
			shelf[i].push_back(x);
			PreCnt+=x;
			pre[i][j+1]=PreCnt;
		}
		for(int j=1;j<=sz;j++)
			suf[i][j]=PreCnt-pre[i][sz-j];
		for(int j=1;j<=sz;j++)
			for(int k=0;k<=j;k++)
				Val[i][j]=max(Val[i][j],pre[i][k]+suf[i][j-k]);
		for(int j=0;j<20005;j++)
			dp[i][j]=-12345;
	}
	for(int i=0;i<=shelf[0].size();i++)
		dp[0][i]=Val[0][i];
	for(int i=0;i<N-1;i++)
		for(int j=0;j<=M;j++)
			if(dp[i][j]!=-12345)
				for(int k=0;k<=shelf[i+1].size();k++)
					if(j+k<=M)
						dp[i+1][j+k]=max(dp[i+1][j+k],dp[i][j]+Val[i+1][k]);
	cout<<dp[N-1][M]<<endl;
	return 0;		
}