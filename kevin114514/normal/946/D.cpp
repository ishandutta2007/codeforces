#include<bits/stdc++.h>
using namespace std;
string curriculum[550];
int DP[550][1050];
int Curriculum[550][550];
int Len[550];
int Minimal[550][550];
int main()
{
	int N,M,K;
	cin>>N>>M>>K;
	for(int i=0;i<N;i++)
		cin>>curriculum[i];
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(curriculum[i][j]=='1')
				Curriculum[i][Len[i]++]=j;
	for(int i=0;i<550;i++)
		for(int j=0;j<550;j++)
			Minimal[i][j]=100000000;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<Len[i];j++)
			for(int k=j+1;k<=Len[i];k++)
				Minimal[i][j+Len[i]-k]=min(Minimal[i][j+Len[i]-k],Curriculum[i][k-1]-Curriculum[i][j]+1);
		Minimal[i][Len[i]]=0;
	}
	for(int i=0;i<=N;i++)
		for(int j=0;j<1050;j++)
			DP[i][j]=100000000;
	DP[0][0]=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<=K;j++)
			for(int k=0;k<=Len[i];k++)
				DP[i+1][j+k]=min(DP[i+1][j+k],DP[i][j]+Minimal[i][k]);
	int Ans=100000000;
	for(int i=0;i<=K;i++)
		Ans=min(Ans,DP[N][i]);
	cout<<Ans<<endl;
	return 0;
}