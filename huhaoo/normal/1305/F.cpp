/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-03 23:25:05
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
i64 read()
{
	i64 r=0,t=1,c=getchar();
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
const int N=200010,M=2000010;
i64 n,a[N],m=2000000,p[M],c,v[M],ans;
i64 solve(i64 p)
{
	i64 ans=0;
	fr(i,1,n)
		if(a[i]<=p) ans+=p-a[i];
		else ans+=std::min(a[i]%p,p-a[i]%p);
	return ans;
}
i64 Solve(i64 v)
{
	i64 ans=n;
	for(int i=1;p[i]*p[i]<=v;i++) if(v%p[i]==0)
	{
		ans=std::min(ans,solve(p[i]));
		while(v%p[i]==0) v/=p[i];
	}
	if(v!=1) ans=std::min(ans,solve(v));
	return ans;
}
int main()
{
	n=read();
	fr(i,1,n) a[i]=read();
	std::random_shuffle(a+1,a+n+1);
	fr(i,2,m)
	{
		if(!v[i]) p[++c]=i;
		fr(j,1,c)
			if(i*p[j]<=m)
			{
				v[i*p[j]]=1;
				if(i%p[j]==0) break;
			}
			else break;
	}
	ans=n;
	fr(i,1,std::min(60ll,n))
	{
		if(a[i]>1) ans=std::min(ans,Solve(a[i]-1));
		ans=std::min(ans,Solve(a[i]));
		ans=std::min(ans,Solve(a[i]+1));
	}
	printf("%I64d\n",ans);
	return 0;
}