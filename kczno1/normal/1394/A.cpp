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

const int N=1e5+5;
int a1[N],a2[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,d,m;
	cin>>n>>d>>m;
	int n1=0,n2=0;
	rep(i,1,n)
	{
		int x=read();
		if(x<=m)a1[++n1]=x;
		else a2[++n2]=x;
	}
	sort(a1+1,a1+n1+1);
	sort(a2+1,a2+n2+1);
	s64 sum=0;
	int x=(n2+d)/(d+1);
	rep(i,n2-x+1,n2)sum+=a2[i];
	rep(i,1,n1)sum+=a1[i];
	s64 ans=sum;int y=0;
	while(x<n2)
	{
		++x;
		sum+=a2[n2-x+1];
		int y1=x*(d+1)-d-n2;
		if(y1>n1)break;
		//cerr<<x<<" "<<y1<<endl;
		while(y<y1)sum-=a1[++y];
		chmax(ans,sum);
	}
	cout<<ans;
}