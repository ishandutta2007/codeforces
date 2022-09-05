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
const int N=2000+5,inf=N*20;
int dp[N][10][10][10],a[N],b[N];
int i,dpi,s,t,na[4],ntop,nb[4];
void push(int x)
{
	if(x)na[ntop++]=x;
}
void check(int x)
{
	int l=min(min(s,t),x),r=max(max(s,t),x);
	int bt=4;
	per(i,ntop-1,0)
	if(na[i]<l||na[i]>r)nb[--bt]=na[i];
	if(bt)
	{
		while(--bt)nb[bt]=0;
		chmin(dp[i+1][nb[1]][nb[2]][nb[3]],dpi+abs(s-x)+abs(t-x));
	}
}

int main()
{
//	freopen("1.in","r",stdin);
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d%d",a+i,b+i);
	rep(i,1,n)
	rep(a1,0,9)
	rep(a2,a1,9)
	rep(a3,a2,9)dp[i][a1][a2][a3]=inf;
	dp[1][0][0][0]=a[1]-1;
	for(i=1;i<n;++i)
	rep(a1,0,9)
	rep(a2,a1,9)
	rep(a3,a2,9)
	{
		dpi=dp[i][a1][a2][a3];
		if(dpi==inf)continue;
		s=a[i];t=a[i+1];
		ntop=0;
		push(a1);
		push(a2);
		push(a3);
		push(b[i]);
		sort(na,na+ntop);
		check(t);
		rep(i,0,ntop-1)check(na[i]);
	}
	int ans=inf;
	rep(a1,0,9)
	rep(a2,a1,9)
	rep(a3,a2,9)
	if(dp[n][a1][a2][a3]!=inf)
	{
		int l=b[n],r=b[n];
		if(a1){chmin(l,a1);chmax(r,a1);}
		if(a2){chmin(l,a2);chmax(r,a2);}
		if(a3){chmin(l,a3);chmax(r,a3);}
		chmin(ans,dp[n][a1][a2][a3]+abs(r-l)+
		min(abs(a[n]-l),abs(a[n]-r)));
	}
	cout<<ans+2*n;
}