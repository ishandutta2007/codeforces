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

const int N=1e5+5;
s64 len[N];
char s[N];

s64 ans,now;
void work_now(int l,int r)
{
	rep(i,l,r)
	if(s[i]=='L')
	{
		ans+=len[i]*6;
		s64 d=min(now,len[i]);
		ans-=d*3;
		now-=d;
	}
	else
	{
		ans+=len[i]*3;
		now+=len[i];
	}
}
void work_w(int l,int r)
{
	s64 ng=0,nl=0,ngl=0;
	per(i,r,l)
	if(s[i]=='L')
	{
		ans+=len[i]*4;
		nl+=len[i];
	}
	else
	if(s[i]=='G')
	{
		ans+=len[i]*4;
		s64 d=min(nl,len[i]);
		ans-=d*2;
		nl-=d;ngl+=d;
		ng+=len[i]-d;
	}
	else
	{
		ans+=len[i]*2;
		s64 d=min(nl,len[i]);
		ans-=d*2;
		nl-=d;
		len[i]-=d;
		d=min(ng,len[i]);
		ans-=d*2;
		ng-=d;
		d=min(ngl*2,len[i]-d);
		ans-=d/2*2;
		ngl-=d/2;
		if(d%2){--ngl;++ng;}
	}
		s64 d=min(nl,now);
		ans-=d;
		nl-=d;
		now-=d;
		d=min(ng,now);
		ans-=d;
		ng-=d;
		d=min(ngl,now-d);
		ngl-=d;ng+=d;
	ans-=ng;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	rep(i,1,n)scanf("%lld",len+i);
	scanf("%s",s+1);
	int i=1;
	while(i<=n&&s[i]!='W')++i;
	work_now(1,i-1);
	work_w(i,n);	
	cout<<ans;
}