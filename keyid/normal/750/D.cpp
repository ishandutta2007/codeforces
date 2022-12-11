#include <bits/stdc++.h>
using namespace std;

const int dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1};

struct state
{
	int x,y,d;
};

bool vis[400][400][8],vis2[400][400];

#define vis(i,j,k) vis[i+200][j+200][k]
#define vis2(i,j) vis2[i+200][j+200]

queue <state> q,q2;

int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	for (int i=0;i<t;i++) vis2(-i,0)=true;
	q.push((state){-(t-1),0,0});
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&t);
		memset(vis,0,sizeof(vis));
		while (!q.empty())
		{
			state u=q.front();q.pop();
			int d=(u.d+1)%8,tx=u.x,ty=u.y;
			for (int i=1;i<=t;i++)
			{
				tx+=dx[d];
				ty+=dy[d];
				vis2(tx,ty)=true;
			}
			if (!vis(tx,ty,d))
			{
				vis(tx,ty,d)=true;
				q2.push((state){tx,ty,d});
			}
			d=(u.d+7)%8;
			tx=u.x;ty=u.y;
			for (int i=1;i<=t;i++)
			{
				tx+=dx[d];
				ty+=dy[d];
				vis2(tx,ty)=true;
			}
			if (!vis(tx,ty,d))
			{
				vis(tx,ty,d)=true;
				q2.push((state){tx,ty,d});
			}
		}
		swap(q,q2);
	}
	int ans=0;
	for (int i=-180;i<=180;i++)
		for (int j=-180;j<=180;j++)
			if (vis2(i,j))
				ans++;
	printf("%d",ans);
	return 0;
}