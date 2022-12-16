#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=300005,E=524288;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
long long inv2=(M+1)/2;
int n,i,m,j,k,u;
long long a[N],f[60],s,ans[60],p[60],b[60],C[65][65],w[65][65],d[65];
void dfs(int i,long long s)
{
	int j;
	if(i>k)
	{
		++ans[__builtin_popcountll(s)];
		return;
	}
	dfs(i+1,s^a[i]);
	dfs(i+1,s);
}
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	s=1;
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		long long t=a[i];
		for(j=m-1;j>=0;--j)
			if((t>>j)&1)
				if(f[j])
					t^=f[j];
				else
				{
					f[j]=t;
					break;
				}
		if(j<0)
			s=s*2%M;
	}
	for(i=0;i<m;++i)
		if(f[i])
			a[++k]=f[i];
	if(k<=m/2)
	{
		dfs(1,0);
		for(i=0;i<=m;++i)
			printf("%lld ",ans[i]*s%M);
	}
	else
	{
		long long su=qpow(2,k-m+M-1);
		k=0;
		for(i=m-1;i>=0;--i)
			if(f[i])
				p[i]=k++;
		for(i=m-1;i>=0;--i)
			if(!f[i])
				p[i]=k++;
		k=0;
		for(i=m-1;i>=0;--i)
			if(f[i])
			{
				long long tmp=0;
				for(j=0;j<m;++j)
					if((f[i]>>j)&1)
						tmp|=1ll<<p[j];
				a[k++]=tmp;
			}
		for(i=0;i<k;++i)
			for(j=0;j<i;++j)
				if((a[j]>>i)&1)
					a[j]^=a[i];
		for(i=0;i<k;++i)
			for(j=k;j<m;++j)
				b[j-k]|=((a[i]>>j)&1)<<i;
		for(i=0;i<m-k;++i)
			b[i]|=1ll<<i+k;
		for(i=1;i<=m-k;++i)
			a[i]=b[i-1];
		k=m-k;
		dfs(1,0);
		for(i=0;i<=m;++i)
		{
			C[i][0]=C[i][i]=1; 
			for(j=1;j<i;++j)
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
		}
		for(i=0;i<=m;++i)
			for(j=0;j<=i;++j)
				for(k=0;k<=m-i;++k)
					w[i][j+k]=(w[i][j+k]+C[i][j]*C[m-i][k]*(j&1?-1:1))%M;
		for(i=0;i<=m;++i)
			for(j=0;j<=m;++j)
				d[i]=(d[i]+w[j][i]*ans[j]%M*su)%M;
		for(i=0;i<=m;++i)
			printf("%lld ",(d[i]*s%M+M)%M);
	}
}