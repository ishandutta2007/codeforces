#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,a[300005],b[300005];
int d[300005][2],pre[300005][2];

int fa[300005];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

queue<pair<int,int> > q;

void upd(int x,int y,int dd,int p)
{
	if(d[x][y]<=dd) return;
	d[x][y]=dd;
	pre[x][y]=p;
	q.push(make_pair(x,y));
}

void print(int x,int y)
{
	if(x==n&&y==0) return;
	print(pre[x][y],y^1);
	if(y==1) printf("%d ",x); 
}

int main()
{
	int i;
	ios_base::sync_with_stdio(0);
	cin>>n;
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>b[i];
	
	rep(i,n) fa[i]=i;
	
	memset(d,0x3f,sizeof(d));
	d[n][0]=0;
	
	q.push(make_pair(n,0));
	
	while(!q.empty())
	{
		pair<int,int> t=q.front();
		q.pop();
		
		if(t.second==0)
		{
			for(i=find(t.first-1);i>=t.first-a[t.first];)
			{
				upd(i,1,d[t.first][t.second]+1,t.first);
				if(i==0) break;
				fa[i]=find(i-1);
				i=find(i);
			}
		}
		else
		{
			upd(t.first+b[t.first],0,d[t.first][t.second],t.first);
		}
	}
	
	if(d[0][1]==0x3f3f3f3f) puts("-1");
	else
	{
		printf("%d\n",d[0][1]);
		print(0,1);
	}
	
	return 0;
}