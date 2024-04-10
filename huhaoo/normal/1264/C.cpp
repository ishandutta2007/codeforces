#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=r*10+c-48; c=getchar(); }
	return r*t;
}
#include<set>
#define i64 long long
const int mod=998244353;
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	while(b)
	{
		if(b&1) r=r*a%p;
		a=a*a%p; b>>=1;
	}
	return r;
}
i64 inv(i64 a){ return power(a,mod-2,mod); }
const int N=200010;
i64 n,q,a[N],s1[N],s2[N],ans;
std::set<i64> s;
i64 calc(i64 l,i64 r)
{
	return (s2[r]-s2[l-1]+mod)*inv(s1[r])%mod;
}
int main()
{
	n=read(); q=read(); s.insert(n+1); s.insert(1);
	fr(i,1,n) a[i]=read();
	s1[0]=1;
	fr(i,1,n)
	{
		s1[i]=s1[i-1]*a[i]%mod*inv(100)%mod;
		s2[i]=(s2[i-1]+s1[i-1])%mod;
	}
	ans=calc(1,n);
	while(q--)
	{
		i64 p=read();
		if(s.count(p))
		{
			std::set<i64>::iterator r=s.erase(s.lower_bound(p)),l=r;
			l--;
			i64 L=*l,R=*r;
			ans+=calc(L,R-1)-calc(L,p-1)-calc(p,R-1);
		}
		else
		{
			std::set<i64>::iterator r=s.lower_bound(p),l=r;
			l--;
			i64 L=*l,R=*r;
			ans+=calc(L,p-1)+calc(p,R-1)-calc(L,R-1);
			s.insert(p);
		}
		printf("%I64d\n",ans%mod);
	}
	return 0;
}