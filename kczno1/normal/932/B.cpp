//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef unsigned int ui;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
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
const int n=1e6,N=1e6+5;
int cnt[N][10],g[N],f[N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	rep(i,1,9)f[i]=g[i]=i;
	rep(i,10,n)
	{
		f[i]=f[i/10]*max(1,i%10);
		g[i]=g[f[i]];
	}
	rep(i,1,n)
	rep(j,1,9)cnt[i][j]=cnt[i-1][j]+(g[i]==j);
	int q;cin>>q;
	while(q--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",cnt[r][k]-cnt[l-1][k]);
	}
}