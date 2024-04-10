#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
typedef long long ll;
typedef unsigned int ui;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define mid ((l+r)>>1)
#define gc (c=getchar())
char readc()
{
	char c;
	while(gc<'0');
	return c;
}
int read()
{
	char c;
	while(gc<'0');
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}

const int N=2e5+5,M=1e6+5,U=21;
int n,T,a[N],t[N],q[N];
bool t_xiao(int x,int y)
{
	return t[x]<t[y];
}
bool ok(int k,bool w=0)
{
	if(w) printf("%d\n%d\n",k,k);
	int can=T,need=k;
	rep(i,1,n)
	{
		if(!need)break;
		if(a[q[i]]>=k)
		{
			can-=t[q[i]];
			--need;
			if(w) printf("%d ",q[i]);
		}
	}
	return need==0&&can>=0;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n>>T;
	rep(i,1,n){a[i]=read();t[i]=read();q[i]=i;}
	sort(q+1,q+n+1,t_xiao);
	int l=0,r=n;
	if(ok(r))ok(r,1);
	else 
	{
		while(l+1!=r)
		if(ok(mid))l=mid;
		else r=mid;
		ok(l,1);
	}
}