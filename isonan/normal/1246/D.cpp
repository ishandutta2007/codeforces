#include <cstdio>
#include <vector>

std::vector<int>ans;
int head[100001],nxt[200001],b[200001],k,n,f[200001],dfn[200001],ord[200001],now,p[200001],mxdep[200001],dep[200001],son[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x){
	mxdep[x]=dep[x]=dep[f[x]]+1;
	for(int i=head[x];i;i=nxt[i]){
		dfs(b[i]);
		if(mxdep[x]<mxdep[b[i]])mxdep[x]=mxdep[b[i]],son[x]=b[i];
	}
}
void dfs2(int x){
	dfn[x]=now;
	ord[now]=x;
	++now;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=son[x])dfs2(b[i]);
	if(son[x])dfs2(son[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d",f+i);
		push(f[i],i);
	}
	dfs(0);
	dfs2(0); 
	for(int i=1;i<n;i++)p[ord[i]]=ord[i-1];
	for(int i=1;i<n;i++){
		while(p[ord[i]]!=f[ord[i]])ans.push_back(ord[i]),p[ord[i]]=p[p[ord[i]]];
	}
	for(int i=0;i<n;i++)printf("%d ",ord[i]);putchar('\n'); 
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
}