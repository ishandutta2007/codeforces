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
int n,m;

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
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n>>m;
	if(n>=30)cout<<m;
	else cout<<m%mi(2,n);
}