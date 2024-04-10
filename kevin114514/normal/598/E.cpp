#include<bits/stdc++.h>
using namespace std;
long long DP[33][33][55];
int main()
{
	for(int i=0;i<33;i++)
		for(int j=0;j<33;j++)
			for(int k=0;k<55;k++)
				DP[i][j][k]=1e18;
	for(int i=1;i<=30;i++)
		for(int j=1;j<=30;j++)
		{
			if(i*j<=50)
				DP[i][j][i*j]=0;
			DP[i][j][0]=0;
			for(int k=1;k<i;k++)
				for(int l=0;l<=min(i*j,50);l++)
					for(int m=0;m+l<=min(i*j,50);m++)
						if(l<=k*j&&m<=(i-k)*j)
							DP[i][j][l+m]=min(DP[i][j][l+m],DP[k][j][l]+DP[i-k][j][m]+j*j);
			for(int k=1;k<j;k++)
				for(int l=0;l<=min(i*j,50);l++)
					for(int m=0;m+l<=min(i*j,50);m++)
						if(l<=k*i&&m<=i*(j-k))
							DP[i][j][l+m]=min(DP[i][j][l+m],DP[i][k][l]+DP[i][j-k][m]+i*i);
		}
	int t;
	cin>>t;
	while(t--)
	{
		int N,M,K;
		cin>>N>>M>>K;
		cout<<DP[N][M][K]<<endl;
	}
	return 0;
}