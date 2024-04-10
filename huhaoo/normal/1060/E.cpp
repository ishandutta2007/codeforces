/****************************************************************
	File name: CF1060E.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 10/10/2018, 8:16:39 PM
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
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
namespace run
{
	#define N 400010
	long long n,e,next[N],to[N],begin[N],h[N],s[N],w[N],ans,f[N],a0,a1;
	#define fo(i,a) for(int i=begin[a];i;i=next[i])
	void add(int u,int v)
	{
		e++;
		next[e]=begin[u];
		begin[u]=e;
		to[e]=v;
	}
	void dfs(long long u)
	{
		long long v;
		fo(i,u)if(f[u]!=(v=to[i]))
		{
			f[v]=u;h[v]=h[u]^1;
			dfs(v);
			w[u]+=w[v]+s[v];s[u]+=s[v];
		}
		fo(i,u)if(f[u]!=(v=to[i]))
			ans+=(w[v]+s[v])*(s[u]-s[v]);
		ans+=w[u];
		s[u]++;
	}
	int main()
	{
		n=read();
		fr(i,2,n)
		{
			long long u=read(),v=read();
			add(u,v);
			add(v,u);
		}
		h[1]=1;dfs(1);
		fr(i,1,n)if(h[i])a1++;else a0++;
		printf("%lld\n",(ans+a0*a1)/2);
		return 0;
	}
}
int main(){return run::main();}