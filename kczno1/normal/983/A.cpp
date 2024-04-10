#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

int main()
{
//	freopen("1.in","r",stdin);
	int tt;
	cin>>tt;
	while(tt--)
	{
		s64 p,q,b;
		scanf("%lld%lld%lld",&p,&q,&b);
		q/=__gcd(p,q);
		while(q>1)
		{
			s64 x=__gcd(q,b);
			if(x==1)break;
			while(q%x==0)q/=x;
		}
		puts(q==1?"Finite":"Infinite");
	}
}