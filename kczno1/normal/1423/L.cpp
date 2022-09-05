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

const int N=1e3+5,S=30+2,B=15,U=1<<15;
struct P
{
bitset<N>a;int first_1;u32 s;
};
vector<P>a;
vector<u32>a0;

int n,s,m;
int upd(bitset<N> &now,u32 &s)
{
	per(i,n,1)
	if(now[i])
	{
		for(const auto &x:a)
		if(x.first_1==i)
		{
			now^=x.a;
			s^=x.s;
			break;
		}
		if(now[i])return i;
	}
	return 0;
}
int upd2(bitset<N> &now,u32 &s)
{
	int sz=a.size();
	per(i,n,1)
	if(now[i])
	{
		rep(j,0,sz-1)
		if(a[j].first_1==i)
		{
			now^=a[j].a;
			s^=1<<j;
			break;
		}
		if(now[i])return i;
	}
	return 0;
}

bitset<N> read_bitset()
{
	bitset<N>now;
	int c=read();
	rep(tmp,1,c)now[read()].flip();
	return now;
}
namespace SMALL_A0
{
u32 xor_sum[U];
void work()
{
	int sz=a0.size();
	int u=(1<<sz)-1;
	rep(s,0,u)
	rep(i,0,sz-1)
	if(s&(1<<i))
		xor_sum[s]^=a0[i];
	rep(tmp,1,m)
	{
		bitset<N> now=read_bitset();
		u32 s_now=0;
		int j=upd(now,s_now);
		if(j)puts("-1");
		else 
		{
			int ans=__builtin_popcount(s_now);
			rep(s,0,u)chmin(ans,__builtin_popcount(s_now^xor_sum[s]));
			printf("%d\n",ans);
		}	
	}
}
};
namespace SMALL_A
{
int a_sum[S],mn[2][U];
void init(int mn[U],int l,int r)
{
	r=r-l+1;
	int u=(1<<r)-1;
	rep(s,0,u)
	{
		int xor_a_sum=0;
		rep(i,0,r-1)
		if((s>>i)&1)xor_a_sum^=a_sum[l+i];
		chmin(mn[xor_a_sum],__builtin_popcount(s));
	}
}
void work()
{
	int sz=a.size();
	rep(i,0,sz-1)
	rep(j,0,s-1)
	if(a[i].s&(1<<j))a_sum[j]^=1<<i;
	int u=(1<<sz)-1;
	rep(i,0,u)mn[0][i]=mn[1][i]=s;
	int b=s/2;
	init(mn[0],0,b-1);
	init(mn[1],b,s-1);

	rep(tmp,1,m)
	{
		bitset<N> now=read_bitset();
		u32 s_now=0;
		int j=upd2(now,s_now);
		if(j)puts("-1");
		else 
		{
			int ans=__builtin_popcount(s_now);
			rep(s0,0,u)chmin(ans,mn[0][s0]+mn[1][s_now^s0]);
			printf("%d\n",ans);
		}	
	}
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n>>s>>m;
	rep(i,0,s-1)
	{
		bitset<N> now=read_bitset();
		u32 s_now=1<<i;
		int j=upd(now,s_now);
		if(!j)a0.push_back(s_now);
		else a.push_back({now,j,s_now});
	}
	if(a0.size()<=15)SMALL_A0::work();
	else SMALL_A::work();
}