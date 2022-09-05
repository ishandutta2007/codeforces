#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=2000+5;
int px[N],py[N],qx[N],qy[N];
struct P
{
	int x1,y1,x2,y2;
};
bool exist[N][N];int mark[N][N];
int n1,n2;
vector<int>lk[N];
int match[N];
bool chosen[N];
void add_e(int x,int y)
{
	lk[x].push_back(n1+y);
	lk[n1+y].push_back(x);
}
bool vis[N];
bool dfs(int x)
{
	if(vis[x])return 0;
	vis[x]=1;
	for(auto y:lk[x])
	{
		if(!match[y]||dfs(match[y]))
		{
			match[y]=x;
			match[x]=y;
			return 1;
		}
	}
	return 0;
}
void choose(int x)
{
	if(chosen[x])return ;
	chosen[x]=1;
	for(auto y:lk[x])
	if(match[y])choose(match[y]);
}
void work()
{
	rep(i,1,n1)
	if(!match[i])
	{
		rep(j,1,n1)vis[j]=0;
		dfs(i);
	}
	rep(i,1,n1+n2)
	if(!match[i])choose(i);
	rep(i,1,n1+n2)
	if(!chosen[i]&&!chosen[match[i]])choose(i);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d%d",px+i,py+i);
	rep(i,1,n){qx[i]=px[i];qy[i]=py[i];}
	sort(qx+1,qx+n+1);
	sort(qy+1,qy+n+1);
	*qx=unique(qx+1,qx+n+1)-qx-1;
	*qy=unique(qy+1,qy+n+1)-qy-1;
	rep(i,1,n)
		exist[lower_bound(qx+1,qx+*qx+1,px[i])-qx][lower_bound(qy+1,qy+*qy+1,py[i])-qy]=1;
	rep(x,1,*qx)
	{
		int ny=0;
		rep(y,1,*qy)
		if(exist[x][y])
		{
			if(ny)
			{
				++n1;
				rep(i,ny+1,y-1)mark[x][i]=n1;	
			}
			ny=y; 
		}
	}
	rep(y,1,*qy)
	{
		int nx=0;
		rep(x,1,*qx)
		if(exist[x][y])
		{
			if(nx)
			{
				++n2;
				rep(i,nx+1,x-1)
				if(mark[i][y])add_e(mark[i][y],n2);
			}
			nx=x;
		}
	}
	
	work();
	
	vector<P>ans[2];
	n1=0;
	rep(x,1,*qx)
	{
		int ny=0,ly=0;
		rep(y,1,*qy)
		if(exist[x][y])
		{
			if(ny)
			{
				++n1;
				if(!chosen[n1])
				{
					ans[0].push_back({x,ly,x,ny});
					ly=y;
				}
			}
			else ly=y;
			ny=y;
		}
		if(ny)ans[0].push_back({x,ly,x,ny});
	}
	n2=0;
	rep(y,1,*qy)
	{
		int nx=0,lx=0;
		rep(x,1,*qx)
		if(exist[x][y])
		{
			if(nx)
			{
				++n2;
				if(!chosen[n1+n2])
				{
					ans[1].push_back({lx,y,nx,y});
					lx=x;
				}
			}
			else lx=x;
			nx=x;
		}
		if(nx)ans[1].push_back({lx,y,nx,y});
	}
	per(i,1,0)
	{
		printf("%d\n",int(ans[i].size()));
		for(auto p:ans[i])printf("%d %d %d %d\n",qx[p.x1],qy[p.y1],qx[p.x2],qy[p.y2]);
	}
}