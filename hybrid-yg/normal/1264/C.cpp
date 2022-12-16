#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=200005;
const long long inf=1000000000000000000ll;
int n,q,i,j,u;
long long treea[1000005],p[200005],treeb[1000005],ans;
set<int> e;
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		b>>=1;
		s=s*s%M;
	}
	return ans;
}
void pushup(int i)
{
	treeb[i]=(treeb[i<<1]*treea[i<<1|1]+treeb[i<<1|1])%M;
	treea[i]=treea[i<<1]*treea[i<<1|1]%M;
}
void Build(int i,int l,int r)
{
	if(l==r)
	{
		treea[i]=qpow(p[l],M-2);
		treeb[i]=treea[i];
		return;
	}
	int mid=l+r>>1;
	Build(i<<1,l,mid);
	Build(i<<1|1,mid+1,r);
	pushup(i);
}
struct str{
	long long a,b;
};
str Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return (str){treea[i],treeb[i]};
	int mid=l+r>>1;
	if(mid>=ll&&mid<rr)
	{
		str tmpa=Query(i<<1,l,mid,ll,rr);
		str tmpb=Query(i<<1|1,mid+1,r,ll,rr);
		return (str){tmpa.a*tmpb.a%M,(tmpa.b*tmpb.a+tmpb.b)%M};
	}
	if(mid>=ll)
		return Query(i<<1,l,mid,ll,rr);
	else
		return Query(i<<1|1,mid+1,r,ll,rr);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&p[i]);
		p[i]=p[i]*qpow(100,M-2)%M;
	}
	e.insert(1);
	e.insert(n+1);
	Build(1,1,n);
	ans=treeb[1];
	for(i=1;i<=q;++i)
	{
		scanf("%d",&u);
		auto x=e.lower_bound(u);
		if(*x==u)
		{
			auto y=x;
			--y;
			ans-=Query(1,1,n,*y,*x-1).b;
			y=x;
			++y;
			ans-=Query(1,1,n,*x,*y-1).b;
			e.erase(x);
			x=y;
			--y;
			ans+=Query(1,1,n,*y,*x-1).b;
		}
		else
		{
			auto y=x;
			--y;
			ans-=Query(1,1,n,*y,*x-1).b;
			e.insert(u);
			x=e.lower_bound(u);
			y=x;
			--y;
			ans+=Query(1,1,n,*y,*x-1).b;
			y=x;
			++y;
			ans+=Query(1,1,n,*x,*y-1).b;
		}
		ans%=M;
		printf("%lld\n",(ans%M+M)%M);
	}
}