#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m,k;
	cin>>n>>m>>k;
	if((s64)n*m*2%k)
	{
		puts("NO");
	}
	else
	{
		puts("YES\n0 0");		
		if(k%2==0)
		{
			k/=2;
			int k1=__gcd(n,k),k2=k/k1;
			printf("%d 0\n",n/k1);
			printf("0 %d\n",m/k2);
		}
		else
		{
			int k1=__gcd(n,k),k2=k/k1;
			if(k1>1)n*=2;
			else m*=2;
			printf("%d 0\n",n/k1);
			printf("0 %d\n",m/k2);
		}
	}
}