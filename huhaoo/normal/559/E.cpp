/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-06 21:33:57
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
#include<vector>
const int N=310;
int n,a[N],f[N],x[N],y[N],m;
std::vector<int> l[N];
int id(int v){ return std::lower_bound(a+1,a+m+1,v)-a; }
int calc(int j,int k,int l)
{
	int r;
	if(k){ l=std::max(l,id(x[j])); r=id(x[j]+y[j]); }
	else{ l=std::max(l,id(x[j]-y[j])); r=id(x[j]); }
	int flag=1;
	for(int i=l;i<=r;i++)
	{
		for(auto p:(::l[i]))
		{
			if(flag&&x[j]==a[i]&&y[j]==p){ flag=1; continue; }
			r=std::max(r,id(a[i]+p));
		}
	}
	return r;
}
int main()
{
	n=read();
	fr(i,1,n)
	{
		x[i]=read(); y[i]=read();
		a[++m]=x[i]; a[++m]=x[i]-y[i]; a[++m]=x[i]+y[i];
	}
	std::sort(a+1,a+m+1); m=std::unique(a+1,a+m+1)-a-1;
	fr(i,1,n) l[id(x[i])].push_back(y[i]);
	a[0]=-1000000000;
	fr(i,0,m)
	{
		if(i) f[i]=std::max(f[i],f[i-1]);
		fr(j,1,n) if(x[j]>a[i]) fr(k,0,1)
		{
			int p=calc(j,k,i+1);
			f[p]=std::max(f[p],f[i]+a[p]-std::max(a[i],x[j]-(k?0:y[j])));
		}
//		printf("%d %d\n",a[i],f[i]);
	}
	printf("%d\n",f[m]);
	return 0;
}