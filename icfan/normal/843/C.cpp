#include <vector>
#include <cstdio>
const int Maxn=200000;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int sz[Maxn+5];
int fa[Maxn+5];
void sz_dfs(int u){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		sz_dfs(v);
		sz[u]+=sz[v];
	}
}
int root,mx_val;
void get_weight(int u,int fa){
	int cur_val=n-sz[u];
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		get_weight(v,u);
		cur_val=std::max(cur_val,sz[v]);
	}
	if(cur_val<mx_val){
		root=u;
		mx_val=cur_val;
	}
}
int lis[Maxn+5],len;
void get_lis(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		get_lis(v);
	}
	lis[++len]=u;
}
struct Operation{
	int u,v,w;
	Operation(int _u=0,int _v=0,int _w=0){
		u=_u,v=_v,w=_w;
	}
};
std::vector<Operation> op;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	sz_dfs(1);
	mx_val=n+1;
	get_weight(1,0);
	if(n-sz[root]==sz[root]){
		int t_root=root;
		root=fa[root];
		for(int i=head[root];i;i=nxt[i]){
			int u=arrive[i];
			if(u==t_root){
				continue;
			}
			len=0;
			fa[u]=root;
			get_lis(u);
			int lst=u;
			for(int j=1;j<=len;j++){
				if(lis[j]==u){
					continue;
				}
				op.push_back(Operation(root,lst,lis[j]));
				lst=lis[j];
				op.push_back(Operation(lis[j],fa[lis[j]],u));
			}
			op.push_back(Operation(root,lst,u));
		}
		root=t_root;
	}
	else{
		fa[root]=0;
	}
	for(int i=head[root];i;i=nxt[i]){
		int u=arrive[i];
		if(u==fa[root]){
			continue;
		}
		len=0;
		fa[u]=root;
		get_lis(u);
		int lst=u;
		for(int j=1;j<=len;j++){
			if(lis[j]==u){
				continue;
			}
			op.push_back(Operation(root,lst,lis[j]));
			lst=lis[j];
			op.push_back(Operation(lis[j],fa[lis[j]],u));
		}
		op.push_back(Operation(root,lst,u));
	}
	printf("%d\n",(int)op.size());
	for(Operation it:op){
		printf("%d %d %d\n",it.u,it.v,it.w);
	}
	return 0;
}