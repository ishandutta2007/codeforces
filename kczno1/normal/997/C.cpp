#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e6+5,D=998244353;
s64 mi(s64 x,int y=D-2)
{
	s64 ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%D;
		x=x*x%D;y>>=1;
	}
	return ans;
}
int n;
s64 jie[N],niv_jie[N];

s64 C(int n,int m)
{
	return jie[n]*niv_jie[m]%D*niv_jie[n-m]%D;
}
s64 f1()
{
	s64 ans=0;
	rep(i,1,n)(ans+=C(n,i)*mi(3,i)%D*mi(3,(s64)n*(n-i)%(D-1))*(i%2?1:-1))%=D;
	return ans;
}
s64 f2()
{
	s64 ans=0;
	rep(i,1,n)(ans+=C(n,i)*3*(mi(3,(s64)n*(n-i)%(D-1))-mi(mi(3,n-i)-1,n))*(i%2?1:-1))%=D;
	return ans;
}

int main()
{
//	freopen("1.in","r",stdin);
	cin>>n;
	jie[0]=1;
	rep(i,1,n)jie[i]=jie[i-1]*i%D;
	niv_jie[n]=mi(jie[n]);
	per(i,n,1)niv_jie[i-1]=niv_jie[i]*i%D;
	cout<<((2*f1()-f2())%D+D)%D;
}