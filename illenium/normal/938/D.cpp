#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

struct point  
{
	int id;
	long long price;	
};
struct road // 
{
	int y,nt;
	long long d;
};

bool operator <(point a,point b) // 
{
	return a.price>b.price;
}

const int maxn=2e5+7;
int head[maxn];
bool vis[maxn];
road f[maxn*2]; // 
long long dis[maxn];  //longlong 
int tot=0;

void add(int tx,int ty,long long td) // 
{
	tot++; f[tot].nt=head[tx]; head[tx]=tot; f[tot].y=ty; f[tot].d=td;
}

int main()
{
	priority_queue<point> q;
	int n,m,i,tx,ty;
	long long td;
	point t,tmp;
	memset(head,-1,sizeof(head));
	memset(vis,false,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%lld",&tx,&ty,&td);
		add(tx,ty,td);
		add(ty,tx,td);
	} 
	for(i=1;i<=n;i++) 
	{
		scanf("%lld",&dis[i]); //dis 
		t.id=i; t.price=dis[i];
		q.push(t);
	}
	while(!q.empty())
	{
		tmp=q.top();
		if(vis[tmp.id])
		{
			q.pop(); continue; //dij, 
		}
		vis[tmp.id]=true;
		i=head[tmp.id];
		while(i!=-1)
		{
			if(dis[f[i].y]>dis[tmp.id]+f[i].d*2) 
			{
			   dis[f[i].y]=dis[tmp.id]+f[i].d*2; //jjj 
			   t.id=f[i].y; t.price=dis[f[i].y];
			   q.push(t);
			}
			i=f[i].nt;
		}
		q.pop();
	}
	for(i=1;i<n;i++) printf("%lld ",dis[i]);
	printf("%lld\n",dis[n]);
	return 0;
}