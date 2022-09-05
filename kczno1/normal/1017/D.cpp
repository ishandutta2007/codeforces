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

const int U=(1<<12)+5,K=105;
int n;
int cnt[U];
int w[U];
int ans[U][K];

int reads()
{
	char c;
	while(gc<'0');
	int x=c-'0';
	rep(i,1,n-1)x+=gc-'0'<<i;
	return x;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int m,q;
	cin>>n>>m>>q;
	rep(i,0,n-1)w[1<<i]=read();
	int u=(1<<n)-1;
	rep(s,1,u)w[s]=min(w[s-(s&-s)]+w[s&-s],101);
	rep(i,1,m)++cnt[reads()];
	rep(i,0,u)
	{
		rep(j,0,u)ans[i][w[u^i^j]]+=cnt[j];
		rep(k,1,100)ans[i][k]+=ans[i][k-1];
	}
	rep(i,1,q)
	{
		int s=reads();
		int k=read();
		printf("%d\n",ans[s][k]);
	}
}