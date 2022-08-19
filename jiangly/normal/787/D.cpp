#include<bits/stdc++.h>
using namespace std;
namespace legacy{
	typedef long long ll;
	const int N=1e5,Q=1e5,V=3*N-2;
	int n,q,s,tot_node;
	typedef struct segment_tree_node{
		int l,r,lchild,rchild;
	}node;
	ll dis[V];
	bool vis[V];
	vector<pair<int,int>>e[V];
	int root1,root2;
	node a[V];
	int new_node(int l,int r){
		return l==r?l:(a[tot_node]={l,r,-1,-1},tot_node++);
	}
	void build(int p){
		if(a[p].l==a[p].r){
			return;
		}
		int mid=(a[p].l+a[p].r)>>1;
		a[p].lchild=new_node(a[p].l,mid);
		a[p].rchild=new_node(mid+1,a[p].r);
		build(a[p].lchild);
		build(a[p].rchild);
	}
	void link(int u,int v,int w){
		e[u].push_back({v,w});
	}
	void link(int p,int u,int l,int r,int w,int type){
		if(a[p].l>=l&&a[p].r<=r){
			type==1?link(u,p,w):link(p,u,w);
		}else if(a[p].l>r||a[p].r<l){
			return;
		}else{
			link(a[p].lchild,u,l,r,w,type);
			link(a[p].rchild,u,l,r,w,type);
		}
	}
	void dijkstra(){
		for(int i=0;i<tot_node;++i){
			dis[i]=-1;
		}
		dis[s]=0;
		priority_queue<pair<ll,int>>h;
		h.push({0,s});
		while(!h.empty()){
			int u=h.top().second;
			h.pop();
			if(vis[u]){
				continue;
			}
			vis[u]=1;
			for(auto i:e[u]){
				int v=i.first,w=i.second;
				if(!vis[v]&&(dis[v]==-1||dis[v]>dis[u]+w)){
					dis[v]=dis[u]+w;
					h.push({-dis[v],v});
				}
			}
		}
	}
	void main(){
		scanf("%d%d%d",&n,&q,&s);
		--s;
		tot_node=n;
		for(int i=0;i<n;++i){
			a[i].l=a[i].r=i;
			a[i].lchild=-1;
			a[i].rchild=-1;
		}
		root1=new_node(0,n-1);
		build(root1);
		root2=new_node(0,n-1);
		build(root2);
		for(int i=n;i<2*n-1;++i){
			link(a[i].lchild,i,0);
			link(a[i].rchild,i,0);
		}
		for(int i=2*n-1;i<3*n-2;++i){
			link(i,a[i].lchild,0);
			link(i,a[i].rchild,0);
		}
		for(int i=0;i<q;++i){
			int t,u,v,l,r,w;
			scanf("%d",&t);
			switch(t){
				case 1:
					scanf("%d%d%d",&u,&v,&w);
					--u;
					--v;
					link(u,v,w);
					break;
				case 2:
					scanf("%d%d%d%d",&u,&l,&r,&w);
					--u;
					--l;
					--r;
					link(root2,u,l,r,w,1);
					break;
				case 3:
					scanf("%d%d%d%d",&u,&l,&r,&w);
					--u;
					--l;
					--r;
					link(root1,u,l,r,w,2);
					break;
			}
		}
		dijkstra();
		for(int i=0;i<n;++i){
			printf("%I64d ",dis[i]);
		}
	}
}
int main(){
	legacy::main();
	return 0;
}