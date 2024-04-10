#include<bits/stdc++.h>
using namespace std;

const int N=1e2+5;
const int fx[4]={-1,1,0,0};
const int fy[4]={0,0,-1,1};
int n,m,i,j;
char type[N][N];int q[N*N],dis[N*N];
int nx,ny,tx,ty;
int dy[4];

const int rdy[4]={1,0,3,2};

void move(int x)
{
	const char ch[]="UDLR";
	printf("%c\n",ch[x]);
	fflush(stdout);
/*	tx=nx+fx[rdy[x]];ty=ny+fy[rdy[x]];
	if(type[tx][ty]==0)
	{tx=nx;ty=ny;} */
	scanf("%d%d",&tx,&ty);
}

int D(int i,int j)
{
	return (i-1)*m+j;
}

int main()
{
    for(i=0;i<4;++i)dy[i]=-1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i) scanf("%s",type[i]+1);
	
	for(i=1;i<=n;++i)
	{
	  for(j=1;j<=m;++j)
	  if(type[i][j]=='F')break;
	  if(type[i][j]=='F')break;
    }
    
	int head,tail,now;
	q[tail=1]=D(i,j);
	for(head=1;head<=tail;++head)
	{
		i=q[head];now=dis[i];
		nx=(i-1)/m+1;ny=(i-1)%m+1;
		for(i=0;i<4;++i)
		{
			tx=nx+fx[i];ty=ny+fy[i];
			if(type[tx][ty]!='.')continue;
			j=D(tx,ty);
			if(dis[j]) continue;
			dis[j]=now+1;q[++tail]=j;
		}
	}
	
	nx=1;ny=1;
	while(type[nx][ny]!='F')
	{
		for(i=0;i<4;++i)
		{
			tx=nx+fx[i];ty=ny+fy[i];
			if(type[tx][ty]!='.'&&type[tx][ty]!='F')continue;
			j=D(tx,ty);
			if(dis[j]>=dis[D(nx,ny)]) continue;
			break;
		}
		if(dy[i]==-1) 
		{
			move(i);
			if(tx==nx&&ty==ny) {dy[i]=i^1;dy[i^1]=i;}
			else {dy[i]=i;dy[i^1]=i^1;}
		}
		else move(dy[i]);
		nx=tx;ny=ty;
	}
}