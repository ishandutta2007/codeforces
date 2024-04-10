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

const int u=1e9;

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	cout<<0<<" "<<0<<endl;
	string s0;
	cin>>s0;
	int l=-(u-1),r=u-1;
	rep(i,2,n)
	{
		int m=(l+r)/2;
		int d=max(0,-m);
		cout<<m+d<<" "<<u-d<<endl;
		string s1;
		cin>>s1;
		if(s1==s0)l=m+1;
		else r=m-1;
	}
	int d=max(0,-l);
	printf("%d %d %d %d\n",l+d,u-d,u-d,l+d);
}