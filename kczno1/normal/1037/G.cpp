#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e5+5,U=26;
char s[N];
int n,ap[2][N][U],dp[2][N][U],pre_sum[N];//0=>(i,j),1=>(j,i)
int q[U];

int F(int l,int r)
{
	if(l==0&&r==4)
		int yyx=1;
	int s=0;
	rep(c,0,U-1)
	if(ap[1][r-1][c]>l)
		s|=1<<(dp[0][l][c]^dp[1][r][c]^pre_sum[ap[1][r-1][c]]^pre_sum[ap[0][l+1][c]]);
	int i=0;
	while(s&(1<<i))++i;
	return i;	
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n)s[i]-='a';
	rep(i,1,n)
	{
		rep(j,0,U-1)ap[1][i][j]=ap[1][i-1][j];
		ap[1][i][s[i]]=i;
	}
	rep(j,0,U-1)ap[0][n+1][j]=n+1;
	per(i,n,1)
	{
		rep(j,0,U-1)ap[0][i][j]=ap[0][i+1][j];
		ap[0][i][s[i]]=i;
	}
	rep(i,1,n+1)
	{
		rep(j,0,U-1)q[j]=ap[1][i-1][j];
		sort(q,q+U);
		int tail=U-1;
		if(i<=n)
		{
		int i0=ap[1][i-1][s[i]];
		per(j,i-1,i0)
		{
		//	if(i==4&&j==2)
		//		int yyx=1;
			dp[0][j][s[i]]=F(j,i);
			if(j&&j==q[tail]){dp[1][i][s[j]]=dp[0][j][s[i]];--tail;}
		}
		pre_sum[i]=pre_sum[i0]^dp[0][i0][s[i]];
		}
	//	else
	//		int yyx=1;
		for(;tail>=0;--tail)
		{
			int j=q[tail];
			if(!j)break;
			dp[1][i][s[j]]=F(j,i);
		}
	}
	int m;
	cin>>m;
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		puts(F(l-1,r+1)?"Alice":"Bob");
	}
}