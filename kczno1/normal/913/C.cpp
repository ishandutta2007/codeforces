#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
typedef long long ll;
typedef unsigned int ui;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define gc (c=getchar())
char readc()
{
	char c;
	while(gc<'0');
	return c;
}
int read()
{
	char c;
	while(gc<'0');
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}

const int N=1e5+5,M=1e6+5,U=21;
int n;
ll c[N];

int mi(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1)ans=ans*x;
		x=x*x;y>>=1;
	}
	return ans;
} 

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int l;
	cin>>n>>l;
	rep(i,0,n-1)cin>>c[i];
	rep(i,1,n-1)chmin(c[i],c[i-1]*2);
	rep(i,n,29)c[i]=c[i-1]*2;
	ll ans=1e18;
	ll now=0;
	per(i,29,0)
	if((l>>i)&1)
	{
		chmin(ans,now+2*c[i]);
		now+=c[i];
	}
	else chmin(ans,now+c[i]);
	cout<<min(ans,now);
}