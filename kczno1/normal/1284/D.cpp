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

const int N=2e5+5;
struct Point
{
	int sa,ea,sb,eb;
};
Point p[N],q1[N],q2[N];
int c1[N],c2[N],q[N],t;
void add(int c[],int i)
{
	for(;i;i-=i&-i)++c[i];
}
int query(int c[],int i)
{
	int ans=0;
	for(;i<=t;i+=i&-i)ans+=c[i];
	return ans;
}
int n;
bool check1()
{
	t=0;
	rep(i,1,n){q[++t]=p[i].sb;q[++t]=p[i].eb;}
	sort(q+1,q+t+1);
	t=unique(q+1,q+t+1)-q-1;
	rep(i,1,n){p[i].sb=lower_bound(q+1,q+t+1,p[i].sb)-q;p[i].eb=lower_bound(q+1,q+t+1,p[i].eb)-q;}
	rep(i,1,n)q1[i]=q2[i]=p[i];
	sort(q1+1,q1+n+1,[&](const Point &a,const Point &b){return a.sa<b.sa;});
	sort(q2+1,q2+n+1,[&](const Point &a,const Point &b){return a.ea<b.ea;});
	rep(i,1,t)c1[i]=c2[i]=0;
	int j=n;
	per(i,n,1)
	{
		while(q1[j].sa>q2[i].ea)
		{
			add(c1,q1[j].sb);
			add(c2,t-q1[j].eb+1);
			--j;
		}
		if(query(c1,q2[i].eb+1)+query(c2,t-(q2[i].sb-1)+1)!=n-j)return 0;
	}
	return 1;
}
bool check()
{
	n=read();
	rep(i,1,n)
	{
		p[i].sa=read();p[i].ea=read();
		p[i].sb=read();p[i].eb=read();
	}
	if(!check1())return 0;
	rep(i,1,n)
	{
		swap(p[i].sa,p[i].sb);
		swap(p[i].ea,p[i].eb);
	}
	return check1();
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	puts(check()?"YES":"NO");
}