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
const int N=5e5+5;
char s[N],t[N];
int f[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	scanf("%s%s",s+1,t+1);
	
	int n=strlen(s+1);
	int	c0=0,c1=0;
	rep(i,1,n)
	if(s[i]=='0')++c0;
	else ++c1;
	
	int m=strlen(t+1);
	rep(i,2,m)
	{
		int j=f[i-1];
		while(j&&t[j+1]!=t[i])j=f[j];
		if(t[j+1]==t[i])++j;
		f[i]=j;
	}
	
	n=0;
	auto out=[&]()
	{
		while(--c0>=0)s[++n]='0';
		while(--c1>=0)s[++n]='1';
		printf("%s\n",s+1);
		exit(0);
	};
	rep(i,1,m)
	if(t[i]=='0')
	{
		if(!(c0--))out();
		s[++n]='0';
	}
	else
	{
		if(!(c1--))out();
		s[++n]='1';
	}
	while(1)
	{
		rep(i,f[m]+1,m)
		if(t[i]=='0')
	{
		if(!(c0--))out();
		s[++n]='0';
	}
	else
	{
		if(!(c1--))out();
		s[++n]='1';
	}
	}
}