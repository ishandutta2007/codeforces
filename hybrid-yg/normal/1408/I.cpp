#include<bits/stdc++.h>
using namespace std;
const int N=3000005,M=998244353;
int n,m,i,j,t,k,c,p,w[65536],a[65536],u[65536];
long long fac[25],inv[25];
struct str{
	int a[17];
}f[65536],ans[65536],s[65536];
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
long long inv2=(M+1)/2;
str operator +(str a,str b)
{
	int i;
	str c;
	memset(c.a,0,sizeof(c));
	for(i=0;i<=k;++i)
		c.a[i]=(a.a[i]+b.a[i])%M;
	return c;
}
str operator -(str a,str b)
{
	int i;
	str c;
	memset(c.a,0,sizeof(c));
	for(i=0;i<=k;++i)
		c.a[i]=(a.a[i]-b.a[i])%M;
	return c;
}
str operator *(str a,str b)
{
	str c;
	int i,j;
	memset(c.a,0,sizeof(c));
	for(i=0;i<=k;++i)
		for(j=0;j<=k-i;++j)
			c.a[i+j]=(c.a[i+j]+1ll*a.a[i]*b.a[j])%M;
	return c;
}
void FWT_xor(str *a,int opt,int N)
{
	int tt=0;
    for(int i=1;i<N;i<<=1)
    {
		for(int p=i<<1,j=0;j<N;j+=p)
            for(int k=0;k<i;++k)
            {
                str X=a[j+k],Y=a[i+j+k];
                a[j+k]=X+Y;a[i+j+k]=X-Y;
            }
        ++tt;
    }
    if(opt==-1)
    {
    	long long mt=qpow(inv2,tt);
    	for(int i=0;i<N;++i)
    		for(int j=0;j<=k;++j)
    			a[i].a[j]=a[i].a[j]*mt%M;
    }
}
void FWT_xor2(int *a,int N)
{
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p)
            for(int k=0;k<i;++k)
            {
                int X=a[j+k],Y=a[i+j+k];
                a[j+k]=X+Y;a[i+j+k]=X-Y;
            }
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	fac[0]=inv[0]=1;
	for(i=1;i<=20;++i)
	{
		fac[i]=fac[i-1]*i%M;
		inv[i]=qpow(fac[i],M-2);
	}
	scanf("%d %d %d",&n,&k,&c);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=0;i<(1<<c);++i)
	{
		memset(ans[i].a,0,sizeof(ans[i].a));
		ans[i].a[0]=1;
	}
	for(i=0;i<(1<<c);++i)
		u[i]=1;
	for(int m=1;m<=c;++m)
	{ 
		int tot=0;
		memset(w,0,sizeof(w));
		for(i=0;i<(1<<m);++i)
		{
			memset(s[i].a,0,sizeof(s[i].a));
			s[i].a[0]=1;
		}
		for(i=1;i<=n;++i)
		{
			for(j=0;j<=c;++j)
				if((a[i]>>j)==((a[i]-k)>>j))
					break;
			int t=j;
			if(t==m)
			{
				for(j=0;j<(1<<t);++j)
					memset(f[j].a,0,sizeof(f[j].a));
				for(j=a[i];j>=a[i]-k;--j)
					for(int w=0;w<(1<<t);++w)
						f[w].a[a[i]-j]=inv[a[i]-j]*(__builtin_popcount(j&w)&1?-1:1); 
				++w[a[i]>>t];
				++tot;
				for(j=0;j<(1<<t);++j)
					s[j]=s[j]*f[j];
			}
		}
		FWT_xor2(w,1<<c-m);
		for(i=0;i<(1<<c-m);++i)
			for(j=0;j<(1<<m);++j)
				if((tot-w[i])/2&1)
					u[(i<<m)|j]=-u[(i<<m)|j];
		for(j=0;j<(1<<m);++j)
			ans[j]=ans[j]*s[j];
		for(j=(1<<m);j<(1<<c);++j)
			ans[j]=ans[j-(1<<m)];
	}
	for(j=0;j<(1<<c);++j)
		if(u[j]==-1)
			for(i=0;i<=k;++i)
				ans[j].a[i]=-ans[j].a[i];
	FWT_xor(ans,-1,(1<<c));
	long long s=qpow(qpow(n,k),M-2);
	for(i=0;i<(1<<c);++i)
		printf("%lld ",(ans[i].a[k]*fac[k]%M*s%M+M)%M);
}