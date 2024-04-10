#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=11006;
int minn(int a,int b){return a<b?a:b;}
void swap(int &x,int &y){x^=y;y^=x;x^=y;}
int read()
{
    int ans=0;char q=getchar();
    while(q<'0'||q>'9')q=getchar();
    while(q>='0'&&q<='9'){ans=ans*10+q-'0';q=getchar();}
    return ans;
}
struct son
{
    int v,next,u,w,cost;
};
son a1[500006];
int first[500006],e;
void addbian(int u,int v,int w,int cost)
{
    a1[e].v=v;
    a1[e].u=u;
    a1[e].w=w;
    a1[e].cost=cost;
    a1[e].next=first[u];
    first[u]=e++;
}
void Link(int u,int v,int w,int cost)
{
    addbian(u,v,w,cost);
    addbian(v,u,0,-cost);
}

int n,cnt;
int S,T;
int ha[106][106],a[106][106];
int x[10006],y[10006];

int flag[N],flow[N],d[N],pre[N];
queue<int> q;
bool spfa(int &fw,int &ct)
{
    mem(pre,0);mem(flag,0);mem(flow,0x7f);mem(d,0x7f/3);int qqq=d[0];
    d[S]=0;q.push(S);flag[S]=1;
    while(!q.empty())
    {
        int now=q.front();q.pop();flag[now]=0;
        for(int i=first[now];i!=-1;i=a1[i].next)
        {
            int temp=a1[i].v;
            if(!a1[i].w||d[temp]<=d[now]+a1[i].cost)continue;
            d[temp]=d[now]+a1[i].cost;
            flow[temp]=minn(flow[now],a1[i].w);
            pre[temp]=i;
            if(!flag[temp])
            {
                q.push(temp);
                flag[temp]=1;
            }
        }
    }
    if(d[T]==qqq)return 0;
    fw+=flow[T];ct+=d[T]*flow[T];
    int now=T;
    while(now!=S)
    {
        a1[pre[now]].w-=flow[T];
        a1[pre[now]^1].w+=flow[T];
        now=a1[pre[now]].u;
    }
    return 1;
}

int MCMF()
{
    int fw=0,ct=0;
    while(spfa(fw,ct));
    return ct;
}

void bianli()
{
    int q1,q2;
    for(int i=0;i<e;++i)
      if(!a1[i].w&&a1[i].u<=cnt&&a1[i].v!=T&&a[x[a1[i].u]][y[a1[i].u]]==2)
      {
            q1=x[a1[i].u];q2=y[a1[i].u];
            if(a1[i].v-cnt==q2)swap(q1,q2);
            a[q1][q2]=1;a[q2][q1]=0;
        }
            
    
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
          printf("%d",a[i][j]);
        printf("\n");
    }
}

int main()
{
	mem(first,-1);
	int i,j,m;
	n=read();
	m=read();
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(i!=j)a[i][j]=2;
	while(m--)
	{
		i=read();
		j=read();
		a[i][j]=1;
		a[j][i]=0;
	}
	cnt=n*n;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)
	{
		ha[i][j]=(i-1)*n+j;
		x[ha[i][j]]=i;
		y[ha[i][j]]=j;
	}
	S=0;
	T=n*n+n+1;
	for(i=1;i<=n;i++)for(j=1;j<i;j++)Link(S,ha[i][j],1,0);
	for(i=1;i<=n;i++)for(j=1;j<i;j++)
	{
		if(a[i][j]==1||a[i][j]==2)Link(ha[i][j],cnt+i,1,0);
		if(a[i][j]==0||a[i][j]==2)Link(ha[i][j],cnt+j,1,0);
	}
	for(i=1;i<=n;i++)for(j=0;j<n;j++)Link(cnt+i,T,1,j);
	MCMF();
	bianli();
	return 0;
}