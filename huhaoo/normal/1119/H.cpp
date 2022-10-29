/***************************************************************
	File name: yuyuko.cpp
	Author: huhao
	Create time: Fri 17 Jan 2020 02:07:52 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
#define i64 long long
const int N=1000010,K=20,mod=998244353,i2=(mod+1)/2;
i64 n,m,k,a[K+5],p[N][K+5],x,f[(1<<K)|10],g[(1<<K)|10],h[(1<<K)|10];
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	while(b)
	{
		if(b&1) r=r*a%p;
		a=a*a%p; b>>=1;
	}
	return r;
}
void fwt(i64 *f,int n,int opt)
{
	opt=(opt==1?1:i2);
	fr(i,0,n-1) for(int j=0;j<(1<<n);j+=(1<<(i+1))) fr(k,0,(1<<i)-1)
	{
		i64 x=f[j+k],y=f[j+k+(1<<i)];
		f[j+k]=(x+y)*opt%mod; f[j+k+(1<<i)]=(x-y+mod)*opt%mod;
	}
}
int main()
{
	n=read(); m=read(); k=3;
	fr(i,0,k-1) a[i]=read();
	fr(i,1,n)
	{
		fr(j,0,k-1) p[i][j]=read();
		x^=p[i][0];
		fd(j,k-1,0) p[i][j]^=p[i][0];
	}
	fr(i,0,(1<<m)-1) f[i<<(k-1)]=n;
	fr(i,1,(1<<(k-1))-1)
	{
		fr(j,0,(1<<m)-1) g[j]=0;
		fr(j,1,n)
		{
			i64 s=0;
			fr(l,1,k-1) if((i>>(l-1))&1) s^=p[j][l];
			g[s]++;
		}
//		fr(j,0,(1<<m)-1) printf("%lld%c",g[j],j==end_j?'\n':' ');
		fwt(g,m,1);
//		fr(j,0,(1<<m)-1) printf("%lld%c",g[j],j==end_j?'\n':' ');
		fr(j,0,(1<<m)-1) f[(j<<(k-1))+i]=g[j];
	}
//	fr(i,0,(1<<m)-1) fr(j,0,(1<<(k-1))-1) printf("%lld%c",f[(i<<(k-1))+j],j==end_j?'\n':' ');
	fr(i,0,(1<<m)-1) fwt(f+(i<<(k-1)),k-1,-1);
//	fr(i,0,(1<<m)-1) fr(j,0,(1<<(k-1))-1) printf("%lld%c",f[(i<<(k-1))+j],j==end_j?'\n':' ');
//	fr(i,0,(1<<m)-1) fwt(f+(i<<(k-1)),k-1,1);
//	fr(i,0,(1<<m)-1) fr(j,0,(1<<(k-1))-1) printf("%lld%c",f[(i<<(k-1))+j],j==end_j?'\n':' ');
	fr(i,0,(1<<m)-1)
	{
		h[i]=1;
		fr(j,0,(1<<(k-1))-1)
		{
			i64 s=a[0];
			fr(l,1,k-1)
				if((j>>(l-1))&1) s-=a[l];
				else s+=a[l];
			s=(s%mod+mod)%mod;
			h[i]=(h[i]*power(s,f[(i<<(k-1))+j],mod))%mod;
		}
	}
/*	fr(i,1,n)
	{
		fr(j,0,(1<<m)-1) f[j]=0;
		fr(j,0,k-1) f[p[i][j]]+=a[j];
		fwt(f,m,1);
//		fr(j,0,(1<<m)-1) printf("%lld%c",f[j],j==end_j?'\n':' ');
	}*/
//	fr(i,0,(1<<m)-1) printf("%lld%c",h[i],i==end_i?'\n':' ');
	fwt(h,m,-1);
	fr(i,0,(1<<m)-1) if((i^x)<i) std::swap(h[i],h[x^i]);
	fr(i,0,(1<<m)-1) printf("%lld%c",h[i],i==end_i?'\n':' ');
	return 0;
}