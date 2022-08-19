#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

int head[100001],nxt[200001],b[200001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int dfn[100001],mx[100001],ord[100001],now,fa[100001],top[100001],size[100001],son[100001],dep[100001];
void dfs1(int x,int f){
	fa[x]=f;
	size[x]=1;
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			size[x]+=size[b[i]];
			if(size[b[i]]>size[son[x]])son[x]=b[i];
		}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++now;
	ord[now]=x;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=son[x]&&b[i]!=fa[x])
			dfs2(b[i],b[i]);
	mx[x]=now;
}
int n,m,q;
std::vector<int>vec[100001];
std::pair<long long,int>mn[1000001];
long long Add[1000001];
void build(int root,int l,int r){
	if(l==r){
		if(vec[ord[l]].empty())mn[root]=std::make_pair(1e18,0);
		else mn[root]=std::make_pair(vec[ord[l]].back(),ord[l]);
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	mn[root]=std::min(mn[root<<1],mn[root<<1|1]);
}
void update(int root,int l,int r,int el,int er,long long x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		Add[root]+=x;
		mn[root].first+=x;
		return;
	}
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	mn[root]=std::min(mn[root<<1],mn[root<<1|1]);
	mn[root].first+=Add[root];
}
void renew(int root,int l,int r,int e){
	if(l==r){
		if(vec[ord[l]].empty())mn[root]=std::make_pair(1e18,0);
		else mn[root]=std::make_pair(vec[ord[l]].back()+Add[root],ord[l]);
		return;
	}
	if((l+r)>>1>=e)renew(root<<1,l,(l+r)>>1,e);
	else renew(root<<1|1,((l+r)>>1)+1,r,e);
	mn[root]=std::min(mn[root<<1],mn[root<<1|1]);
	mn[root].first+=Add[root];
}
std::pair<long long,int>query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return std::make_pair(1e18,0);
	if(el<=l&&er>=r)return mn[root];
	std::pair<long long,int>ans=std::min(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
	ans.first+=Add[root];
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1,tem;i<=m;++i){
		scanf("%d",&tem);
		vec[tem].push_back(i);
	}
	// puts("dfn:");
	// for(int i=1;i<=n;++i)printf("%d ",dfn[i]);putchar('\n');
	for(int i=1;i<=n;++i)std::reverse(vec[i].begin(),vec[i].end());
	build(1,1,n);
	for(int i=1,opt,v,u,k;i<=q;++i){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&v,&u,&k);
			int stk[21][2],Top=0;
			std::pair<long long,int>tem[21];
			while(top[u]!=top[v]){
				if(dep[top[u]]<dep[top[v]])std::swap(u,v);
				++Top;
				stk[Top][0]=dfn[top[u]];
				stk[Top][1]=dfn[u];
				u=fa[top[u]];
			}
			if(dfn[u]>dfn[v])std::swap(u,v);
			++Top;
			stk[Top][0]=dfn[u];
			stk[Top][1]=dfn[v];
			for(int l=1;l<=Top;++l){
				// printf("%d %d\n",stk[l][0],stk[l][1]);
				tem[l]=query(1,1,n,stk[l][0],stk[l][1]);
			}
			std::vector<int>out;
			for(int j=1;j<=k;++j){
				std::pair<long long,int>ans=std::make_pair(1e18,0);
				int p=0;
				for(int l=1;l<=Top;++l)
					if(ans>tem[l])ans=tem[l],p=l;
				if(!ans.second)break;
				out.push_back(vec[ans.second].back());
				vec[ans.second].pop_back();
				renew(1,1,n,dfn[ans.second]);
				tem[p]=query(1,1,n,stk[p][0],stk[p][1]);
				// if(tem[p].second)printf("%lld %d %d\n",tem[p].first,tem[p].second,vec[tem[p].second].back());
			}
			// puts("***");
			printf("%d ",out.size());
			for(int i=0;i<out.size();++i)printf("%d ",out[i]);putchar('\n');
		}
		else{
			scanf("%d%d",&v,&k);
			update(1,1,n,dfn[v],mx[v],k);
		}
	}
}