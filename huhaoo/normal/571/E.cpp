/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-04 14:43:03
****************************************************************/
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define i64 long long
const i64 mod=1000000007,inf=1ll<<60,N=110;
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 calc(i64 a,int b)
{
	i64 s=(i64)(pow(a,1./b)+0.5);
	return power(s,b,inf)==a?s:0;
}
i64 n,a[N],b[N],c[N],d[N];
i64 v[N];
i64 gcd(i64 a,i64 b){ return b?gcd(b,a%b):a; }
i64 split(i64 a,i64 p)
{
//	printf("%I64d\n",a);
	fr(i,1,p)
	{
		i64 g;
		if(v[i]!=1&&(g=gcd(a,v[i]))!=1){ v[i]/=g; a/=g; }
		if(a==1) return 1;
	}
	return 0;
}
i64 checkv(i64 p){ fr(i,1,p) if(v[i]!=1) return 0; return 1; }
i64 check(i64 a,i64 b,i64 p,i64 A,i64 B)
{
	p++; v[1]=a;
	fr(i,2,p) v[i]=b;
	if(!split(A,p)) return 0;
	if(!checkv(p)&&B==1) return 0;
	while(!checkv(p)) if(!split(B,p)) return 0;
//	printf("%I64d %I64d %I64d %I64d %I64d\n",a,b,p,A,B);
	return 1;
}
i64 check(i64 A,i64 B,i64 p)
{
	fr(i,1,n) if(!check(A,B,p,a[i],b[i])) return 0;
	return 1;
}
#include<map>
// a(b^c)(b^d)^i
// c+di==
int main()
{
	n=read();
	fr(i,1,n){ a[i]=read(); b[i]=read(); }
	int flag=0;
	fr(i,1,n) if(b[i]==1) flag=1;
	if(flag)
	{
		fr(i,1,n) if(b[i]==1)
		{
			if(check(a[i],b[i],0)) printf("%I64d\n",a[i]);
			else printf("-1\n");
			return 0;
		}
	}
	fr(i,1,n)
	{
		fd(j,29,0) if(calc(b[i],j))
		{
			d[i]=j; b[i]=calc(b[i],j);
			break;
		}
		while(a[i]%b[i]==0){ a[i]/=b[i]; c[i]++; }
	}
	fr(i,2,n) if(b[i]!=b[1])
	{
		fr(j,1,n){ a[j]=a[j]*power(b[j],c[j],inf); b[j]=power(b[j],d[j],inf); }
		fr(j,0,100) if(check(a[1],b[1],j,a[i],b[i]))
		{
			if(check(a[1],b[1],j)) printf("%I64d\n",power(b[1],j,mod)*a[1]%mod);
			else printf("-1\n");
			return 0;
		}
		printf("-1\n");
		return 0;
	}
	fr(i,2,n) if(a[i]!=a[1]){ printf("-1\n"); return 0; }
	i64 ans=c[1],Ans=d[1];
//	fr(i,1,n) printf("%I64d %I64d\n",c[i],d[i]);
	fr(i,2,n)
	{
		int flag=0;
		fr(j,0,1000) if(ans+Ans*j>=c[i]&&(ans+Ans*j-c[i])%d[i]==0)
		{
			ans+=Ans*j; flag=1; break;
		}
		if(!flag){ printf("-1\n"); return 0; }
		Ans=Ans*d[i]/gcd(Ans,d[i]);
	}
	printf("%I64d\n",a[1]*power(b[1],ans,mod)%mod);
	return 0;
}