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

#define LO(x) (x&(1<<20)-1)
#define HI(x) (x>>20)
const int N=5e5+5;
int n,a[N];s64 sd[N],c[N];
void add(int i)
{
	s64 x=1+(s64(i)<<20);
	for(++i;i<=n+2;i+=i&-i)c[i]+=x;
}
s64 query(int i)
{
	s64 ans=0;
	for(++i;i;i-=i&-i)ans+=c[i];
	return ans;
}
s64 C2(int n)
{
	return s64(n)*(n-1);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	n=read();
	rep(i,1,n)a[i]=read();
	sort(a+1,a+n+1,greater<int>());
	rep(i,1,n)sd[i]=sd[i-1]+a[i];
	int al=0,ar=n;bool ad=0;
	per(i,n,1)
	{
		ad^=a[i]%2;
		auto Q=[&](int k)//sum_{j>i} min(a[j],k)
		{
			s64 x=query(k);
			return (n-i-LO(x))*k+HI(x);
		};
		s64 nr=max(C2(i+1)+Q(i+1)-sd[i],a[i]-1LL);
		s64 nl=sd[i]-C2(i)-Q(i);
		if(nl>i||nl>a[i])nl=a[i];
		ar=min(s64(ar),nr);al=max(s64(al),nl);
		add(a[i]);
	}
	bool h=0;
	rep(i,al,ar)
	if(i%2==ad)
	{
		s64 x=query(i);
		int k=n-LO(x)+1;
		s64 x2=query(min(i,k));
		if(sd[n]-HI(x)+i<=C2(k)+(LO(x)-LO(x2))*k+HI(x2))
		{
			printf("%d ",i);
			h=1;
		}
	}
	if(!h)puts("-1");
}