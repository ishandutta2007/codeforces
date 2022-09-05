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

const int N=2e5+5,T=N*3,D=1e9+7;
int b[N];
s64 s[T],s2[T];
int n,d;

#define cl (i*2)
#define cr (cl+1)
void modify(int i,int w)
{
	i+=d;s[i]=w;s2[i]=(s64)w*b[i-d]%D;
	while(i>>=1)
	{
		s[i]=s[cl]+s[cr];
		s2[i]=s2[cl]+s2[cr];
	}
}
s64 qiu(int i,int t)
{
	if(i==0)return 0;
	i+=d;
	s64 a1=s[i],a2=s2[i];
	while(i)
	{
		if(i%2){a1+=s[i-1];a2+=s2[i-1];}
		i>>=1;
	}
	return t==1?a1:a2;
}
int erfen(s64 sum)
{
	int i=1;
	while(i<=d)
	if(s[cl]>=sum)i=cl;
	else 
	{
		sum-=s[cl];
		i=cr;
	}
	return i-d;
}
int query(int l,int r)
{
	s64 sum=qiu(r,1)-qiu(l-1,1);
	int m=erfen((sum+1)/2+qiu(l-1,1));
	return ((b[m]*((qiu(m,1)-qiu(l-1,1)-(qiu(r,1)-qiu(m,1)))%D)
				+(qiu(r,2)-qiu(m,2)-(qiu(m,2)-qiu(l-1,2))))%D+D)%D;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	n=read();int m=read();
	for(d=1;d<n;d*=2);--d;
	rep(i,1,n)b[i]=read()-i;
	rep(i,1,n)modify(i,read());
	while(m--)
	{
		int x=read(),y=read();
		if(x<0)modify(-x,y);
		else printf("%d\n",query(x,y));
	}
}