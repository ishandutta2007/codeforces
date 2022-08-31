#include <algorithm>
#include <cstdio>
#include <cmath>

int arr[1001][1001],block,pos[100001],dfn[100001],size[100001],son[100001],top[100001],now,add[1001];
int head[100001],nxt[100001],b[100001],k,n,fa[100001],t[100001],m,a[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		dfs1(b[i]);
		if(size[b[i]]>size[son[x]])son[x]=b[i];
		size[x]+=size[b[i]];
	}
}
void dfs2(int x,int t){
	dfn[x]=++now;
	top[x]=t;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=son[x])dfs2(b[i],b[i]);
}
void rebuild(int x){
	arr[x][0]=0;
	for(int i=(x-1)*block+1;pos[i]==x;i++)
		arr[x][++arr[x][0]]=a[i];
	std::sort(arr[x]+1,arr[x]+arr[x][0]+1);
}
void update(int l,int r,int delta){
	for(int i=pos[l]+1;i<pos[r];++i)add[i]+=delta;
	for(int i=l;pos[i]==pos[l]&&i<=r;++i)a[i]+=delta;
	rebuild(pos[l]);
	if(pos[l]!=pos[r]){
		for(int i=r;pos[i]==pos[r]&&i>=l;--i)a[i]+=delta;
		rebuild(pos[r]);
	}
}
int getans(){
	int ans=0;
	for(int i=1;i<=pos[n];i++){
		ans+=arr[i][0]-(std::upper_bound(arr[i]+1,arr[i]+arr[i][0]+1,-add[i])-arr[i])+1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)scanf("%d",fa+i),push(fa[i],i);
	block=sqrt(n);
	for(int i=1;i<=n;i++)scanf("%d",t+i),pos[i]=(i-1)/block+1;
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;i++){
		int tem=pos[dfn[i]];
		arr[tem][++arr[tem][0]]=a[dfn[i]]=-t[i];
	}
	for(int i=1;i<=pos[n];i++)std::sort(arr[i]+1,arr[i]+arr[i][0]+1);
	for(int i=1,tem;i<=m;i++){
		scanf("%d",&tem);
		if(tem==0){
			printf("%d ",getans());
			continue;
		}
		int sgn=tem>0?1:(tem=-tem,-1);
		update(dfn[tem],dfn[tem],-n*sgn);
		tem=fa[tem];
		while(tem){
			update(dfn[top[tem]],dfn[tem],sgn);
			tem=fa[top[tem]];
		}
		printf("%d ",getans());
	}
}