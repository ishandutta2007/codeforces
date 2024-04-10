#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
const int D=1e9+7;
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
s64 F,F2;
void solve(s64 n)
{
	s64 a0=0,a1=0,a2=0,a3=0;
	int my=0;
	while((s64)my*my<=n)++my;
	--my;
	s64 s2=0,s4=0,s6=0;
	for(int y=1;y<=my;++y)
	{
		int y_2=(s64)y*y%D;
		(s2+=y_2)%=D;
		(s4+=(s64)y_2*y_2)%=D;
		(s6+=(s64)y_2*y_2%D*y_2)%=D;
	}
	for(int x=0;(s64)x*x<=n;++x)
	{
		while((s64)x*x+(s64)my*my>n)
		{
			int y_2=(s64)my*my%D;
			(s2-=y_2)%=D;
			(s4-=(s64)y_2*y_2)%=D;
			(s6-=(s64)y_2*y_2%D*y_2)%=D;
			--my;
		}
		(a0+=my)%=D;
		int x_2=(s64)x*x%D;
		(a1+=(s64)x_2*my+s2)%=D;
		(a2+=(s64)x_2*x_2%D*my+2*x_2*s2+s4)%=D;
		(a3+=(s64)x_2*x_2%D*x_2%D*my+(s64)x_2*x_2%D*s2%D*3+x_2*s4%D*3+s6)%=D;
	}
	n%=D;
	a0=(4*a0+1)%D;a1=4*a1%D;a2=4*a2%D;a3=4*a3%D;
	F=(n*(n+1)%D*a0%D-a2+a1)%D*mi(2)%D;
	F2=( n*(n+1)%D*(2*n+1)%D*a0%D-2*a3+3*a2-a1)*mi(6)%D;
}

int main()
{
//	freopen("1.in","r",stdin);
	s64 n;
	cin>>n;
	solve(n);
	cout<<(((n+1)%D*F-F2)%D+D)%D;
}