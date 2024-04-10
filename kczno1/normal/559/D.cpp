#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e5+5;
int n,x[N],y[N];
long double sum[N];

s64 value(int x1,int y1,int x2,int y2)
{
	if(x1==x2)
	{
		if(y1>y2)return 0;
		return y1-y2;
	}
	int dx=abs(x2-x1),dy=abs(y2-y1);
	if(x1<x2)
	{
		if(y1==y2)return s64(y1-1)*dx;
		s64 s=( s64(dx+1)*(dy+1)-(__gcd(dx,dy)+1))/2;
		if(y1<y2)return s64(y1-1)*dx+s-dy;
		return s64(y2-1)*dx+s;
	}
	if(y1==y2)return -s64(y1)*dx;
	s64 s=( s64(dx+1)*(dy+1)+(__gcd(dx,dy)+1))/2;
	if(y1<y2)return -(s64(y1-1)*dx+s-1);
	return -(s64(y2-1)*dx+s-(dy+1));
}
s64 value(int i,int j)
{
	return value(x[i],y[i],x[j],y[j]);
}

int main()
{
//	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	rep(i,0,n-1)scanf("%d%d",x+i,y+i);
	reverse(x,x+n);
	reverse(y,y+n);
//	rep(i,0,n-1)cerr<<x[i]<<" "<<y[i]<<endl;
//	cerr<<value(3,1)<<endl;
	long double ans=0;
	rep(i,0,n-1)
	{
		int mj=min(100,n-2);
		rep(j,1,mj)
		{
			sum[j+1]+=value(i,(i+j)%n);
		}
	}
	long double sum_n=0;
	per(j,n-1,1){ans=(ans+sum[j])/2;sum_n+=sum[j];}
	rep(i,1,n)sum_n/=2;
	ans-=sum_n;
	long double k=1+n+s64(n)*(n-1)/2;
	rep(i,1,n)k/=2;
	ans/=1-k;
	printf("%.10f\n",double(ans+1));
}