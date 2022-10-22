#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct Edge{
	int to,nxt;
}e[2*maxn];
int cnt;
int head[maxn];
int n;
struct node{
	int id,data;
	bool operator <(node i)const{
		return data<i.data;
	}
}a[maxn];
int b[maxn];
int sum[maxn],lst[maxn];
set<int>s[maxn];
set<int>::iterator it;
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
int dfsnum;
int dfn[maxn],num[maxn],siz[maxn];
void dfs(int x,int fa){
	dfn[x]=++dfsnum;
	num[dfsnum]=x;
	siz[x]=1;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs(tmp,x);
		siz[x]+=siz[tmp];
	}
	return ;
}
int g[maxn],f[maxn];
int query(int l,int r,int c){
	int ans=0;
	it=s[c].upper_bound(r);it--;
	ans+=sum[*it];
	it=s[c].lower_bound(l);it--;
	ans-=sum[*it];
	return ans;
}
void dfs1(int x,int fa){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs1(tmp,x);
		g[x]+=g[tmp];
	}
	g[x]+=query(dfn[x]+1,dfn[x]+siz[x]-1,b[x]);
	return ;
}
int ans=0;
void dfs2(int x,int fa){
	if(f[x]==0)ans++;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		int l=dfn[tmp],r=dfn[tmp]+siz[tmp]-1;
		f[tmp]=f[x]+query(1,l-1,b[tmp])+query(r+1,n,b[tmp])-query(l,r,b[x]);
		dfs2(tmp,x);
	}
	return ;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i].id=i,a[i].data=read();
	sort(a+1,a+n+1);
	int w=0;
	for(int i=1;i<=n;i++){
		if(a[i].data>a[i-1].data)s[++w].insert(0);
		b[a[i].id]=w;
	}
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		sum[i]=sum[lst[b[num[i]]]]+1;
		lst[b[num[i]]]=i;
		s[b[num[i]]].insert(i);
	}
	dfs1(1,0);f[1]=g[1];
	dfs2(1,0);
	printf("%d\n",ans);
	return 0;
}