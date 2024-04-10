#include<bits/stdc++.h>
using namespace std;
namespace water_tree{
	const int N=5e5,Q=5e5,P=2*N-1;
	int tot_node,root;
	int lchild[P],rchild[P],t_l[P],t_r[P],sum[P],same[P];
	int n,q;
	int parent[N],preferred_son[N],dep[N],pos[N],top[N],size[N];
	vector<int>e[N];
	void dfs1(int u){
		size[u]=1;
		preferred_son[u]=-1;
		for(auto v:e[u]){
			if(v==parent[u]){
				continue;
			}
			parent[v]=u;
			dep[v]=dep[u]+1;
			dfs1(v);
			size[u]+=size[v];
			if(preferred_son[u]==-1||size[v]>size[preferred_son[u]]){
				preferred_son[u]=v;
			}
		}
	}
	void dfs2(int u){
		static int cnt;
		pos[u]=cnt++;
		if(preferred_son[u]==-1){
			return;
		}
		top[preferred_son[u]]=top[u];
		dfs2(preferred_son[u]);
		for(auto v:e[u]){
			if(v==parent[u]||v==preferred_son[u]){
				continue;
			}
			top[v]=v;
			dfs2(v);
		}
	}
	int new_node(int l,int r){
		t_l[tot_node]=l;
		t_r[tot_node]=r;
		lchild[tot_node]=-1;
		rchild[tot_node]=-1;
		sum[tot_node]=0;
		same[tot_node]=-1;
		return tot_node++;
	}
	void build(int p){
		if(t_l[p]==t_r[p]){
			return;
		}
		int mid=(t_l[p]+t_r[p])>>1;
		lchild[p]=new_node(t_l[p],mid);
		rchild[p]=new_node(mid+1,t_r[p]);
		build(lchild[p]);
		build(rchild[p]);
	}
	void build(){
		root=new_node(0,n-1);
		build(root);
	}
	void push_down(int p){
		if(same[p]==-1){
			return;
		}
		same[lchild[p]]=same[p];
		sum[lchild[p]]=same[p]*(t_r[lchild[p]]-t_l[p]+1);
		same[rchild[p]]=same[p];
		sum[rchild[p]]=same[p]*(t_r[p]-t_l[rchild[p]]+1);
		same[p]=-1;
	}
	void update(int p){
		sum[p]=sum[lchild[p]]+sum[rchild[p]];
	}
	int query_sum(int p,int l,int r){
		if(t_l[p]>=l&&t_r[p]<=r){
			return sum[p];
		}else if(t_r[p]<l||t_l[p]>r){
			return 0;
		}else{
			push_down(p);
			return query_sum(lchild[p],l,r)+query_sum(rchild[p],l,r);
		}
	}
	void make_same(int p,int l,int r,int x){
		if(t_l[p]>=l&&t_r[p]<=r){
			same[p]=x;
			sum[p]=x*(t_r[p]-t_l[p]+1);
		}else if(t_r[p]<l||t_l[p]>r){
			return;
		}else{
			push_down(p);
			make_same(lchild[p],l,r,x);
			make_same(rchild[p],l,r,x);
			update(p);
		}
	}
	void path_make_same(int x,int y){
		while(~x){
			make_same(root,pos[top[x]],pos[x],y);
			x=parent[top[x]];
		}
	}
	void subtree_make_same(int x,int y){
		make_same(root,pos[x],pos[x]+size[x]-1,y);
	}
	void main(){
		scanf("%d",&n);
		for(int i=1;i<n;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			--u;
			--v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		parent[0]=-1;
		dfs1(0);
		dfs2(0);
		build();
		scanf("%d",&q);
		for(int i=0;i<q;++i){
			int opt,x;
			scanf("%d%d",&opt,&x);
			--x;
			switch(opt){
				case 1:
					subtree_make_same(x,1);
					break;
				case 2:
					path_make_same(x,0);
					break;
				case 3:
					printf("%d\n",query_sum(root,pos[x],pos[x]));
					break;
			}
		}
	}
}
int main(){
	water_tree::main();
	return 0;
}