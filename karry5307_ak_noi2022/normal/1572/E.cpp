#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct pnt
{
	long long x,y;pnt(long long _x=0,long long _y=0):x(_x),y(_y){}
}P[300];

long long operator*(pnt A,pnt B){return A.x*B.y-A.y*B.x;}
long long area(pnt A,pnt B,pnt C){return A*B+B*C+C*A;}

pair<int,long long> dp[300][300];long long sz[300][300];

int main()
{
	int n=0,k=0;scanf("%d%d",&n,&k);k++;for(int i=1;i<=n;i++)scanf("%lld%lld",&P[i].x,&P[i].y);
	
	for(int l=1;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)sz[l][r]=sz[l][r-1]+P[r-1]*P[r];
		for(int r=l+1;r<=n;r++)sz[l][r]+=P[r]*P[l];
	}
	long long S=0;for(int i=1;i<n;i++)S+=P[i]*P[i+1];S+=P[n]*P[1];//printf("%lld\n",S);
	long long L=0,R=S/k;
	while(L<R)
	{
		long long x=(L+R+1)>>1;memset(dp,0,sizeof(dp));
		//printf("CALC: %lld %lld %lld\n",L,R,x);
		for(int len=3;len<=n;len++)
		{
			for(int l=1;l+len-1<=n;l++)
			{
				int r=l+len-1;
				if(sz[l][r]<x)continue;
				dp[l][r]=make_pair(1,0);
				for(int k=l+1;k<=r-1;k++)
				{
					pair<int,long long> val=make_pair(dp[l][k].first+dp[k][r].first,dp[l][k].second+dp[k][r].second+area(P[l],P[k],P[r]));
					if(val.second>=x)val.first++,val.second=0;
					dp[l][r]=max(dp[l][r],val);
				}
				//printf("%d %d %d\n",l,r,dp[l][r]);
			}
		}
		if(dp[1][n].first>=k)L=x;else R=x-1;
	}
	printf("%lld",L);
}