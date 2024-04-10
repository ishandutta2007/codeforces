// Hydro submission #61bc74288d010cd404604421@1639740456877
#include<bits/stdc++.h>
using namespace std;
int tree[6000005];
int tot;
int ls[6000005],rs[6000005];
int rt[300005];
int fa[300005][25];
int dep[300005];
int ans[300005];
int n,m;
vector<pair<int,int> >vec[300005];
vector<int> edge[300005];
void change(int &k,int l,int r,int x,int y){
	if(!k)k=++tot;
	if(l==r){
		tree[k]+=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)change(ls[k],l,mid,x,y);
	else change(rs[k],mid+1,r,x,y);
}
int ask(int k,int l,int r,int x){
	if(l==r)return tree[k];
	int mid=l+r>>1;
	if(x<=mid)return ask(ls[k],l,mid,x);
	else return ask(rs[k],mid+1,r,x);
}
int merge(int x,int y,int l,int r){
	if(!x||!y)return x+y;
	if(l==r){
		tree[x]+=tree[y];
		return x;
	}
	int mid=l+r>>1;
	ls[x]=merge(ls[x],ls[y],l,mid);
	rs[x]=merge(rs[x],rs[y],mid+1,r);
	tree[x]=tree[ls[x]]+tree[rs[x]];
	return x;
}
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	rt[x]=++tot;
	for(auto y:edge[x]){
		dfs(y);
		rt[x]=merge(rt[x],rt[y],1,n);
	}
	change(rt[x],1,n,dep[x],1);
	for(auto query:vec[x])
		ans[query.second]=ask(rt[x],1,n,dep[x]+query.first)-1;
}
int getk(int x,int k){
	for(int i=0;i<=22;i++)if(k&(1<<i))x=fa[x][i];
	return x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&fa[i][0]);
		edge[fa[i][0]].push_back(i);
	}
	for(int j=1;j<=22;j++)for(int i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x,k;
		scanf("%d%d",&x,&k);
		vec[getk(x,k)].push_back(make_pair(k,i));
	}
	for(int i=1;i<=n;i++)if(!fa[i][0])dfs(i);
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}