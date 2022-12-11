#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005,MAX=200005,MAXK=2005,MOD=1000000007;

struct cell
{
	int r,c;
}a[MAXK];

int fac[MAX],inv_fac[MAX],dp[20][MAXK];

bool cmp(const cell &a,const cell &b)
{
	return a.r!=b.r?a.r<b.r:a.c<b.c;
}

int get_d(int s)
{
	int d=0;
	while (s!=1)
	{
		s=(s+1)/2;
		d++;
	}
	return d;
}

int C(int n,int m)
{
	return (LL)fac[n]*inv_fac[m]%MOD*inv_fac[n-m]%MOD;
}

int calc(int r,int c)
{
	return C(r+c,r);
}

int get_inv(int x)
{
	if (x==1) return 1;
	return (LL)(MOD-MOD/x)*get_inv(MOD%x)%MOD;
}

int main()
{
	fac[0]=1;
	for (int i=1;i<=200000;i++)
		fac[i]=(LL)fac[i-1]*i%MOD;
	inv_fac[0]=inv_fac[1]=1;
	for (int i=2;i<=200000;i++)
		inv_fac[i]=(LL)(MOD-MOD/i)*inv_fac[MOD%i]%MOD;
	for (int i=2;i<=200000;i++)
		inv_fac[i]=(LL)inv_fac[i-1]*inv_fac[i]%MOD;
	int n,m,k,s;
	scanf("%d%d%d%d",&n,&m,&k,&s);
	int d=get_d(s);
	for (int i=0;i<k;i++)
		scanf("%d%d",&a[i].r,&a[i].c);
	sort(a,a+k,cmp);
	a[k]={n,m};
	for (int i=0;i<d;i++)
		for (int j=0;j<=k;j++)
		{
			dp[i][j]=calc(a[j].r-1,a[j].c-1);
			for (int u=0;u<i;u++)
				dp[i][j]=(dp[i][j]-dp[u][j]+MOD)%MOD;
			for (int u=0;u<j;u++)
				if (a[u].c<=a[j].c)
					dp[i][j]=(dp[i][j]-(LL)dp[i][u]*calc(a[j].r-a[u].r,a[j].c-a[u].c)%MOD+MOD)%MOD;
		}
	int sum=0;
	for (int i=0;i<d;i++)
	{
		sum=(sum+(LL)s*dp[i][k])%MOD;
		s=(s+1)/2;
	}
	int road=calc(n-1,m-1),q=get_inv(road);
	for (int i=0;i<d;i++)
		road=(road-dp[i][k]+MOD)%MOD;
	sum=(sum+road)%MOD;
	sum=(LL)sum*q%MOD;
	printf("%d",sum);
	return 0;
}