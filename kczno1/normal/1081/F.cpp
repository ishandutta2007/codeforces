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

const int U=10000+5,L=30,N=300+5;
pii st[U];int top;
int a[N],ans[N];
int n,t;

int C1(int i)
{
	int ans=0;
	rep(j,1,i)ans+=a[j];
	return ans;
}
int push(int l,int r)
{
	st[++top]={l,r};
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int t;
	scanf("%d",&t);
	return t;
}
void get(int i)
{
		int top0=top,tmp=0;
		while(++tmp<=L)
		{
			int t1=push(i+1,n);
			if(t1==n-t)
			{
				st[top]={1,n};
				rep(j,1,i-1)a[j]^=1;
				t=t1;
			}
			else
			{
				int x=t1-(n-t);
				t=t1;
				x-=2*C1(i-1)-i;
				if(x>0)a[i]=1;
				else a[i]=0;
				return ;
			}
		}
		rep(j,top0+1,top)st[j]={i+1,n};
		int x=0;
		x-=2*C1(i-1)-i;
		if(x>0)a[i]=1;
		else a[i]=0;
		int a0=a[1];
		top0=top;
		get(1);
		if(a[1]==a0)rep(j,2,i)a[j]^=1;
		if((a[1]!=a0)^((top-top0)%2==0)){st[top0].first=1;}
		//if((a[1]!=a0)^(top-top0)%2==0){rep(j,2,i)a[j]^=1;st[top0-1].first=1;}
}

int main()
{
#ifdef kcz
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n>>t;
	rep(i,1,n-1)get(i);
	a[n]=t-C1(n-1);
	per(i,top,1)
	{
		int l=st[i].first,r=st[i].second;
		rep(i,l,r)a[i]^=1;
	}
	printf("! ");
	rep(i,1,n)printf("%d",a[i]);
	fflush(stdout);
}