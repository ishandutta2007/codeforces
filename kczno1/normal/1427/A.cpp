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

int b;
int sgn(int x)
{
	return x<0?-b:(x>0?-(b^1):1);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n;
		cin>>n;
		vector<int>a(n);
		rep(i,0,n-1)a[i]=read();
		int sum=0;
		rep(i,0,n-1)sum+=a[i];
		if(sum==0)puts("NO");
		else 
		{
			b=sum<0;
			puts("YES");
			sort(a.begin(),a.end(),[&](int x,int y){ return sgn(x)<sgn(y); });
			rep(i,0,n-1)printf("%d%c",a[i]," \n"[i==n-1]);
		}
	}
}