#include<bits/stdc++.h>
const int MAXN=100000,MAXM=1000000,inf=0x7fffffff;
int n,r,m;
int dfs_clock,max_dep,tot_node,last_ans;
int dfn[MAXN+5],sz[MAXN+5],dep[MAXN+5],val[MAXN+5],tp[MAXN+5];
std::vector<int>e[MAXN+5];
int rt[MAXN+5],lc[MAXN*20],rc[MAXN*20],Min[MAXN*20];
void dfs(int u,int fa){
	dfn[u]=++dfs_clock;
	sz[u]=1;
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if(v==fa){
			continue;
		}
		dep[v]=dep[u]+1;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
bool cmp(int a,int b){
	return dep[a]<dep[b];
}
int insert(int p,int l,int r,int x,int y){
	int q=++tot_node;
	lc[q]=lc[p];
	rc[q]=rc[p];
	if(l==r){
		Min[q]=y;
		return q;
	}else{
		int mid=(l+r)>>1;
		if(x<=mid){
			lc[q]=insert(lc[q],l,mid,x,y);
		}else{
			rc[q]=insert(rc[q],mid+1,r,x,y);
		}
		Min[q]=std::min(Min[lc[q]],Min[rc[q]]);
		return q;
	}
}
int query_min(int p,int tl,int tr,int l,int r){
	if(!p||(tl>=l&&tr<=r)){
		return Min[p];
	}else if(tl>r||tr<l){
		return inf;
	}else{
		int mid=(tl+tr)>>1;
		return std::min(query_min(lc[p],tl,mid,l,r),query_min(rc[p],mid+1,tr,l,r));
	}
}
int main(){
	Min[0]=inf;
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;++i){
		scanf("%d",&val[i]);
	}
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dep[r]=1;
	dfs(r,0);
	for(int i=1;i<=n;++i){
		tp[i]=i;
	}
	std::sort(tp+1,tp+n+1,cmp);
	for(int i=1;i<=n;++i){
		int u=tp[i];
		if(max_dep<dep[u]){
			rt[dep[u]]=rt[max_dep++];
		}
		rt[dep[u]]=insert(rt[dep[u]],1,n,dfn[u],val[u]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int x,k;
		scanf("%d%d",&x,&k);
		x=(x+last_ans)%n+1;
		k=(k+last_ans)%n;
		printf("%d\n",last_ans=query_min(rt[std::min(dep[x]+k,max_dep)],1,n,dfn[x],dfn[x]+sz[x]-1));
	}
	return 0;
}