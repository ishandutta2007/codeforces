#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=3e5+5;
int n;
vector<int>lk[N];
unordered_map<int,bool>co[N];
int g[N],fa[N];

void solve2(int x)
{
	puts("4");	
	printf("%d %d %d %d %d\n",1,fa[x],x,1,n);
	exit(0);
}
int q[N];
void bfs()
{
	rep(i,1,n)g[i]=N;
	g[1]=0;
	int tail=1;
	q[1]=1;
	rep(head,1,tail)
	{
		int x=q[head];
		for(auto y:lk[x])
		if(g[y]==N)
		{
			g[y]=g[x]+1;
			fa[y]=x;
			q[++tail]=y;
		}
	}
	if(g[n]!=N)
	{
		vector<int>ans;
		for(int i=n;i!=1;i=fa[i])ans.push_back(i);
		ans.push_back(1);
		reverse(ans.begin(),ans.end());
		if(ans.size()<=5)
		{
			printf("%d\n",ans.size()-1);
			for(auto x:ans)printf("%d ",x);
			puts("");
			exit(0);
		}
		else solve2(ans[2]);
	}
}

void check(int x)
{
	int tail=1;
	q[1]=x;g[x]=0;
	rep(head,1,tail)
	{
		int x=q[head];
		for(auto y:lk[x])
		if(g[y]==1)
		{
			g[y]=0;
			q[++tail]=y;
		}
	}
	rep(i,1,tail)
	{
		int x=q[i];
		rep(j,1,tail)
		if(j!=i)
		{
			int y=q[j];
			if(!co[x][y])
			{
				for(auto z:lk[y])
				if(z!=1&&co[x][z])
				{
					puts("5");
					printf("%d %d %d %d %d %d\n",1,y,z,x,y,n);
					exit(0);
				}
			}
		} 
	}
}

int main()
{

	int m;
	cin>>n>>m;
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lk[x].push_back(y);lk[y].push_back(x);
		co[x][y]=co[y][x]=1;
	}
	bfs();
	rep(i,1,n)
	if(g[i]==2)solve2(i);
	rep(i,1,n)
	if(g[i]==1)check(i);
	puts("-1");
}