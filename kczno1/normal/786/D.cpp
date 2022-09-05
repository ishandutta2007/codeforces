#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=20000+5;
struct Edge
{
	int to;char c;Edge *next;
};
void add(Edge* &fir,int to,char c)
{
	Edge *now=new Edge{to,c,fir};
	fir=now;
}
Edge *lk[N],*lk_son[N];
int fa[N],deep[N],sz[N];char to_fa[N];
int n,m;
char s[N];int top;

void dfs(int x)
{
	sz[x]=1;
	for(Edge *e=lk[x];e;e=e->next)
	{
		int y=e->to;
		if(y==fa[x])continue;
		add(lk_son[x],y,e->c);
		fa[y]=x;to_fa[y]=e->c;
		deep[y]=deep[x]+1;
		dfs(y);
		sz[x]+=sz[y];
	}
}

void get_s(int x,int y)
{
	top=0;
	static char s2[N];int t2=0;
	while(x!=y)
	if(deep[x]>deep[y]){s[++top]=to_fa[x];x=fa[x];}
	else{s2[++t2]=to_fa[y];y=fa[y];}
	for(;t2;--t2)s[++top]=s2[t2];
}

int ans;
void dfs(int x,int len)
{
	for(Edge *e=lk_son[x];e;e=e->next)
	if(e->c<s[len])ans+=sz[e->to];
	else
	if(e->c==s[len]&&len<top)
	{
		++ans;
		dfs(e->to,len+1);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	cin>>n>>m;
	rep(i,1,n-1)
	{
		int x,y;char c[5];
		scanf("%d%d%s",&x,&y,c);
		add(lk[x],y,*c);
		add(lk[y],x,*c);
	}
	dfs(1);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		get_s(x,y);
		ans=0;
		int len=1;
		dfs(x,1);
		while((y=fa[x]))
		{
			if(to_fa[x]<s[len])
			{
				ans+=n-sz[x];
				break;
			}
			if(to_fa[x]>s[len])break;
			if(len==top)break;
			++ans;
			++len;
			for(Edge *e=lk_son[y];e;e=e->next)
			if(e->to!=x)
			{
				if(e->c<s[len])ans+=sz[e->to];
				else
				if(e->c==s[len]&&len<top)
				{
					++ans;
					dfs(e->to,len+1);
				}
			}
			x=y;
		}
		printf("%d\n",ans);
	}
}