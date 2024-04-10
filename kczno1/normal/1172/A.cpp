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
int n,p[N];

bool ok(int mid)
{
	rep(i,1,n)
	if(p[i]!=mid+i&&p[i]>mid+i-n-1)return 0;
	return 1;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n;
	rep(i,1,n)read();
	rep(i,1,n)p[read()]=i;
	if(p[1]&&ok(p[1]-1)){cout<<p[1]-1;exit(0);}
	int l=0,r=2*n+1;
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		if(ok(mid))r=mid;
		else l=mid;
	}
	cout<<r;	
}