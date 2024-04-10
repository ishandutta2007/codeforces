#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m,tot;
int deg1[300005],deg2[300005];
int U[300005],V[300005],W[300005];

int hd[600005],nxt[2400005],to[2400005],dir[1200005];
void link(int x,int y,int id)
{
	nxt[id*2]=hd[x];hd[x]=id*2;to[id*2]=y;
	nxt[id*2+1]=hd[y];hd[y]=id*2+1;to[id*2+1]=x;
}

void dfs(int x)
{
	while(hd[x])
	{
		if(dir[hd[x]/2])
		{
			hd[x]=nxt[hd[x]];
			continue;
		}
		
		dir[hd[x]/2]=hd[x]%2+1;
		int t=to[hd[x]];
		hd[x]=nxt[hd[x]];
		dfs(t);
	}
}

int main()
{
	int i;
	scanf("%d%d",&n,&m);tot=m;
	rep(i,m) scanf("%d%d%d",&U[i],&V[i],&W[i]);
	
	rep(i,m) if(W[i]==1)
	{
		link(U[i],V[i],i);
		deg1[U[i]]^=1;
		deg1[V[i]]^=1;
	}
	
	rep(i,m) if(W[i]==2)
	{
		link(U[i]+n,V[i]+n,i);
		deg2[U[i]]^=1;
		deg2[V[i]]^=1;
	}
	
	int N1=n*2+1,N2=n*2+2;
	int ans=0;
	rep(i,n) if(deg1[i]==1)
	{
		deg2[i]^=1;ans++;
		if(deg2[i]==1)
		{
			link(i,N1,++tot);
			link(N1,N2,++tot); 
		}
		else
		{
			link(i,i+n,++tot);
		}
	}
	
	rep(i,n) if(deg1[i]==0&&deg2[i]==1)
	{
		link(i+n,N2,++tot);
	}
	
	rep(i,n*2+2) dfs(i);
	
	printf("%d\n",ans);
	rep(i,m) putchar(dir[i]+'0');
	return 0;
}