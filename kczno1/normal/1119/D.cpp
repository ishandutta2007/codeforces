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
s64 a[N],d[N];
pair<s64,int>query[N];
s64 ans[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	rep(i,1,n)scanf("%lld",a+i);
	int m;
	cin>>m;
	rep(i,1,m)
	{
		s64 l,r;
		scanf("%lld%lld",&l,&r);
		query[i]={r-l,i};
	}
	sort(query+1,query+m+1);
	sort(a+1,a+n+1);
	rep(i,1,n-1)d[i]=a[i+1]-a[i];
	sort(d+1,d+n);
	s64 base=0;
	int j=1;
	rep(i,1,m)
	{
		while(j<n&&d[j]<=query[i].first)
		{
			base+=d[j];
			++j;
		}
		ans[query[i].second]=base+(n-j+1)*(query[i].first+1);
	}
	rep(i,1,m)printf("%lld ",ans[i]);
}