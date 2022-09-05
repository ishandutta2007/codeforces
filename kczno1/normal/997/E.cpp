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

const int N=120000+5;
int n,p[N],dy[N];
vector<int>lkq[N];
int qr[N];s64 qans[N];

#define cl (k*2)
#define cr (cl+1)
#define mid ((l+r)/2)
namespace SEG
{
const int T=N*4;
int mn[T],ad[T],mn_cnt[T],ad_cnt[T];
s64 tot_cnt[T];
void add(int k,int w)
{
	mn[k]+=w;ad[k]+=w;
}
void add2(int k,int c)
{
	tot_cnt[k]+=(s64)c*mn_cnt[k];
	ad_cnt[k]+=c;
}
void down(int k)
{
	add(cl,ad[k]);add(cr,ad[k]);ad[k]=0;
	if(mn[cl]==mn[k])add2(cl,ad_cnt[k]);
	if(mn[cr]==mn[k])add2(cr,ad_cnt[k]);
	ad_cnt[k]=0;
}
void up(int k)
{
	if(mn[cl]!=mn[cr])
	{
		int x=mn[cl]<mn[cr]?cl:cr;
		mn[k]=mn[x];
		mn_cnt[k]=mn_cnt[x];
	}
	else 
	{
		mn[k]=mn[cl];
		mn_cnt[k]=mn_cnt[cl]+mn_cnt[cr];
	}
	tot_cnt[k]=tot_cnt[cl]+tot_cnt[cr];
}
void suf_add(int i,int w)
{
	int k=1,l=1,r=n;
	while(l!=r)
	{
		down(k);
		if(i<=mid)
		{
			add(cr,w);
			k=cl;r=mid;
		}
		else
		{
			k=cr;l=mid+1;
		}
	}
	add(k,w);
	while(k>>=1)up(k);
}
void calc(int k)
{
	if(mn[k]==0)add2(k,1);
}
void suf_calc(int i)
{
	int k=1,l=1,r=n;
	while(l!=r)
	{
		down(k);
		if(i<=mid)
		{
			calc(cr);
			k=cl;r=mid;
		}
		else
		{
			k=cr;l=mid+1;
		}
	}
	calc(k);
	while(k>>=1)up(k);
}
s64 qiu(int i)
{
	if(i>n)return 0;
	s64 ans=0;
	int k=1,l=1,r=n;
	while(l!=r)
	{
		down(k);
		if(i<=mid)
		{
			ans+=tot_cnt[cr];
			k=cl;r=mid;
		}
		else
		{
			k=cr;l=mid+1;
		}
	}
	return ans+tot_cnt[k];
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	n=read();
	rep(i,1,n)dy[p[i]=read()]=i;
	int m=read();
	rep(i,1,m)
	{
		lkq[read()].push_back(i);
		qr[i]=read();
	}
	rep(i,1,n*4)SEG::mn_cnt[i]=1;
	per(i,n,1)
	{
		if(i<n)SEG::suf_add(i+1,1);
		if(i<dy[p[i]-1])SEG::suf_add(dy[p[i]-1],-1);
		if(i<dy[p[i]+1])SEG::suf_add(dy[p[i]+1],-1);
		SEG::suf_calc(i);
		for(auto x:lkq[i])qans[x]=SEG::qiu(i)-SEG::qiu(qr[x]+1);
	}
	rep(i,1,m)printf("%lld\n",qans[i]);
}