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

int min_p(int a)
{
	int i=2;
	while(a%i)++i;
	return i;
}
int b[30];
int work()
{
	int a=read();
	int i=0;
	while(a>>i)++i;
	if(a==(1<<i)-1)return b[i]?b[i]:b[i]=a/min_p(a);
	return (1<<i)-1;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int m=read();
	while(m--)printf("%d\n",work());
}