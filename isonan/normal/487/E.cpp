#include <algorithm>
#include <assert.h>
#include <cstdio>
#include <vector>
#include <set>

int low[100001],dfn[100001],now,size[200001],son[200001],n,m,q,w[100001],stack[200010],Top,top[200001],fa[200001],dep[200001],ord[200001];
int head[100001],nxt[200001],b[200001],k,cnt;
std::vector<int>con[200001];
std::multiset<int>set[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void Push(int s,int t){con[s].push_back(t);}
void tarjan(int x){
	low[x]=dfn[x]=++now;
	stack[++Top]=x;
	for(int i=head[x];i;i=nxt[i]){
		if(!dfn[b[i]]){
			tarjan(b[i]);
			low[x]=std::min(low[x],low[b[i]]);
			if(low[b[i]]>=dfn[x]){
				++cnt;
				Push(x,cnt);
				while(stack[Top+1]!=b[i]){
					Push(cnt,stack[Top]);
					--Top;
				}
			}
		}
		else{
			low[x]=std::min(low[x],dfn[b[i]]);
		}
	}
}
void dfs1(int x,int f){
	size[x]=1;
	fa[x]=f;
	dep[x]=dep[f]+1;
	for(int i=0,to;i<con[x].size();i++){
		to=con[x][i];
		if(to!=f){
			dfs1(to,x);
			size[x]+=size[to];
			if(size[son[x]]<size[to])son[x]=to;
		}
	}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++now;
	ord[now]=x;
	if(son[x])dfs2(son[x],t);
	for(int i=0,to;i<con[x].size();i++){
		to=con[x][i];
		if(to!=fa[x]&&to!=son[x])
			dfs2(to,to);
	}
}
int se[2000001];
void build(int root,int l,int r){
	if(l==r){
		int tem=ord[l];
		if(tem<=n)se[root]=w[tem];
		else se[root]=*set[tem].begin();
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=std::min(se[root<<1],se[root<<1|1]);
}
void update(int root,int l,int r,int e,int x){
	if(l==r){
		se[root]=x;
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
	se[root]=std::min(se[root<<1],se[root<<1|1]);
}
int query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0x7f7f7f7f;
	if(el<=l&&er>=r)return se[root];
	return std::min(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
char get(){
	char ch=getchar();
	while(ch<'A'||ch>'Z')ch=getchar();
	return ch;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",w+i);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	cnt=n;
	tarjan(1);
	dfs1(1,0);
	now=0;
	dfs2(1,1);
	for(int i=2;i<=n;i++)set[fa[i]].insert(w[i]);
	build(1,1,cnt);
	for(int i=1,x,y;i<=q;i++){
		if(get()=='A'){
			scanf("%d%d",&x,&y);
			int ans=0x7f7f7f7f;
			while(top[x]!=top[y]){
				if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
				ans=std::min(ans,query(1,1,cnt,dfn[top[x]],dfn[x]));
				x=fa[top[x]];
			}
			if(dfn[x]>dfn[y])x^=y^=x^=y;
			ans=std::min(ans,query(1,1,cnt,dfn[x],dfn[y]));
			if(x>n)ans=std::min(ans,w[fa[x]]);
			printf("%d\n",ans);
		}
		else{
			scanf("%d%d",&x,&y);
			if(x>1){
				set[fa[x]].erase(set[fa[x]].find(w[x]));
				set[fa[x]].insert(y);
				update(1,1,cnt,dfn[fa[x]],*set[fa[x]].begin());
			}
			w[x]=y;
			update(1,1,cnt,dfn[x],y);
		}
	}
}