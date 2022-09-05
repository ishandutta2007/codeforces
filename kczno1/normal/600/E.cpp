#include<cstdio>

#define ll long long
#define N 100100
int n,i,x,y;
int col[N],t[N];
struct edge
{
	int to,next; 
}l[N<<1]; 
void add_e(int x,int y)
{
	static int e=0;
	l[++e]=(edge){y,t[x]};t[x]=e;
}

int f[N],sz[N],son[N],in[N],out[N],q[N];
void dfs(int x,int fr)
{
   static int tot=0;
   f[x]=fr;sz[x]=1;q[in[x]=++tot]=col[x];
   int &c=son[x];
   for (int i=t[x],y;i;i=l[i].next)
   if ((y=l[i].to)!=fr)
   {
   	  dfs(y,x);
   	  sz[x]+=sz[y];
   	  if (sz[y]>sz[c]) c=y;
   }
   out[x]=tot; 
}

ll ans[N],now;
int m,cnt[N];
void push(int c)
{
	++cnt[c];
	if (cnt[c]>m) { m=cnt[c];now=c; }
	else 
	if (cnt[c]==m) now+=c;
}
void get(int x)
{
	int c=son[x];
	if (!c)
	{
		m=cnt[ans[x]=now=col[x]]=1;
		return ; 
	}
	for (int i=t[x],y;i;i=l[i].next)
    if ((y=l[i].to)!=f[x]&&y!=c)
    {
    	get(y);
    	for (int k=in[y];k<=out[y];++k) cnt[q[k]]=0;
    	now=m=0;
    }
    get(c);
    int k;
    for (k=in[x];k<in[c];++k) push(q[k]);
    for (k=out[c]+1;k<=out[x];++k) push(q[k]);
    ans[x]=now;
}

int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d",col+i);
	for (i=1;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		add_e(x,y);add_e(y,x);
	}
    dfs(1,0);
	get(1);
    for (i=1;i<=n;++i) printf("%lld ",ans[i]);
}