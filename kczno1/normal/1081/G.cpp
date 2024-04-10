#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e5+5;
int n,D;
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
s64 jie[N],niv_jie[N];
s64 C(int n,int m)
{
	if(m>n)return 0;
	return jie[n]*niv_jie[m]%D*niv_jie[n-m]%D;
}
s64 F(int a,int b)
{
	s64 ans=0;
	rep(len,2,n)
	{
	//	if(a==1&&b==2&&len==3)
	//		int yyx=1;
		int l=max(len-b,1),r=min(len-1,a);
		if(l>r)continue;
		(ans+=s64(len-l-1+len-r-1)*(r-l+1)/2%D*mi(len))%=D;
	}
	return ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int k;
	cin>>n>>k>>D;
	jie[0]=1;
	rep(i,1,n)jie[i]=jie[i-1]*i%D;
	rep(i,0,n)niv_jie[i]=mi(jie[i]); 
	int x=n,a=1,b=0;
	rep(tmp,1,k-1)
	{
		if(x%2)b+=a+b;
		else a+=a+b;
		x/=2;
	}
	if(!x){puts("0");exit(0);}
	s64 ans=(a*C(x,2)+b*C(x+1,2))%D;
	(ans+=s64(a)*(a-1)%D*F(x,x)+s64(b)*(b-1)%D*F(x+1,x+1)+a*b%D*(F(x,x+1)+F(x+1,x)))%=D;
	cout<<ans*mi(2)%D;
}