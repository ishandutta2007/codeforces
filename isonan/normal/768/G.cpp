#include <set>
#include <cstdio>
#include <algorithm>

using std::min;
using std::max;

int head[100001],nxt[200001],b[200001],k,value[200001];
int son[100001],top[100001],fa[100001],now,n,size[100001],skdmx[100001],mn[100001];
int fin[100001];
std::multiset<int>ans,out,child[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x,int f){
	fa[x]=f;
	size[x]=1;
	mn[x]=n+1;
	skdmx[x]=-n;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			size[x]+=size[b[i]];
			if(size[son[x]]<size[b[i]])skdmx[x]=size[son[x]],son[x]=b[i];
			else skdmx[x]=max(skdmx[x],size[b[i]]);
			mn[x]=min(mn[x],size[b[i]]);
		}
	if(n-size[x])mn[x]=min(mn[x],n-size[x]);
}
void dfs2(int x,int t){
	top[x]=t;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=fa[x]&&b[i]!=son[x])
			dfs2(b[i],b[i]);
}
void add(int x,std::multiset<int> & set){
	set.insert(size[x]);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=fa[x])
			add(b[i],set);
}
void del(int x,std::multiset<int> & set){
	set.erase(set.find(size[x]));
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=fa[x])
			del(b[i],set);
}
void getans(int x){
	if(n-size[x]>size[son[x]]){
		int tem=(n-size[x]-mn[x])>>1,v1,v2;
		v1=max(*--out.upper_bound(tem),(*--ans.upper_bound(tem+size[x]))-size[x]);
		v2=min(*  out.lower_bound(tem),(*  ans.lower_bound(tem+size[x]))-size[x]);
		if(v1==n-size[x])v1=0;
		if(v2==n-size[x])v2=0;
		fin[x]=min(max(min(max(mn[x]+v1,n-size[x]-v1),max(mn[x]+v2,n-size[x]-v2)),size[son[x]]),n-size[x]);
	}
	if(son[x]){
		for(int i=head[x];i;i=nxt[i])
			if(b[i]!=fa[x]&&b[i]!=son[x])
				add(b[i],out);
		ans.insert(size[x]);
		getans(son[x]);
		ans.erase(ans.find(size[x]));
	}
	if(n-size[x]<=size[son[x]]){
		skdmx[x]=max(skdmx[x],n-size[x]);
		int tem=(size[son[x]]-mn[x])>>1,v1=*(--child[top[x]].upper_bound(tem)),v2=*child[top[x]].lower_bound(tem);
		if(v1==size[son[x]])v1=0;
		if(v2==size[son[x]])v2=0;
		fin[x]=min(max(min(max(mn[x]+v1,size[son[x]]-v1),max(mn[x]+v2,size[son[x]]-v2)),skdmx[x]),size[son[x]]);
	}
	ans.insert(size[x]);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=fa[x]&&b[i]!=son[x]){
			del(b[i],out);
			getans(b[i]);
		}
	ans.erase(ans.find(size[x]));
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=fa[x]){
			if(b[i]!=son[x])add(b[i],child[top[x]]);
		}
	out.insert(size[x]);
	child[top[x]].insert(size[x]);
}
int main(){
//	freopen("CF768G.in","r",stdin);
//	freopen("CF768G.out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		puts("0");
		return 0;
	}
	int root=0;
	for(int i=1,s,t;i<=n;i++){
		scanf("%d%d",&s,&t);
		if(!s){
			root=t;
			continue;
		}
		push(s,t);
		push(t,s);
	}
	for(int i=1;i<=n;i++)child[i].insert(-(n<<1)),child[i].insert((n<<1));
	out.insert(-(n<<1)),out.insert((n<<1));
	ans.insert(-(n<<1)),ans.insert((n<<1));
	dfs1(root,0);
	dfs2(root,root);
	getans(root);
	for(int i=1;i<=n;i++)printf("%d\n",fin[i]);
}