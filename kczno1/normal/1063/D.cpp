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

s64 ans=-1;
s64 k;
void check(s64 l1,s64 r1,s64 l2,s64 r2)
{
	if(l1>k)return ;
	s64 i=1;
	while(i<=k)
	{
		s64 j=k/(k/i);
		
		s64 t=k/i;
		s64 nl=max(i,max( (k-r1+t-1)/t,(k+l2+t)/(t+1) )),nr=min(j,min( (k-l1)/t,(k+r2)/(t+1) ));
		if(nl<=nr)chmax(ans,nr);
		
		i=j+1;
	}
	s64 t=0;
	if(k>=l1&&k<=r1)
	{
		s64 nl=max(k+1,(k+l2+t)/(t+1)),nr=(k+r2)/(t+1);
		if(nl<=nr)chmax(ans,nr);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	s64 n,l,r;
	cin>>n>>l>>r>>k;
	r=(r-l+n)%n;
	ans=n-1;	
	if(r==n-1)
	{
		auto check2=[&](s64 len)
		{
			if(len>=n&&len<=2*n)chmax(ans,len);
		};
		rep(i,1,1e6)
		if(k%i==0)
		{
			check2(i);
			check2(k/i);
		}
	}
	rep(i,0,1)check(r+1+i,2*r+1+i,n-r+i-(i+1),2*(n-r)-(i+1));
	cout<<ans-n;	
}