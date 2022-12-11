#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)

#define int ll

inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}


const int maxn=1e5+20;
const int mod=1e9+7;

inline int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b & 1)ans=(ll)ans*a%mod;
		b>>=1;
		a=(ll)a*a%mod;
	}
	return ans;
}

int n,m,a[maxn],b[maxn],f[maxn];


void init()
{
	n=read();m=read();
	REP(i,1,n)a[i]=read();
	REP(i,1,n)b[i]=read();
}

void doing()
{
	f[0]=1;
	REP(i,1,n)
	{
		if(a[i]==0 || b[i]==0)
		{
			f[i]=(ll)f[i-1]*power(m,mod-2)%mod;
		}else f[i]=a[i]==b[i]?f[i-1]:0;
	}
	int ans=0;
	REP(i,1,n)
	{
		if(a[i]==0)
		{
			if(b[i]==0)ans=(ans+(ll)f[i-1]*(m-1)%mod*power(2*m,mod-2))%mod;
			else ans=(ans+(ll)f[i-1]*(m-b[i])%mod*power(m,mod-2))%mod;
		}
		else if(b[i]==0)
		{
			ans=(ans+(ll)f[i-1]*(a[i]-1)%mod*power(m,mod-2))%mod;
		}else
		{
			ans=(ans+(ll)f[i-1]*(a[i]>b[i]))%mod;
		}
	}
	printf("%lld\n",ans);
}

#undef int 

int main()
{
//    freopen("d.in","r",stdin);
//    freopen("d.out","w",stdout);
	init();
	doing();
	return 0;
}