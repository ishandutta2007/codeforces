#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=2e5+5,L=30,T=N*L;
int a[N];
int ch[T][2],tot=1;
void ins(int v)
{
	int i=1;
	per(j,L-1,0)
	{
		bool d=(v>>j)&1;
		if(!ch[i][d])ch[i][d]=++tot;
		i=ch[i][d];
	}
}
int check(int v,int i,int d)
{
	int ans=0;
	per(j,d,0)
	{
		bool b=(v>>j)&1;
		if(ch[i][b])i=ch[i][b];
		else {i=ch[i][b^1];ans+=1<<j;}
	}
	return ans;
}
int q[N],t,dfn[T],en[T];
s64 ans;
void dfs(int x,int d,int v)
{
	if(d<0)
	{
		q[++t]=v;
		dfn[x]=en[x]=t;
		return ;
	}
	dfn[x]=t+1;
	int l=ch[x][0],r=ch[x][1];
	if(l)dfs(l,d-1,v);
	if(r)dfs(r,d-1,v|(1<<d));
	if(l&&r)
	{
		int mn=1<<d;
		if(en[l]-dfn[l]<en[r]-dfn[r])
		{
			rep(i,dfn[l],en[l])chmin(mn,check(q[i],r,d-1));
		}
		else
		{
			rep(i,dfn[r],en[r])chmin(mn,check(q[i],l,d-1));
		}
		ans+=mn+(1<<d); 
	}
	en[x]=t;
}

int main()
{
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,n)ins(a[i]);
	dfs(1,29,0);
	cout<<ans;
}