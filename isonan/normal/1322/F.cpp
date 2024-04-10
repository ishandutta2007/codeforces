#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>

int n,m,head[1000001],nxt[1000010],b[1000010],k=1,K,l,r,ans,sum[1000001];
int fa[500001][21],dep[1000001],val[1000001],f[1000001],fin[1000001];
bool exi[1000001];
bool vis[1000001];
typedef std::pair<int,int> tuple;
std::vector<tuple>Lca[1000001];
std::vector<int>son[1000001];
tuple Ans[1000001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x,int f){
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs1(b[i],x);
}
int LCA(int x,int y,int go=-1){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=20;~i;--i)if(dep[fa[x][i]]>dep[y])x=fa[x][i];
	if(fa[x][0]==y){
		++val[x];
		son[y].push_back(x);
		return y;
	}
	if(dep[x]!=dep[y])x=fa[x][0];
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	++val[x],++val[y];
	if(~go)Lca[fa[x][0]].push_back(std::make_pair(x,y));
	return fa[x][0];
}
tuple &operator&=(tuple &a,tuple b){
	a.first=std::max(a.first,b.first);
	a.second=std::min(a.second,b.second);
	return a;
} 
struct bipart{
	int head[1000001],nxt[4000010],b[4000010],k,col[1000001];
	std::vector<int>v[2][1000001];
	void clear(int x){head[x]=0,col[x]=-1;}
	void init(){k=0;}
	void push(int s,int t){
//		printf("push %d %d\n",s,t);
		nxt[++k]=head[s];
		head[s]=k;
		b[k]=t;
		nxt[++k]=head[t];
		head[t]=k;
		b[k]=s;
	}
	bool ch(int x,int ins,int c=0){
//		printf("ch %d %d %d\n",x,c,col[x]);
		if(~col[x])return (col[x]==c);
		if(x<=n)v[c][ins].push_back(x);
		col[x]=c;
		for(int i=head[x];i;i=nxt[i]){
//			printf("%d %d\n",b[i],x);
			if(!ch(b[i],ins,c^1))return 0;
		}
		return 1;
	}
	tuple solve(int x){
		int l=0,r=K+1;
		for(int i=0;i<v[0][x].size();i++)r=std::min(r,K+1-f[v[0][x][i]]);
		for(int i=0;i<v[1][x].size();i++)l=std::max(l,f[v[1][x][i]]);
		return std::make_pair(l,r);
	}
	void getans(int x,int c=0){
		if(vis[x])return;
//		printf("getans %d %d %d\n",x,c,vis[x]);
		vis[x]=1;
		if(x<=n&&!c)fin[x]=1;
		for(int i=head[x];i;i=nxt[i]){
//			printf("%d %d\n",x,b[i]);
			getans(b[i],c^1);
		}
	}
}Check;
void Do(int x){
	if(x&&!~Check.col[x]&&!Check.ch(x,x)){puts("-1");exit(0);}
}
void dfs2(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs2(b[i],x),sum[x]+=sum[b[i]];
			exi[b[i]]=(sum[b[i]]>val[b[i]]);
		}
	for(int i=head[x];i;i=nxt[i])if(exi[b[i]]&&b[i]!=f)Check.push(x+n,b[i]);
	for(int i=0;i<Lca[x].size();++i)
		Check.push(Lca[x][i].first,Lca[x][i].second),exi[Lca[x][i].first]=exi[Lca[x][i].second]=1;
//	printf("%d\n",x);
	Do(x+n);
	for(int i=head[x];i;i=nxt[i])if(b[i]!=f)Do(b[i]);
}
bool judge(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!judge(b[i],x))return 0;
	tuple ans=std::make_pair(0,K+1),tem=Check.solve(x+n),now;
//	printf("judge %d %d\n",x,f);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&exi[b[i]]){
			Ans[b[i]]=now=Check.solve(b[i]);
			if(K+1-now.second<now.first)now=std::make_pair(K+1-now.second,K+1-now.first);
			ans&=now;
		}
	for(int i=0;i<son[x].size();++i)
		if(!exi[son[x][i]]){
//			printf("%d %d\n",x,son[x][i]);
			ans&=std::make_pair(0,K+1-::f[son[x][i]]);
		}
	(now=tem)&=ans;
	if(now.first<now.second-1)::f[x]=now.first+1;
	else{
		ans=std::make_pair(K+1-ans.second,K+1-ans.first);
		ans&=tem;
		if(ans.first>=ans.second-1)return 0;
		else ::f[x]=ans.first+1;
	}
	if(::ans==-2){
		Check.getans(x+n);
		for(int i=head[x];i;i=nxt[i])
			if(b[i]!=f&&exi[b[i]]&&!vis[b[i]])
				Check.getans(b[i],!(Ans[b[i]].first<(::f[x])&&Ans[b[i]].second>::f[x]));
		for(int i=0;i<son[x].size();i++)
			if(!exi[son[x][i]]){
				if((::f[son[x][i]])>=(::f[x]))fin[son[x][i]]=1;
			}
	}
//	printf("solve: %d %d %d\n",x,::f[x],K);
	return 1;
}
void set(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)fin[b[i]]^=fin[x],set(b[i],x);
	if(fin[x])::f[x]=K+1-::f[x];
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	scanf("%d%d",&n,&m);
	memset(Check.col,-1,sizeof Check.col);
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),push(u,v),push(v,u);
	dfs1(1,0);
	for(int i=1,a,b;i<=m;i++){
		a=read(),b=read();
		int lca=LCA(a,b,0);
		++sum[a];
		++sum[b];
		sum[lca]-=2;
	}
	dfs2(1,0);
	l=1,r=n,ans=-1;
	while(l<=r){
		memset(Check.col,0,sizeof Check.col);
		K=(l+r)>>1;
		if(judge(1,0))ans=K,r=K-1;
		else l=K+1;
	}
	K=ans;ans=-2;
	printf("%d\n",K);
	memset(Check.col,0,sizeof Check.col);
	judge(1,0);
//	for(int i=1;i<=n;i++)printf("%d ",fin[i]);putchar('\n');
	set(1,0);
	for(int i=1;i<=n;i++)write(f[i]),putchar(' ');putchar('\n');
}