/***************************************************************
	File name: F.cpp
	Author: huhao
	Create time: Mon 26 Apr 2021 04:51:49 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define i64 long long
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
const int N=3010,mod=998244353,M=1<<10|10;
int n,c;
int a[N];
int s[N][N];
int f[N][N],g[N];
int p2[N];
int ans[N];
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 inv(i64 a){ return power(a,mod-2,mod); }
int main()
{
	n=read(); c=read();
	fr(i,1,n)
	{
		a[i]=read(); s[i][a[i]]++;
		fr(j,1,c) s[i][j]+=s[i-1][j];
	}
	if(c<=10)
	{
		static int f[N][M],F[N][M];
		f[0][0]=1; int m=n/c;
		fr(i,1,n)
		{
			fr(j,0,m) fr(k,0,(1<<c)-1){ F[j][k]=f[j][k]; f[j][k]=0; }
			fr(j,0,m) fr(k,0,(1<<c)-1)
			{
				f[j][k]=(f[j][k]+F[j][k])%mod;
				if(k&(1<<(a[i]-1))) f[j][k]=(f[j][k]+F[j][k])%mod;
				else
				{
					int K=k|(1<<(a[i]-1));
					if(K==(1<<c)-1) f[j+1][0]=(f[j+1][0]+F[j][k])%mod;
					else f[j][K]=(f[j][K]+F[j][k])%mod;
				}
			}	
		}
		fr(i,0,n) fr(j,0,(1<<c)-1) ans[i]=(ans[i]+f[i][j])%mod;
		ans[0]=(ans[0]-1+mod)%mod;
	}
	else
	{
		f[0][0]=1; p2[0]=1;
		fr(i,1,n) p2[i]=p2[i-1]*2%mod;
		fr(i,0,n-1)
		{
			i64 p=1;
			fr(o,1,c) p=p*(p2[s[n][o]-s[i][o]]-1)%mod;
			if(p) fd(k,n,i+1)
			{
				p=p*inv(p2[s[k][a[k]]-s[i][a[k]]]-1)%mod;
				fr(j,0,n) if(f[i][j]) f[k][j+1]=(f[k][j+1]+p*f[i][j])%mod; else if(j) break;
				p=p*(p2[s[k][a[k]]-s[i][a[k]]-1]-1)%mod; if(!p) break;
			}
		}
		fd(i,n,1)
		{
			i64 p=1;
			fr(o,1,c) p=p*(p2[s[n][o]-s[i][o]]-1)%mod;
			g[i]=(p2[n-i]-p+mod)%mod;
		}
//		fr(i,1,n) fr(j,0,n) printf("%d%c",f[i][j],j==n?'\n':' ');
		fr(i,1,n) fr(j,1,n) ans[j]=(ans[j]+(i64)f[i][j]*g[i])%mod;
		ans[0]=p2[n]-1; fr(i,1,n) ans[0]=(ans[0]-ans[i]+mod)%mod;
	}
	fr(i,0,n) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}