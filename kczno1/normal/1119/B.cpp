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

const int N=1000+5;
int h,a[N],b[N];
bool ok(int mid)
{
	rep(i,1,mid)b[i]=a[i];
	sort(b+1,b+mid+1);
	s64 sum=0;
	rep(i,0,mid/2)sum+=b[mid-i*2];
	return sum<=h;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n>>h;
	rep(i,1,n)a[i]=read();
	int l=1,r=n+1;
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		if(ok(mid))l=mid;
		else r=mid;
	}
	cout<<l;
}