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
int n,p[N],d[N],q[N],top;
s64 s;
s64 check_min(int x)
{
	s64 ans=0;
	int n=::n,i=1,x_i=1;
	while(1)
	{
		ans+=(s64)x_i*i;
		n-=x_i;
		if((n+x-1)/x<=x_i)return ans+(s64)n*(i+1);
		x_i*=x;++i;
	}
}
int erfen()
{
	int l=1,r=n;
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		if(check_min(mid)<=s)r=mid;
		else l=mid;
	}
	return r;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n>>s;
	if((s64)n*(n+1)/2<s||check_min(n)>s)
	{
		puts("No");
		exit(0);
	}
	int x=erfen();
	//cerr<<x<<endl;
	d[1]=1;q[top=1]=1;
	s64 ans=1;
	rep(i,2,n)
	{
		p[i]=(i-2)/x+1;
		d[i]=d[p[i]]+1;
		ans+=d[i];
		if(d[i]>top)q[++top]=i;
	}
//	cerr<<n<<endl;
	int i=n;
	while(ans<s)
	{
		while(d[i]>d[i-1])--i;
		if(ans+(top+1-d[i])<=s)
		{
			ans+=top+1-d[i];
			p[i]=q[top]; 
			q[++top]=i;
		}
		else
		{
			while(ans<s)
			{
				++d[i];
				++ans;
			}
			p[i]=q[d[i]-1];
		}
		--i;
	}
//	cerr<<ans<<" "<<s<<endl;
	puts("Yes");
	rep(i,2,n)printf("%d ",p[i]);
}