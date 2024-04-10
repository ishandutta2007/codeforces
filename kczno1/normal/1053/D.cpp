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

const int N=2e5+5,U=2e6+5,D=1e9+7;
int ap[U];
int mx[U],mx_cnt[U];
int r[U];
int pr[U],pcnt;
void init(int n)
{
	rep(i,2,n)
	{
		if(!r[i])r[i]=pr[++pcnt]=i;
		for(int j=1,x;x=pr[j],i*x<=n;++j)
		{
			r[i*x]=x;
			if(x==r[i])break;
		}
	}
}
int a[N],top;
void add(int x)
{
	a[++top]=x;
	while(x>1)
	{
		int p=r[x],y=1;
		while(x%p==0){x/=p;y*=p;}
		if(mx[p]<y){mx[p]=y;mx_cnt[p]=1;}
		else mx_cnt[p]+=mx[p]==y;
	}
}
bool no_value(int x)
{
	while(x>1)
	{
		int p=r[x],y=1;
		while(x%p==0){x/=p;y*=p;}
		if(mx[p]==y&&mx_cnt[p]==1)return 0;
	}
	return 1;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	init(U-1);
	int n=read();
	rep(i,1,n)++ap[read()];
	rep(i,1,U-1)mx[i]=mx_cnt[i]=1;
	bool ap3=0;
	per(i,U-1,2)
	if(ap[i])
	if(ap[i]>=2){add(i);add(i-1);ap3+=ap[i]>=3;}
	else add(mx[i]>1?i-1:i);
	rep(i,1,n)ap3|=no_value(a[i]);
	s64 ans=1;
	rep(i,1,U-1)ans=ans*mx[i]%D;
	cout<<(ans+ap3)%D;
}