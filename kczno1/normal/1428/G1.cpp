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
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
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

const int L=6,U=1e6;
s64 F[L],dp[L+1][U];
int q[U];s64 a[U];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int k;
	cin>>k;
	--k;
	k*=3;
	rep(i,0,5)cin>>F[i];
	rep(i,0,U-1)
	{
		int x=i;
		rep(j,0,L-1)
		{
			int y=x%10;
			if(y%3==0)dp[0][i]+=F[j]*(y/3);
			x/=10;
		}
	}
	int w=3;
	rep(j,0,L-1)
	{
		rep(d,0,w-1)
		{
			int mi=(U-1-d)/w;
			int h=0,t=-1;
			rep(i,0,mi)
			{
				s64 now=dp[j][d+i*w]-i*F[j];
				while(t>=h&&now>=a[t])--t;
				++t;a[t]=now;q[t]=i;
				if(q[h]<i-k)++h;
				dp[j+1][d+i*w]=a[h]+i*F[j];
			}
		}
		w*=10;
	}
	int m;
	cin>>m;
	while(m--)printf("%lld\n",dp[L][read()]);
}