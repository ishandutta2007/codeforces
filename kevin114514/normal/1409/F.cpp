#include<bits/stdc++.h>
#define REP(i) for(int i=0;i<220;i++)
using namespace std;
int DP[220][220][220];
int main()
{
	int N,K;
	cin>>N>>K;
	string S,T;
	cin>>S>>T;
	if(T[0]==T[1])
	{
		int cnt=0;
		for(int i=0;i<N;i++)
			if(S[i]==T[0])
				cnt++;
		cnt+=K;
		cnt=min(cnt,N);
		cout<<(cnt-1)*cnt/2<<endl;
		return 0;
	}
	REP(x1)
		REP(x2)
			REP(x3)
				DP[x1][x2][x3]=-1;
	DP[0][0][0]=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=K;k++)
				if(DP[i][j][k]!=-1)
				{
					//cout<<i<<" "<<j<<" "<<k<<" "<<DP[i][j][k]<<endl;
					DP[i+1][j+1][k+1]=max(DP[i+1][j+1][k+1],DP[i][j][k]);
					DP[i+1][j][k+1]=max(DP[i+1][j][k+1],DP[i][j][k]+j);
					if(S[i]==T[0])
						DP[i+1][j+1][k]=max(DP[i+1][j+1][k],DP[i][j][k]);
					if(S[i]==T[1])
						DP[i+1][j][k]=max(DP[i+1][j][k],DP[i][j][k]+j);
					DP[i+1][j][k]=max(DP[i+1][j][k],DP[i][j][k]);
				}
	int ans=0;
	for(int j=0;j<=N;j++)
		for(int k=0;k<=K;k++)
			if(DP[N][j][k]!=-1)
				ans=max(ans,DP[N][j][k]);
	cout<<ans<<endl;
	return 0;
}