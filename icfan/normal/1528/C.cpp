#include <vector>
#include <cstdio>
const int Maxn=300000;
int n;
int dfn[Maxn+5],sz[Maxn+5],dfn_tot;
std::vector<int> g_1[Maxn+5],g_2[Maxn+5];
void dfn_dfs(int u,int fa){
	dfn[u]=++dfn_tot;
	sz[u]=1;
	for(int i=0;i<(int)g_2[u].size();i++){
		int v=g_2[u][i];
		if(v==fa){
			continue;
		}
		dfn_dfs(v,u);
		sz[u]+=sz[v];
	}
}
namespace Segment_Tree{
	int col[Maxn<<2|5];
	void update_tag(int root,int a){
		col[root]=a;
	}
	void push_down(int root){
		if(col[root]!=-1){
			update_tag(root<<1,col[root]);
			update_tag(root<<1|1,col[root]);
			col[root]=-1;
		}
	}
	void update(int l,int r,int a,int root=1,int left=1,int right=n){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			update_tag(root,a);
			return;
		}
		push_down(root);
		int mid=(left+right)>>1;
		update(l,r,a,root<<1,left,mid);
		update(l,r,a,root<<1|1,mid+1,right);
	}
	int query(int x,int root=1,int left=1,int right=n){
		if(left==right){
			return col[root];
		}
		push_down(root);
		int mid=(left+right)>>1;
		if(x<=mid){
			return query(x,root<<1,left,mid);
		}
		else{
			return query(x,root<<1|1,mid+1,right);
		}
	}
}
namespace BIT{
	int f[Maxn+5];
	void add(int x,int a){
		for(int i=x;i<=n;i+=(i&(-i))){
			f[i]+=a;
		}
	}
	int query(int x){
		int ans=0;
		for(int i=x;i>0;i-=(i&(-i))){
			ans+=f[i];
		}
		return ans;
	}
	int query(int l,int r){
		return query(r)-query(l-1);
	}
}
void init(){
	for(int i=1;i<=n;i++){
		g_1[i].clear(),g_2[i].clear();
	}
	dfn_tot=0;
}
int work_dfs(int u,int fa,int tmp_ans){
	int last=0;
	bool add_flag=0;
	if(BIT::query(dfn[u],dfn[u]+sz[u]-1)==0){
		last=Segment_Tree::query(dfn[u]);
		if(last!=0){
			Segment_Tree::update(dfn[last],dfn[last]+sz[last]-1,0);
			BIT::add(dfn[last],-1);
		}
		else{
			tmp_ans++;
		}
		Segment_Tree::update(dfn[u],dfn[u]+sz[u]-1,u);
		BIT::add(dfn[u],1);
		add_flag=1;
	}
	int ans=tmp_ans;
	for(int i=0;i<(int)g_1[u].size();i++){
		int v=g_1[u][i];
		if(v==fa){
			continue;
		}
		ans=std::max(ans,work_dfs(v,u,tmp_ans));
	}
	if(add_flag){
		BIT::add(dfn[u],-1);
		Segment_Tree::update(dfn[u],dfn[u]+sz[u]-1,0);
		if(last!=0){
			Segment_Tree::update(dfn[last],dfn[last]+sz[last]-1,last);
			BIT::add(dfn[last],1);
		}
	}
	return ans;
}
void solve(){
	scanf("%d",&n);
	init();
	for(int i=2;i<=n;i++){
		int fa;
		scanf("%d",&fa);
		g_1[fa].push_back(i);
	}
	for(int i=2;i<=n;i++){
		int fa;
		scanf("%d",&fa);
		g_2[fa].push_back(i);
	}
	dfn_dfs(1,0);
	printf("%d\n",work_dfs(1,0,0));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}