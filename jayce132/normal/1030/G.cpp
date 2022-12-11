#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxp=2e6+20;
const int maxn=maxp;
const int mod=1e9+7;

int n,p[maxn],mark[maxn],prime[maxn],tot,d[maxn];

inline void prepare()
{
	REP(i,2,2e6)
	{
		if(!mark[i])prime[++tot]=i,mark[i]=tot,d[i]=i;
		for(int j=1;i*prime[j]<=2e6;j++)
		{
			int k=i*prime[j]; mark[k]=1; d[k]=prime[j];
			if(!(i%prime[j]))break;
		}
	}
}

inline void init()
{
	n=read();
	REP(i,1,n)p[i]=read();
	sort(p+1,p+n+1);
}

int cnt[maxp],ok[maxp];
int tag[maxp];

inline int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=(ll)ans*a%mod;
		b>>=1;
		a=(ll)a*a%mod;
	}
	return ans;
}

inline void doing()
{
	DREP(i,n,1)
	{
		int x=p[i];
		if(!cnt[x])
		{
			cnt[x]=1;tag[x]=1;ok[i]=0;
		}else
		{
			ok[i]=1;
			int u=x-1;
			while(u>1)
			{
				int t=d[u],sum=0;
				while(!(u%t))u/=t,sum++;
				if(cnt[t]<sum)cnt[t]=sum,tag[t]=1;
				else if(cnt[t]==sum)tag[t]++;
			}
		}
	}

	int ad=0;
	
	DREP(i,n,1)
	{
		int u=p[i]-ok[i],flg=1;
		while(u>1)
		{
			int t=d[u],sum=0;
			while(!(u%t))u/=t,sum++;
			if(tag[t]==1 && cnt[t]==sum)flg=0;
		}
		ad|=flg;
	}
	int ans=1;
	REP(i,1,2e6)if(cnt[i])ans=(ll)ans*power(i,cnt[i])%mod;
	printf("%d\n",(ans+ad)%mod);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("linear.in","r",stdin);
	freopen("linear.out","w",stdout);
#endif
	prepare();
	init();
	doing();
	return 0;
}