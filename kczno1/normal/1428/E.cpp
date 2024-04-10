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

s64 sqr(s64 x)
{
	return x*x;
}
const int N=1e5+5;
int a[N],c[N];

s64 W(int a,int c)
{
	int x=a/c;
	int b=a%c;
	return sqr(x)*(c-b)+sqr(x+1)*b;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,k;
	cin>>n>>k;
	s64 sum=0;
	priority_queue<pair<s64,int>>heap;
	auto push=[&](int i)
	{
		if(c[i]<a[i])heap.push({W(a[i],c[i])-W(a[i],c[i]+1),i});
	};
	rep(i,1,n)
	{
		a[i]=read();
		sum+=sqr(a[i]);
		c[i]=1;
		push(i);
	}
	rep(tmp,n+1,k)
	{
		auto pr=heap.top();heap.pop();
		sum-=pr.first;
		int i=pr.second;
		++c[i];
		push(i);
	}
	cout<<sum<<endl;
}