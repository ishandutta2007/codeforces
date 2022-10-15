#include<bits/stdc++.h>
using namespace std;
int DP[550][550];
int diff[550],sz;
string S;
int n;
void chmin(int &a,int b)
{
	a=min(a,b);
}
int main()
{
	cin>>n>>S;
//	S+="0";
	for(int i=1;i<n;i++)
		if(S[i-1]!=S[i])
			diff[++sz]=i;
	for(int i=0;i<550;i++)
		for(int j=0;j<550;j++)
			DP[i][j]=n+n;
	for(int i=0;i<=n;i++)
		DP[i][i]=0;
	for(int len=1;len<=n;len++)
		for(int i=n-len;i>=0;i--)
		{
			int j=i+len;
			chmin(DP[i][j],1+DP[i+1][j]);
			for(int k=i+1;k<=n;k++)
				if(S[i]==S[k])
					chmin(DP[i][j],DP[i+1][k]+DP[k][j]);
		}
	cout<<DP[0][n]<<endl;
	return 0;
}