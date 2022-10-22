#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
int n,m,q,i,root[MAXN],w[MAXN],d[MAXN],lc[MAXN*31],rc[MAXN*31],s[MAXN*31],f[MAXN],D[MAXN],F[MAXN][19];
ll g[MAXN][19],x,y,ans;
inline int MAX(int x,int y)
{
	return d[x]>d[y]?x:y;
}
void fix(int &R,int R1,int l,int r,int x,int d)
{
	R=++m;
	s[R]=MAX(s[R1],d);
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)
	{
		fix(lc[R],lc[R1],l,mid,x,d);
		rc[R]=rc[R1];
	}
	else
	{
		fix(rc[R],rc[R1],mid+1,r,x,d);
		lc[R]=lc[R1];
	}
}
int ask(int R,int l,int r,int x)
{
	if(!R)return 0;
	if(l==r)return s[R];
	int mid=l+r>>1;
	if(x>mid)return ask(rc[R],mid+1,r,x);
	return MAX(s[rc[R]],ask(lc[R],l,mid,x));
}
void add(int x,int y)
{
	w[++n]=y;
	f[n]=x;
	d[n]=d[x]+1;
	D[n]=D[F[n][0]=ask(root[x],0,1000000000,y)]+1;
	g[n][0]=y;
	fix(root[n],root[x],0,1000000000,y,n);
	for(i=1;1<<i<=D[n];i++)
	{
		F[n][i]=F[F[n][i-1]][i-1];
		g[n][i]=g[n][i-1]+g[F[n][i-1]][i-1];
	}
	for(;i<19;i++)g[n][i]=1LL<<60;
}
int main()
{
	scanf("%d",&q);
	for(i=0;i<19;i++)g[0][i]=1LL<<60;
	w[0]=1000000000;
	fix(root[0],root[0],0,1000000000,1000000000,0);
	add(0,0);
	while(q--)
	{
		scanf("%d%I64d%I64d",&i,&x,&y);
		x^=ans;
		y^=ans;
		if(i==1)add(x,y);
		else
		{
			for(ans=0,i=18;~i;i--)if(g[x][i]<=y)
			{
				y-=g[x][i];
				ans|=1<<i;
				x=F[x][i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}