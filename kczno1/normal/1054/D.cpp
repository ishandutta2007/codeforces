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

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,k;
	cin>>n>>k;
	int u=(1<<k)-1;
	map<int,int>cnt;
	int s=0;++cnt[s];
	rep(i,1,n){s^=read();++cnt[min(s,s^u)];}
	s64 ans=s64(n+1)*n/2;
	for(auto pr:cnt)
	{
		int m=pr.second;
		int a=m/2,b=m-a;
		ans-=s64(a)*(a-1)/2+s64(b)*(b-1)/2;
	}
	cout<<ans;
}